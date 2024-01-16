/**
 * @file Clase_Educativa_Est.h
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Leccion Educativa sobre Algoritmos de Ordenamiento
 * @brief Esta Clase representa toda la estrucutura de la ventana, que presentara la informacion correspondiente a la Leccion sobre Estructuras de Datos
 * @version 1.0
 * @date 2023-11-26
 */
#ifndef CLASE_EDUCATIVA_EST_H
#define CLASE_EDUCATIVA_EST_H

// Importando librerias de Qt
#include <QMainWindow>
#include <QString>
#include <QVector>
#include "Quiz_Desde_ClaseEst.h"


/**
 * @brief Estructura auxiliar de la clase Leccion_Estructuras, contribuye a la organizacion de la informacion de la leccion ya que nos permite ordenar las lecciones por paginas
 */
struct Contenido_Leccion1 {
    QString Info;                  // Informacion sobre el tema
    QVector<QString> Orden;       // Ordena las paginas
    int Validacion;              // Índice de validacion para el contador
    QString Imagen_del_Tema;    // Ruta de la imagen relacionada con el tema
};

// Espacio de nombres para la interfaz de usuario generada por Qt
namespace Ui {
class Clase_Estructuras;
}

/**
 * @brief Clase Leccion_Estructuras que representa la lección de estructuras de datos, almacena la informacion y la organiza, ademas contiene funcionalidades para la navegacion dentro la app
 */
class Leccion_Estructuras : public QMainWindow
{
    Q_OBJECT

// Metodos tipo void no devuelven ningun valor

public:
    /**
     * @brief Constructor de la clase Leccion_Estructuras.
     * @param parent El widget padre que contendra a los otros widgets en esta ventana.
     */
    explicit Leccion_Estructuras(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase Leccion_Estructuras.
     */
    ~Leccion_Estructuras();

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
     * @brief mostrarQuiz2  Contiene las instrucciones del boton, cuando este se oprima mostrara el quiz de estructuras de datos
     */
    void irQuiz1();

    /**
     * @brief volviendo_a_Leccion  Contiene las instrucciones del boton, cuando este se oprima regresaremos a la leccion desde el quiz
     */
    void volviendo_a_Leccion();

    /**
     * @brief mostrarLeccion_Estructuras Despliega la toda la estructura de la ventana con la informacion sobre la Leccion de Algoritmos
     */
    void mostrarLeccion_Estructuras();

private:
    Ui::Clase_Estructuras *ui;          // Objeto de la interfaz de usuario generada por Qt
    QVector<Contenido_Leccion1> texto;  // Vector que almacena las paginas de la leccion
    int paginaActual;       // Índice de la pagina actual
    void mostrarPagina(const Contenido_Leccion1 &Contenido_Leccion1); // Muestra las paginas en el orden que fueron agregadas
    int Verificando;  // Contador de paginas
    Quiz_Desde_Estructuras *Quiz_Estructuras;  // Puntero a un objeto de tipo pregunta1copia
};

#endif // CLASE_EDUCATIVA_EST_H
