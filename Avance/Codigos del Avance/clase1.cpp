#include "clase1.h"//.h"
#include "ui_clase1.h"
#include <QMessageBox>


Clase1::Clase1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clase1),
    preguntaActual(0),
    respuestasCorrectas(0),
    miPregunta1(new pregunta1(this))

{ //aca se agregan las preguntas con sus respuestas y se le dice a la compu cual es la respuesta correcta, de 0 (a), 1(b), 2(c), 3(c)
    ui->setupUi(this);
    preguntas.append({ "Estructuras de Datos",
                      {"Las estructuras de datos en C++ son diferentes métodos de organización de información,"
                       " nos permiten almacenar y manejar datos de forma ordenada y eficiente "
                       "es importante tener en cuenta que la estructura que vayamos a utilizarn"
                       "en nuestro programa depende de las necesidades de este"},
                      0,
                      "image002"});
    preguntas.append({ "Tipos de estructuras de datos",
                      {""},
                      0,
                      "image003"});
    preguntas.append({ "Lineales y Estaticas:",
                      {""},
                      0,
                      "image005"});
    preguntas.append({ "Lineales y Dinamicas:",
                      {""},
                      0,
                      "image002"});
    preguntas.append({ "No lineales:",
                      {""},
                      0,
                      "image002"});
    preguntas.append({ "Lineales y Dinámicas: ",
                      {"loremipsun loremipsun /n loremipsun " },
                      0,
                      "orden"});



    mostrarPregunta(preguntas[preguntaActual]);

    // Conectar el botón  a la ranura
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &Clase1::mostrarSiguientePregunta);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &::Clase1::mostrarPreguntaAnterior);
    connect(ui->irQuiz1, &QPushButton::clicked, this, &Clase1::irQuiz1);
    connect(ui->botonVolver, &QPushButton::clicked, this, &::Clase1::volverAMainWindow);




}

void Clase1::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}


void Clase1::mostrarPregunta(const Question3 &Question3) {
    ui->titulo->setText(Question3.text); //esto carga El titulo del tema
    ui->texto->setText(Question3.options[0]); // esto carga la info que queramos montar
    // Asumiendo que la ruta de la imagen está almacenada en Question3.options[1]
    QString imagePath = ":/images/images/" +  Question3.rutaImagenRespuesta;
    QPixmap image(imagePath);


    if (!image.isNull()) {
        ui->image->setPixmap(image);
        ui->image->setScaledContents(true); // Para escalar la imagen según el tamaño del QLabel
    } else {
        // Manejar el caso en que la imagen no se pueda cargar
        QMessageBox::warning(this, "Error de Carga", "No se pudo cargar la imagen: " + imagePath);
    }
}

void Clase1::reiniciarQuiz() {
    preguntaActual = 0;
    respuestasCorrectas = 0;
    mostrarPregunta(preguntas[preguntaActual]);
}
void Clase1::mostrarSiguientePregunta() {
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

void Clase1::mostrarPreguntaAnterior() {
    if (preguntaActual > 0) {
            preguntaActual--;
            mostrarPregunta(preguntas[preguntaActual]);
    }
}

void Clase1::irQuiz1() {
    miPregunta1->show(); // Muestra la ventana de pregunta1
}
    Clase1::~Clase1() {
    delete ui;
}


void Clase1::volverAMainWindow() {
    emit regresarAMainWindow();
    this->hide(); // Opcionalmente, oculta esta ventana
}
