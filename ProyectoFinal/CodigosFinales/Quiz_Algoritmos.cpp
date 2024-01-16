/**
 * @file Quiz_Algoritmos.cpp
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Contiene la informacion del Quiz de Algortimos de Ordenamiento que se despliega desde el Menu Principal
 * @brief Se crea el Objeto de tipo Quiz_Algoritmos para dar forma al Quiz de Algortimos de Ordenamiento
 * @version 1.0
 * @date 2023-11-26
 */
#include "Quiz_Algoritmos.h"          // Incluye la declaración de la clase
#include "ui_Quiz_Algoritmos.h"       // Incluye la interfaz de usuario
#include <QMessageBox>          // Incluye la clase para mostrar mensajes de información

// Creando Objeto de tipo Quiz_Algoritmos
Quiz_Algoritmos::Quiz_Algoritmos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Preguntas_Algoritmos),
    preguntaActual(0),
    respuestasCorrectas(0)
{
    ui->setupUi(this);

    // Agrega preguntas con sus opciones y respuestas correctas
    texto.append({ "Con respecto a la complejidad de un algoritmo de ordenamiento, usando la notación Big-O, ¿que representa la 'n'?",
                      {"Número de cálculos realizados por el algoritmo de ordenamiento.",
                       "Cantidad de líneas del código.",
                       "Tamaño del conjunto de datos que se desea ordenar.",
                       "Numero de variables del código."},
                      2 });

    texto.append({ "¿Cuál es el principio fundamental de Selection Sort?",
                      {"Comparar e intercambiar pares de elementos adyacentes.",
                       "Seleccionar el elemento mínimo y "
                       "lo coloca en la posición correcta.",
                       "Dividir el conjunto de elementos en subconjuntos y ordenarlos por separado.",
                       "Usa como pivote un elemento y partir de él ordena."},
                      1 });

    texto.append({ "¿Cuál de los siguientes algoritmos de ordenamiento tiene una complejidad de espacio de O(n*log(n))?",
                      {"Burbuja (Bubble Sort)",
                       "Fusión (Merge Sort)",
                       "Rápido (Quick Sort)",
                       "Insercción (Insertion Sort)"},
                      2 });

    texto.append({ "¿Los algoritmos de ordenamiento son esenciales para: ?",
                      {"Resolver operaciones matemáticas complejas en un código. ",
                       "Los algoritmos de ordenamiento son únicamente necesarios para organizar visualmente los datos.",
                       "El ordenamiento de datos solo es crucial cuando se trabaja con conjuntos de datos de un tamaño masivo.",
                       "Optimizar operaciones, ya que nos ayudan a ordenar y mejorar la eficiencia las de estructuras de datos."},
                      3 });

    texto.append({ "¿Cuál de esto es el funcionamiento básico de un algoritmo de ordenamiento Fusión (Merge Sort)?",
                      {"Divide la lista en mitades, ordena cada mitad y luego combina las mitades ordenadas. ",
                       "Encuentra el elemento mínimo de la lista y lo intercambia con el primer elemento.",
                       "Construye una secuencia ordenada uno a uno, insertando elementos en su posición correcta.",
                       "Selecciona un elemento como " "pivote"" y particiona la lista alrededor del pivote."},
                      0 });


    // Muestra la primera pregunta
    mostrarPregunta(texto[preguntaActual]);

    // Conecta los botones a las direcciones correspondientes
    connect(ui->BotonSiguiente_2, &QPushButton::clicked, this, &Quiz_Algoritmos::mostrarSiguientePregunta);
    connect(ui->BotonAnterior_2, &QPushButton::clicked, this, &Quiz_Algoritmos::mostrarPreguntaAnterior);
    connect(ui->btnMostrarRespuestas_2, &QPushButton::clicked, this, &Quiz_Algoritmos::mostrarRespuestas);
    connect(ui->botonVolver_2, &QPushButton::clicked, this, &Quiz_Algoritmos::volver_a_Menu);
}

// Permite introducir el texto
void Quiz_Algoritmos::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}

// Despliega el contenido de la pregunta
void Quiz_Algoritmos::mostrarPregunta(const Quiz_de_Algoritmos &question) {
    // Muestra la pregunta y opciones en la interfaz gráfica
    ui->questionLabel->setText(question.Pregunta);
    ui->option1RadioButton->setText(question.Respuestas[0]);
    ui->option2RadioButton->setText(question.Respuestas[1]);
    ui->option3RadioButton->setText(question.Respuestas[2]);
    ui->option4RadioButton->setText(question.Respuestas[3]);
}

// Cuando se acaba el programa la nota y las preguntas se reinician
void Quiz_Algoritmos::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(texto[preguntaActual]);
}

// Realiza la accion del boton "siguiente"
void Quiz_Algoritmos::mostrarSiguientePregunta() {
    // Determina la respuesta seleccionada por el usuario
    int respuestaSeleccionada = -1;
    if (ui->option1RadioButton->isChecked()) respuestaSeleccionada = 0;
    else if (ui->option2RadioButton->isChecked()) respuestaSeleccionada = 1;
    else if (ui->option3RadioButton->isChecked()) respuestaSeleccionada = 2;
    else if (ui->option4RadioButton->isChecked()) respuestaSeleccionada = 3;

    // Verifica la respuesta de la pregunta actual antes de incrementar preguntaActual
    if (preguntaActual < texto.size() && respuestaSeleccionada == texto[preguntaActual].Respuesta_Correcta) {
        respuestasCorrectas++;
    }

    // Incrementa preguntaActual solo si aún hay preguntas por mostrar
    if (preguntaActual + 1 < texto.size()) {
        preguntaActual++;
        mostrarPregunta(texto[preguntaActual]);
    } else {
        // Muestra la puntuación y emite la señal para regresar a MainWindow
        ui->nota->setText("Tu puntuación es: " + QString::number(respuestasCorrectas) + "/" + QString::number(texto.size()));
            emit quizTerminado();
    }

    // Habilita el botón para mostrar respuestas después de responder la última pregunta
    if (preguntaActual + 1 >= texto.size()) {
        ui->btnMostrarRespuestas_2->setEnabled(true);
    }
}

// Realiza la accion del boton "anterior"
void Quiz_Algoritmos::mostrarPreguntaAnterior() {
    // Muestra la pregunta anterior
    if (preguntaActual > 0) {
        preguntaActual--;
        mostrarPregunta(texto[preguntaActual]);
    }
}

// Muestra las respuestas correctas de todas las preguntas, en un recuadro tipo mensaje
void Quiz_Algoritmos::mostrarRespuestas() {
    // Ordenando las respuestas correctas de todas las preguntas
    QString info;
    for (const auto& pregunta : texto) {
        info += "<font color='white'>" + pregunta.Pregunta + "</font><br>" "<font color='white'>Respuesta correcta: </font> <font color='white'>" + pregunta.Respuestas[pregunta.Respuesta_Correcta] + "</font><br><br>";
    }

    QMessageBox msgBox;
    msgBox.setTextFormat(Qt::RichText);
    msgBox.information(this, "Respuestas Correctas", info);
}

// Liberando la memoria
Quiz_Algoritmos::~Quiz_Algoritmos() {
    delete ui; // Libera la memoria utilizada por la interfaz de usuario de pregunta2
}

// Emite la señal para regresar a la ventana anterior y oculta esta ventana
void Quiz_Algoritmos::volver_a_Menu() {
    emit regresar_a_Menu();
    this->hide();
}
