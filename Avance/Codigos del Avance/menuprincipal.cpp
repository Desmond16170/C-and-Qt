#include "menuprincipal.h"
#include "ui_menuprincipal.h"


MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
    miPregunta1 = new pregunta1(this);
    connect(ui->quizAlgoritmos, &QPushButton::clicked, this, &MenuPrincipal::mostrarPregunta1);
    miPregunta2 = new pregunta2(this);
    connect(ui->quizOrdenamieto, &QPushButton::clicked, this, &MenuPrincipal::mostrarPregunta2);
    miClase1 = new Clase1(this);
    connect(ui->ClaseAlgoritmos, &QPushButton::clicked, this, &MenuPrincipal::mostrarClase1);
    miClase3 = new Clase3(this);
    connect(ui->ClaseOrdenamieto, &QPushButton::clicked, this, &MenuPrincipal::mostrarClase3);



}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
    miPregunta1 = new pregunta1(this);
    miPregunta2 = new pregunta2(this);
    miClase1 = new Clase1(this);
    miClase3 = new Clase3(this);
}

void MenuPrincipal::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}

void MenuPrincipal::mostrarPregunta1() {
    miPregunta1->show(); // Muestra la ventana de pregunta1
}

void MenuPrincipal::mostrarPregunta2() {
    miPregunta2->show(); // Muestra la ventana de pregunta2
}

void MenuPrincipal::mostrarClase1() {
    miClase1->show(); // Muestra la ventana de clase1
}

void MenuPrincipal::mostrarClase3() {
    miClase3->show(); // Muestra la ventana de clase2
}
