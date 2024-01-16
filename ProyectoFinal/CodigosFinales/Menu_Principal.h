/**
 * @file Menu_Principal.h
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Menu Principal primeras interacciones del usuario con la aplicacion eduactiva
 * @brief Esta Clase es la encargada de desplegar el menu principal y contiene los botones para la navegacion en nuestra aplicacion
 * @version 1.0
 * @date 2023-11-26
 */

#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H


#include "Quiz_Estructuras.h" // Añadiendo Clase Quiz_Estructuras
#include "Quiz_Algoritmos.h" // Añadiendo Clase Quiz_Algoritmos
#include "Clase_Educativa_Est.h" // Añadiendo Clase Leccion_Estructuras
#include "Clase_Educativa_Alg.h" // Añadiedno Clase Leccion_Algortmos
#include <QMainWindow> // Importando libreria de Qt

// Espacio de nombres generado por Qt
namespace Ui {
class MenuPrincipal;
}

/**
 * @brief Clase MenuPrincipal presenta el diseño del Menu de nuestra Aplicacion contiene los botones hacia las demas ventanas
 */
class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

// Metodos tipo void no devuelven ningun valor
public:

    /**
     * @brief Constructor de la clase MenuPrincipal
     * @param parent  parent El widget padre que contendra a los otros widgets en esta ventana
     */
    explicit MenuPrincipal(QWidget *parent = nullptr);


    /**
     * @brief Destructor de la clase MenuPrincipal
     */
    ~MenuPrincipal();

    /**
     * @brief setTextoEnLabel Ubica el texto en un QLabel(Cuadro de Texto) de la interfaz gráfica.
     * @param texto Cadena de Caracteres
     */
    void setTextoEnLabel(const QString &texto);

// Slots para mostrar diferentes ventanas o funcionalidades
private slots:

    /**
     * @brief mostrar_Quiz_Estructuras Contiene las instrucciones del boton, dirige al usuario hacia el Quiz de Estructuras de Datos una vez este oprimio el boton
     */
    void mostrar_Quiz_Estructuras();

    /**
     * @brief mostrar_Quiz_Algoritmos Contiene las instrucciones del boton, dirige al usuario hacia el Quiz de Algoritmos de Ordenamiento una vez este oprimio el boton
     */
    void mostrar_Quiz_Algoritmos();

    /**
     * @brief mostrar_Leccion_Estructuras  Contiene las instrucciones del boton, dirige al usuario hacia la leccion de Estructuras de Datos una vez este oprimio el boton
     */
    void mostrar_Leccion_Estructuras();

    /**
     * @brief mostrar_Leccion_Algoritmos Contiene las instrucciones del boton, dirige al usuario hacia la leccion de Algoritmos de Ordenamiento una vez este oprimio el boton
     */
    void mostrar_Leccion_Algoritmos();

    /**
     * @brief Desplegar Despliega en pantalla en diseño del Menu Principal, ademas nos sirve para desplejar las nuevas ventanas que surgen de la presente ventana
     */
    void Desplegar();

private:
    Ui::MenuPrincipal *ui;    // Objeto de la interfaz de usuario generada por Qt
    Quiz_Estructuras *Quiz_de_Estructuras;   // Instancia de la clase Quiz_de_Estructuras
    Quiz_Algoritmos *Quiz_de_Algoritmos;   // Instancia de la clase Quiz_de_Algoritmos
    Leccion_Estructuras *Leccion_de_Estructuras;         // Instancia de la clase Leccion_de_Estructuras
    Leccion_Algoritmos *Leccion_de_Algoritmos;         // Instancia de la clase Leccion_de_Algoritmos
};

#endif // MENU_PRINCIPAL_H
