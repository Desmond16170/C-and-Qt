#ifndef CLASE1_H
#define CLASE1_H
#include <QMainWindow>
#include <QString>
#include <QVector>
#include "pregunta1.h"

// Estructura para representar una pregunta
struct Question3 {
    QString text;
    QVector<QString> options;
    int correctAnswer; // índice de la respuesta correcta
    QString rutaImagenRespuesta;
};

namespace Ui {
class Clase1;
}

class Clase1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clase1(QWidget *parent = nullptr);
    ~Clase1();
    void reiniciarQuiz();
    void setTextoEnLabel(const QString &texto);


signals:
    void quizTerminado();
    void regresarAMainWindow();
private slots:
    void mostrarSiguientePregunta();
    void mostrarPreguntaAnterior();
    void irQuiz1 ();
    void volverAMainWindow();

private:
    Ui::Clase1 *ui;
    QVector<Question3> preguntas;
    int preguntaActual;
    void mostrarPregunta(const Question3 &Question3);
    int respuestasCorrectas;
    pregunta1 *miPregunta1;


};

#endif // CLASE1_H
