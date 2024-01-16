/**
 * @file main.cpp
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Crea el frame de nuestra app
 * @brief Se ejecuta en bucle la aplicacion hasta que el usuario la cierra, funciona en bluce para responder correctantemento a las acciones del usurio usuario
 * @version 1.0
 * @date 2023-11-26
 */
#include "mainwindow.h" // Incluye la declaración de la clase MainWindow

#include <QApplication> // Incluye la clase QApplication, que gestiona la aplicación Qt

int main(int argc, char *argv[]) {
    // Crea una aplicación Qt
    QApplication a(argc, argv);

    // Crea una instancia de la clase MainWindow
    MainWindow w;

    // Muestra la ventana principal
    w.show();

    // Ejecuta el bucle de eventos de la aplicación
    return a.exec();
}
