/**
 * @file Quiz_Desde_ClaseEst.h
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Construye el Quiz de Estructuras de Datos que se despliega desde lo interno de la Leccion de Estructuras de Datos
 * @brief Esta Clase es la encargada de construir el Quiz de Estructuras de Datos, ordenar las preguntas, recibir las respuestas y validar aciertos, ademas nos permite navegar por la aplicacion
 * @version 1.0
 * @date 2023-11-26
 */
#ifndef QUIZ_DESDE_CLASEEST_H
#define QUIZ_DESDE_CLASEEST_H

// Importando librerias de Qt
#include <QMainWindow>
#include <QString>
#include <QVector>

/**
 * @brief Estructura auxiliar de la clase Quiz_Desde_Estructuras, se usa para presentar una pregunta, contiene las preguntas y sus repuestas
 */
struct Quiz_Desde_Leccion1 {
    QString Pregunta;                   // Texto de la pregunta
    QVector<QString> Respuestas;       // Opciones posibles para la respuesta
    int Respuesta_Correcta;              // Índice de la respuesta correcta en el vector de opciones
};

// Espacio de nombres generado por Qt
namespace Ui {
class Preguntas_Leccion_Est;
}

/**
 * @brief Clase Quiz_Desde_Estructuras presenta las preguntas en formato quiz de seleccion unica, obtiene resultados y brinda una calificación, y ademas contiene instrucciones para botones de navegacion
 */
class Quiz_Desde_Estructuras : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase Quiz_Desde_Estructuras
     * @param parent Es el widget padre de el provendran los otros widgets que se desplieguen a partir de esta ventana
     */
    explicit Quiz_Desde_Estructuras(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase Quiz_Desde_Estructuras
     */
    ~Quiz_Desde_Estructuras();

    /**
     * @brief reiniciarQuiz Reinicia a 0 la nota y el orden del quiz cada que el programa se cierra
     */
    void reiniciarQuiz();

    /**
     * @brief setTextoEnLabel Ubica el texto en un QLabel(Cuadro de Texto) de la interfaz gráfica.
     * @param texto Cadena de Caracteres
     */
    void setTextoEnLabel(const QString &texto);

signals:
    /**
     * @brief quizTerminado Señal que se conecta con los botonos para indicar que el quiz termino
     */
    void quizTerminado();

    /**
     * @brief regresar_a_Menu Señal que se conecta con nuestro boton para regresar al menu
     */
    void regresar_a_Menu();

    /**
     * @brief regreso_a_Leccion Señal que se conecta con nuestro boton para regresar a la leccion de Estructuras de Datos desde el quiz
     */
    void regreso_a_Leccion();

private slots:

    /**
     * @brief mostrarSiguientePregunta Contiene las instrucciones del boton, cuando este se oprima mostrara la siguiente pregunta
     */
    void mostrarSiguientePregunta();

    /**
     * @brief mostrarPreguntaAnterior Contiene las instrucciones del boton, cuando este se oprima mostrara la pregunta anterior
     */
    void mostrarPreguntaAnterior();

    /**
     * @brief mostrarRespuestas Contiene las instrucciones del boton, cuando este se oprima mostrara las respuestas del quiz en un recuadro de mensaje
     */
    void mostrarRespuestas();

    /**
     * @brief volviendo_a_Leccion Contiene las instrucciones para que el usuario vuelva a la leccion por medio de un boton en el quiz
     */
    void volviendo_a_Leccion();

private:
    Ui::Preguntas_Leccion_Est *ui;          // Objeto de la interfaz de usuario generada por Qt
    QVector<Quiz_Desde_Leccion1> texto;    // Vector que almacena las preguntas del quiz
    int preguntaActual;              // Índice de la pregunta actual
    int respuestasCorrectas;         // Contador de respuestas correctas

    // Muestra una pregunta específica
    void mostrarPregunta(const Quiz_Desde_Leccion1 &pregunta);
};

#endif // pregunta1copia_H
