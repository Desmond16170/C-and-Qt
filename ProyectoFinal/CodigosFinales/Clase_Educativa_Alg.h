/**
 * @file Clase_Educativa_Alg.h
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Leccion Educativa sobre Algoritmos de Ordenamiento
 * @brief Esta Clase representa toda la estrucutura de la ventana, que presentara la informacion correspondiente a la Leccion sobre Algoritmos de Ordenamiento
 * @version 1.0
 * @date 2023-11-26 
 */
#ifndef CLASE_EDUCATIVA_ALG_H
#define CLASE_EDUCATIVA_ALG_H

// Importando librerias de Qt
#include <QMainWindow>
#include <QString>
#include <QVector>
#include "Quiz_Desde_ClaseAlg.h"

/**
 * @brief Estructura auxiliar de la clase Leccion_Algoritmos, contribuye a la organizacion de la informacion de la leccion ya que nos permite ordenar las lecciones por paginas
 */
struct Contenido_Leccion2 {
    QString Info;                  // Informacion sobre el tema
    QVector<QString> Orden;       // Ordena las paginas
    int Validacion;              // Índice de validacion para el contador
    QString Imagen_del_Tema;    // Ruta de la imagen relacionada con el tema
};

// Espacio de nombres para la interfaz de usuario generada por Qt
namespace Ui {
class Clase_Algoritmos;
}

/**
 * @brief Clase Leccion_Algoritmos que representa la lección de algoritmos de ordenamiento, almacena informacion y la organiza, ademas contiene funcionalidades para la navegacion dentro la app
 */
class Leccion_Algoritmos: public QMainWindow
{
    Q_OBJECT

// Metodos tipo void no devuelven ningun valor

public:
    /**
     * @brief Constructor de la clase Leccion_Algoritmos.
     * @param parent El widget padre que contendra a los otros widgets en esta ventana.
     */
    explicit Leccion_Algoritmos(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase Leccion_Algoritmos.
     */
    ~Leccion_Algoritmos();

    /**
     * @brief reiniciarQuiz Reinicia a 0 la nota y el orden del quiz cada que el programa se cierra
     */
    void reiniciarQuiz();

    /**
     * @brief setTextoEnLabel Ubica el texto en un QLabel(Cuadro de Texto) de la interfaz gráfica.
     * @param texto Cadena de Caracteres
     */
    void setTextoEnLabel(const QString &texto);

    /**
     * @brief volver_a_Menu Contiene las instrucciones para que el usuario vuelva al menu principal por medio de un boton
     */
    void volver_a_Menu();

signals:
    /**
     * @brief quizTerminado Señal que se conecta con los botonos para indicar que el quiz termino
     */
    void quizTerminado();

    /**
     * @brief regresar_a_Menu Señal que se conecta con nuestro boton para regresar al menu
     */
    void regresar_a_Menu();

private slots:

    /**
     * @brief mostrarSiguientePagina Contiene las instrucciones del boton, cuando este se oprima mostrara la siguiente pagina
     */
    void mostrarSiguientePagina();

    /**
     * @brief mostrarPaginaAnterior  Contiene las instrucciones del boton, cuando este se oprima mostrara la pagina anterior
     */
    void mostrarPaginaAnterior();

    /**
     * @brief mostrarQuiz2  Contiene las instrucciones del boton, cuando este se oprima mostrara el quiz de algoritmos
     */
    void mostrarQuiz2();


    /**
     * @brief volviendo_a_Leccion  Contiene las instrucciones del boton, cuando este se oprima regresaremos a la leccion desde el quiz
     */
    void volviendo_a_Leccion();


    /**
     * @brief mostrarLeccion_Algoritmos Despliega la toda la estructura de la ventana con la informacion sobre la Leccion de Estrucuturas
     */
    void mostrarLeccion_Algoritmos();


private:
    Ui::Clase_Algoritmos *ui;            // Objeto de la interfaz de usuario generada por Qt
    QVector<Contenido_Leccion2> texto;    // Vector que almacena las paginas de la Leccion
    int Pagina_Actual;                 // Índice de la pagina actual
    int Verificacion;            // Verfica estabilidad del programa
    Quiz_Desde_Algoritmos *Quiz_algoritmos;   // Puntero a un objeto de tipo quiz

    void mostrarInformacion(const Contenido_Leccion2 &contenido);
};

#endif // CLASE_EDUCATIVA_ALG_H
