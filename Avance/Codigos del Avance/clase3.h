#ifndef CLASE3_H
#define CLASE3_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include "pregunta2.h"

// Estructura para representar una pregunta
struct Question4 {
    QString text;
    QVector<QString> options;
    int correctAnswer; // índice de la respuesta correcta
    QString rutaImagenRespuesta;
};

namespace Ui {
class Clase3;
}

class Clase3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clase3(QWidget *parent = nullptr);
    ~Clase3();
    void reiniciarQuiz();
    void setTextoEnLabel(const QString &texto);


signals:
    void quizTerminado();
    void regresarAMainWindow();
private slots:
    void mostrarSiguientePregunta();
    void mostrarPreguntaAnterior();
    void mostrasquiz2();
    void volverAMainWindow();

private:
    Ui::Clase3 *ui;
    QVector<Question4> preguntas;
    int preguntaActual;
    void mostrarPregunta(const Question4 &Question4);
    int respuestasCorrectas;
    pregunta2 *miPregunta2;


};

#endif // CLASE3_H
