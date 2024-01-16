#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuprincipal.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu = new MenuPrincipal(this); // Inicializa pregunta1

    connect(ui->botonEnter, SIGNAL(clicked()), this, SLOT(on_botonEnter_clicked())); // Conecta el botón
    //connect(menu, &menuprincipal::quizTerminado, this, &MainWindow::mostrarMainWindow);
    ///connect(menu, &menuprincipal::regresarAMainWindow, this, &MainWindow::mostrarMainWindow);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarMainWindow() {
    this->show(); // Muestra MainWindow
}

void MainWindow::on_botonEnter_clicked()
{
    QString texto = ui->nombre->text();
    menu->setTextoEnLabel(texto);
    menu->show(); // Muestra
}

