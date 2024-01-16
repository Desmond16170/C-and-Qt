/**
 * @file Quiz_Estructuras.cpp
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Es el cuerpo del Quiz de Estructuras de Datos que se despliega desde el Menu Principal
 * @brief Se crea el Objeto de tipo Quiz_Estructuras contiene la infromacion y las acciones del Quiz de Estructuras de Datos
 * @version 1.0
 * @date 2023-11-26
 */
#include "Quiz_Estructuras.h"          // Incluye la declaración de la clase
#include "ui_Quiz_Estructuras.h"       // Incluye la interfaz de usuario de la clase
#include <QMessageBox>          // Incluye la clase para mostrar mensajes de información

// Creando Objeto de tipo Quiz_Estructuras
Quiz_Estructuras::Quiz_Estructuras(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Preguntas_Estructuras),
    preguntaActual(0),
    respuestasCorrectas(0)
{
    ui->setupUi(this);

    // Agrega preguntas con sus opciones y respuestas correctas
    texto.append({ "¿A que se refiere FIFO?",
                      {"Primero en entrar, Primero en salir",
                       "Ultimo en entrar, Ultimo en salir",
                       "Ultimo en entrar, Primero en salir",
                       "Ninguna de las anteriores"},
                      2 });

    texto.append({ "¿Cuál de las siguientes afirmaciones describe mejor una lista enlazada en C++?",
                      {"Una lista enlazada almacena la dirección de memoria de otra variable.",
                       "Una lista enlazada consiste en nodos, donde cada nodo contiene un elemento y una referencia al siguiente nodo.",
                       "Una lista enlazada permite almacenar elementos del mismo tipo en una secuencia contigua de memoria",
                       "Una lista enlazada puede contener diferentes tipos de datos agrupados bajo un solo nombre." },
                      1 });

    texto.append({ "¿Cuáles son las características un árbol?",
                      {"Jerarquica y no lineal", "Lineal", "Almacena elementos en pares key-values", "No tiene nodos"},
                      0 });

    texto.append({ "¿Que hace la operación Peek en un Stack(pila)?",
                      {"Agrega un elemento a la parte superior de una pila.",
                       "Elimina un elemento de la parte superior de una pila.",
                       "Comprueba si la pila está llena.",
                       "Obtiene el valor del elemento superior sin eliminarlo" },
                      3 });

    texto.append({ "¿Cual de estas es una Estructura de Datos Lineal y Dinámica?",
                      {"Colas (Queues).","Arreglos (Arrays)", "Grafo(Graph)", "Árbol Binario de Búsqueda (BST)",},
                      0 });


    // Muestra la primera pregunta
    mostrarPregunta(texto[preguntaActual]);

    // Conecta los botones a las ranuras correspondientes
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &Quiz_Estructuras::mostrarSiguientePregunta);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &Quiz_Estructuras::mostrarPreguntaAnterior);
    connect(ui->btnMostrarRespuestas, &QPushButton::clicked, this, &Quiz_Estructuras::mostrarRespuestas);
    connect(ui->botonVolver, &QPushButton::clicked, this, &Quiz_Estructuras::volver_a_Menu);
}

// Permite introducir el texto
void Quiz_Estructuras::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}

// Despliega el contenido de la pregunta
void Quiz_Estructuras::mostrarPregunta(const Quiz_de_Estructuras &question) {
    // Muestra la pregunta y opciones en la interfaz gráfica
    ui->questionLabel->setText(question.Pregunta);
    ui->option1RadioButton->setText(question.Respuestas[0]);
    ui->option2RadioButton->setText(question.Respuestas[1]);
    ui->option3RadioButton->setText(question.Respuestas[2]);
    ui->option4RadioButton->setText(question.Respuestas[3]);
}

// Cuando se acaba el programa la nota y las preguntas se reinician
void Quiz_Estructuras::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(texto[preguntaActual]);
}

// Realiza la accion del boton "siguiente"
void Quiz_Estructuras::mostrarSiguientePregunta() {
    // Determina la respuesta seleccionada por el usuario
    int respuestaSeleccionada = -1;
    if (ui->option1RadioButton->isChecked()) respuestaSeleccionada = 0;
    else if (ui->option2RadioButton->isChecked()) respuestaSeleccionada = 1;
    else if (ui->option3RadioButton->isChecked()) respuestaSeleccionada = 2;
    else if (ui->option4RadioButton->isChecked()) respuestaSeleccionada = 3;

    // Verifica la respuesta y actualiza el conteo
    if (preguntaActual < texto.size() && respuestaSeleccionada == texto[preguntaActual].Respuesta_Correcta) {
        respuestasCorrectas++;
    }

    // Muestra la siguiente pregunta o finaliza el cuestionario
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
        ui->btnMostrarRespuestas->setEnabled(true);
    }
}

// Realiza la accion del boton "anterior"
void Quiz_Estructuras::mostrarPreguntaAnterior() {
    // Muestra la pregunta anterior
    if (preguntaActual > 0) {
        preguntaActual--;
        mostrarPregunta(texto[preguntaActual]);
    }
}

// Muestra las respuestas correctas de todas las preguntas, en un recuadro tipo mensaje
void Quiz_Estructuras::mostrarRespuestas() {
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
Quiz_Estructuras::~Quiz_Estructuras() {
    delete ui; // Libera la memoria utilizada por la interfaz de usuario de pregunta1
}

// Emite la señal para regresar a la ventana anterior y oculta esta ventana
void Quiz_Estructuras::volver_a_Menu() {
    // Emite la señal para regresar a MainWindow y oculta esta ventana
    emit regresar_a_Menu();
    this->hide();
}
