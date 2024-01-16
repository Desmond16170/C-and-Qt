/**
 * @file mainwindow.cpp
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Cuerpo de la Ventana Principal de nuestra aplicacion le da la Bienvenida al Usuario
 * @brief Se crea el Objeto de tipo MainWindow nos permite desplegar la informacion inicial de nuestra aplicacion, registrar al usuario y lo invita a entrar al programa
 * @version 1.0
 * @date 2023-11-26
 */
#include "mainwindow.h"       // Incluye la declaración de la clase MainWindow
#include "ui_mainwindow.h"    // Incluye la interfaz de usuario de la clase MainWindow
#include "Menu_Principal.h"    // Incluye la declaración de la clase MenuPrincipal
#include <QCoreApplication> // Libreria de Qt

// Creando Objeto de tipo MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu = new MenuPrincipal(this); // Inicializa un objeto de la clase MenuPrincipal

    // Conecta la señal clicked() del botón 'botonEnter' con el slot on_botonEnter_clicked()
    connect(ui->botonEnter, SIGNAL(clicked()), this, SLOT(ID_y_Entrar()));
}

MainWindow::~MainWindow()
{
    delete ui; // Libera la memoria utilizada por la interfaz de usuario de MainWindow
}

void MainWindow::mostrarMainWindow()
{
    this->show(); // Muestra la ventana MainWindow
}

void MainWindow::ID_y_Entrar()
{
    // Obtiene el texto ingresado en el campo 'nombre'
    QString texto = ui->nombre->text();

    // Configura el texto en una etiqueta dentro del objeto MenuPrincipal
    menu->setTextoEnLabel(texto);

    // Muestra la ventana MenuPrincipal y oculta la ventana MainWindow
    menu->show();
    this->hide();
}

// Realiza cualquier limpieza o acción necesaria antes de cerrar la ventana
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
}
