#include "clase3.h"
#include "ui_clase3.h"

#include <QMessageBox>


Clase3::Clase3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clase3),
    preguntaActual(0),
    respuestasCorrectas(0),
    miPregunta2(new pregunta2(this))

{ //aca se agregan las preguntas con sus respuestas y se le dice a la compu cual es la respuesta correcta, de 0 (a), 1(b), 2(c), 3(c)
    ui->setupUi(this);
    preguntas.append({ "Teoría y definicón de los algoritmos de ordenamiento",
                          {""},
                          0,
                          ""});
    preguntas.append({ "Bubble Sort (Burbuja)",
                      {""},
                      0,
                      "image003"});
    preguntas.append({ "Selection Sort (Selección)",
                      {""},
                      0,
                      "image005"});
    preguntas.append({ "Insertion Sort (Inserción)",
                      {""},
                      0,
                      ""});
    preguntas.append({ "Quick Sort (Rápido)",
                      {""},
                      0,
                      ""});




    mostrarPregunta(preguntas[preguntaActual]);

    // Conectar el botón  a la ranura
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &Clase3::mostrarSiguientePregunta);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &::Clase3::mostrarPreguntaAnterior);
    connect(ui->irQuiz2, &QPushButton::clicked, this, &::Clase3::mostrasquiz2);
    connect(ui->botonVolver, &QPushButton::clicked, this, &::Clase3::volverAMainWindow);




}

void Clase3::mostrarPregunta(const Question4 &Question4) {
    ui->titulo->setText(Question4.text); //esto carga El titulo del tema
    ui->texto->setText(Question4.options[0]); // esto carga la info que queramos montar
    // Asumiendo que la ruta de la imagen está almacenada en Question3.options[1]
    QString imagePath = ":/images/images/" +  Question4.rutaImagenRespuesta;
    QPixmap image(imagePath);

    if (!image.isNull()) {
        ui->image->setPixmap(image);
        ui->image->setScaledContents(true); // Para escalar la imagen según el tamaño del QLabel
    } else {
        // Manejar el caso en que la imagen no se pueda cargar
        QMessageBox::warning(this, "Error de Carga", "No se pudo cargar la imagen: " + imagePath);
    }
}



void Clase3::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}


void Clase3::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(preguntas[preguntaActual]);
}
void Clase3::mostrarSiguientePregunta() {
    int respuestaSeleccionada = -1;

    // Verificar la respuesta de la pregunta actual antes de incrementar preguntaActual
    if (preguntaActual < preguntas.size() && respuestaSeleccionada == preguntas[preguntaActual].correctAnswer) {
        respuestasCorrectas++;
    }

    // Incrementar preguntaActual solo si aún hay preguntas por mostrar
    if (preguntaActual + 1 < preguntas.size()) {
        preguntaActual++;
        mostrarPregunta(preguntas[preguntaActual]);
    } else {
    }
}

void Clase3::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
            preguntaActual--;
            mostrarPregunta(preguntas[preguntaActual]);
    }
}

void Clase3::mostrasquiz2() {
    miPregunta2->show(); // Muestra la ventana de pregunta1
}
    Clase3::~Clase3() {
    delete ui;
}


void Clase3::volverAMainWindow() {
    emit regresarAMainWindow();
    this->hide(); // Opcionalmente, oculta esta ventana
}
