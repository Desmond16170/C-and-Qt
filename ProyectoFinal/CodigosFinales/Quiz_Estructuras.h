/**
 * @file Quiz_Estructuras.h
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Construye el Quiz de Estructuras de Datos que se despliega desde el Menu Principal
 * @brief Esta Clase es la encargada de construir el Quiz de Estructuras de Datos, ordenar las preguntas, recibir las respuestas y validar aciertos, ademas nos permite navegar por la aplicacion
 * @version 1.0
 * @date 2023-11-26
 */
#ifndef QUIZ_ESTRUCTURAS_H
#define QUIZ_ESTRUCTURAS_H

// Importando Librerias de Qt
#include <QMainWindow>
#include <QString>
#include <QVector>

/**
 * @brief Estructura auxiliar de la clase Quiz_Estructuras, para representar una pregunta, contiene las preguntas y sus repuestas
 */
struct Quiz_de_Estructuras {
    QString Pregunta;                   // Texto de la pregunta
    QVector<QString> Respuestas;       // Opciones posibles para la respuesta
    int Respuesta_Correcta;              // Índice de la respuesta correcta en el vector de opciones
};

// Espacio de nombres generado por Qt
namespace Ui {
class Preguntas_Estructuras;
}

/**
 * @brief Clase Quiz_Estructuras presenta las preguntas en formato quiz de seleccion unica, obtiene resultados y brinda una calificación
 */
class Quiz_Estructuras : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase Quiz_Estructuras
     * @param parent Es el widget padre de el provendran los otros widgets que se desplieguen a partir de esta ventana
     */
    explicit Quiz_Estructuras(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase Quiz_Estructuras
     */
    ~Quiz_Estructuras();

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
     * @brief mostrarSiguientePregunta Contiene las instrucciones del boton, cuando este se oprima mostrara la siguiente pregunta
     */
    void mostrarSiguientePregunta();

    /**
     * @brief mostrarPreguntaAnterior Contiene las instrucciones del boton, cuando este se oprima mostrara la pagina anterior
     */
    void mostrarPreguntaAnterior();

    /**
     * @brief mostrarRespuestas Contiene las instrucciones del boton, cuando este se oprima mostrara las respuestas del quiz en un recuadro de mensaje
     */
    void mostrarRespuestas();

private:
    Ui::Preguntas_Estructuras *ui;          // Objeto de la interfaz de usuario generada por Qt
    QVector<Quiz_de_Estructuras> texto; // Vector que almacena las preguntas del quiz
    int preguntaActual;          // Índice de la pregunta actual
    int respuestasCorrectas;     // Contador de respuestas correctas

    // Muestra una pregunta específica
    void mostrarPregunta(const Quiz_de_Estructuras &preguntas);
};

#endif // QUIZ_ESTRUCTURAS_H
