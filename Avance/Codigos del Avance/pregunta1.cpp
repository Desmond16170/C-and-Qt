#include "pregunta1.h"
#include "ui_pregunta1.h"
#include <QMessageBox>


pregunta1::pregunta1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pregunta1),
    preguntaActual(0),
    respuestasCorrectas(0)

{ //aca se agregan las preguntas con sus respuestas y se le dice a la compu cual es la respuesta correcta, de 0 (a), 1(b), 2(c), 3(c)
    ui->setupUi(this);
    preguntas.append({ "¿A que se refiere FIFO?",
                      {"Primero en entrar, Primero en salir", "Ultimo en entrar, Ultimo en salir", "Ultimo en entrar, Primero en salir", "Ninguna de las anteriores"},
                      2 });
    preguntas.append({ "¿Cuál de las siguientes afirmaciones describe mejor una lista enlazada en C++?",
                      {"Una lista enlazada almacena la dirección de memoria de otra variable.", "Una lista enlazada es una estructura de datos dinámica que consiste en nodos, donde cada nodo contiene un elemento y una referencia al siguiente nodo.", "Una lista enlazada permite almacenar elementos del mismo tipo en una secuencia contigua de memoria", "Una lista enlazadauna forma de definir un tipo de dato que puede contener diferentes tipos de datos agrupados bajo un solo nombre." },
                      1 });
    preguntas.append({ "¿Cuáles son las características un árbol?",
                      {"Jerarquica y no lineal", "lineal", "Almacena elementos en pares key-values", "No tiene nodos"},
                      0 });
    preguntas.append({ "¿Que hace la operación Peek en un Stack(pila)?",
                      {"Agrega un elemento a la parte superior de una pila.", "Elimina un elemento de la parte superior de una pila.", "Comprueba si la pila está llena.", "Obtiene el valor del elemento superior sin eliminarlo" },
                      3 });
    preguntas.append({ "Cual de estas es una Estructura de Datos Lineal y Dinámica?",
                      {"Colas (Queues).","Arreglos (Arrays)", "Grafo(Graph)", "Árbol Binario de Búsqueda (BST)",},
                      0 });


    mostrarPregunta(preguntas[preguntaActual]);

    // Conectar el botón  a la ranura
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &pregunta1::mostrarSiguientePregunta);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &pregunta1::mostrarPreguntaAnterior);
    connect(ui->btnMostrarRespuestas, &QPushButton::clicked, this, &pregunta1::mostrarRespuestas);
    connect(ui->botonVolver, &QPushButton::clicked, this, &pregunta1::volverAMainWindow);




}

void pregunta1::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}

void pregunta1::mostrarPregunta(const Question &question) {
    ui->questionLabel->setText(question.text);
    ui->option1RadioButton->setText(question.options[0]);
    ui->option2RadioButton->setText(question.options[1]);
    ui->option3RadioButton->setText(question.options[2]);
    ui->option4RadioButton->setText(question.options[3]);
}
void pregunta1::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(preguntas[preguntaActual]);
}
void pregunta1::mostrarSiguientePregunta() {
    int respuestaSeleccionada = -1;
    if (ui->option1RadioButton->isChecked()) respuestaSeleccionada = 0;
    else if (ui->option2RadioButton->isChecked()) respuestaSeleccionada = 1;
    else if (ui->option3RadioButton->isChecked()) respuestaSeleccionada = 2;
    else if (ui->option4RadioButton->isChecked()) respuestaSeleccionada = 3;

    // Verificar la respuesta de la pregunta actual antes de incrementar preguntaActual
    if (preguntaActual < preguntas.size() && respuestaSeleccionada == preguntas[preguntaActual].correctAnswer) {
        respuestasCorrectas++;
    }

    // Incrementar preguntaActual solo si aún hay preguntas por mostrar
    if (preguntaActual + 1 < preguntas.size()) {
        preguntaActual++;
        mostrarPregunta(preguntas[preguntaActual]);
    } else {
        // Mostrar la puntuación y emitir la señal para regresar a MainWindow
        ui->nota->setText("Tu puntuación es: " + QString::number(respuestasCorrectas) + "/" + QString::number(preguntas.size()));
            emit quizTerminado();
    }
    if (preguntaActual + 1 >= preguntas.size()) {
            ui->btnMostrarRespuestas->setEnabled(true);
    }
}

void pregunta1::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
            preguntaActual--;
            mostrarPregunta(preguntas[preguntaActual]);
    }
}

void pregunta1::mostrarRespuestas() {
    QString info;
    for (const auto& pregunta : preguntas) {
            info += pregunta.text + "\nRespuesta correcta: " + pregunta.options[pregunta.correctAnswer] + "\n\n";
    }

    QMessageBox::information(this, "Respuestas Correctas", info);
}
    pregunta1::~pregunta1() {
    delete ui;
}


void pregunta1::volverAMainWindow() {
    emit regresarAMainWindow();
    this->hide(); // Opcionalmente, oculta esta ventana
}
