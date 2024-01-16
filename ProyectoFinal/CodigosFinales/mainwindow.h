/**
 * @file mainwindow.h
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Ventana Principal de nuestra aplicacion le da la Bienvenida al Usuario
 * @brief Esta Clase nos permite desplegar la informacion inicial de nuestra aplicacion y registrar al usuario
 * @version 1.0
 * @date 2023-11-26
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Importando libreria de Qt
#include "Menu_Principal.h" // Incluyendo clase de Menu Principal.

// Espacio de nombres generado por Qt
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Clase MainWindow contiene la estructura de nuestra ventana inicial de este ventana surgen las demas.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

// Metodos tipo void no devuelven ningun valor
public:
    // Constructor de la clase
    /**
     * @brief Constructor de la clase de la clase MainWindow
     * @param parent El widget padre que contendra a los otros widgets en esta ventana.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase MainWindow
     */
    ~MainWindow();

public slots:
    /**
     * @brief mostrarMainWindow Despliega la Ventana Principal muestra el diseño de la aplicacion
     */
    void mostrarMainWindow();

private slots:
    /**
     * @brief ID_y_Entrar Registra el nombre del usuario y le permite ingresar al sistema
     */
    void ID_y_Entrar();

private:
    Ui::MainWindow *ui;     // Objeto de la interfaz de usuario generada por Qt
    MenuPrincipal *menu;    // Instancia de la segunda ventana

protected:
    /**
     * @brief closeEvent Metodo reservado de Qt cierra el programa correctamente
     * @param event Evento actual, reacciona al cierre del programa
     */
    void closeEvent(QCloseEvent *event) override;
};

#endif // MAINWINDOW_H
