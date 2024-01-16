#include "pregunta2.h"
#include "ui_pregunta2.h"
#include <QMessageBox>


pregunta2::pregunta2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pregunta2),
    preguntaActual(0),
    respuestasCorrectas(0)

{ //aca se agregan las preguntas con sus respuestas y se le dice a la compu cual es la respuesta correcta, de 0 (a), 1(b), 2(c), 3(c)
    ui->setupUi(this);
    preguntas.append({ "Pregunta sobre Burbuja",
                      {"Opcion a", "Opcion b", "Opcion c", "Opcion d"},
                      2 });
    preguntas.append({ "Pregunta sobre Insercion",
                      {"Opcion a", "Opcion b", "Opcion c", "Opcion d" },
                      1 });
    preguntas.append({ "Pregunta sobre Seleccion",
                      {"Opcion a", "Opcion b", "Opcion c", "Opcion d"},
                      0 });
    preguntas.append({ "Pregunta sobre Rapido",
                      {"Opcion a", "Opcion b", "Opcion c", "Opcion d" },
                      3 });
    preguntas.append({ "Presgunta sobre Fusion",
                      {"Opcion a","Opcion b", "Opcion c", "Opcion d",},
                      0 });


    mostrarPregunta(preguntas[preguntaActual]);

    // Conectar el botón  a la ranura
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &pregunta2::mostrarSiguientePregunta);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &pregunta2::mostrarPreguntaAnterior);
    connect(ui->btnMostrarRespuestas, &QPushButton::clicked, this, &pregunta2::mostrarRespuestas);
    connect(ui->botonVolver, &QPushButton::clicked, this, &pregunta2::volverAMainWindow);




}

void pregunta2::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}

void pregunta2::mostrarPregunta(const Question2 &question) {
    ui->questionLabel->setText(question.text);
    ui->option1RadioButton->setText(question.options[0]);
    ui->option2RadioButton->setText(question.options[1]);
    ui->option3RadioButton->setText(question.options[2]);
    ui->option4RadioButton->setText(question.options[3]);
}
void pregunta2::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(preguntas[preguntaActual]);
}
void pregunta2::mostrarSiguientePregunta() {
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

void pregunta2::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
            preguntaActual--;
            mostrarPregunta(preguntas[preguntaActual]);
    }
}

void pregunta2::mostrarRespuestas() {
    QString info;
    for (const auto& pregunta : preguntas) {
            info += pregunta.text + "\nRespuesta correcta: " + pregunta.options[pregunta.correctAnswer] + "\n\n";
    }

    QMessageBox::information(this, "Respuestas Correctas", info);
}
    pregunta2::~pregunta2() {
    delete ui;
}


void pregunta2::volverAMainWindow() {
    emit regresarAMainWindow();
    this->hide(); // Opcionalmente, oculta esta ventana
}
