#ifndef PREGUNTA2_H
#define PREGUNTA2_H

#include <QMainWindow>
#include <QString>
#include <QVector>

// Estructura para representar una pregunta
struct Question2 {
    QString text;
    QVector<QString> options;
    int correctAnswer; // índice de la respuesta correcta
};

namespace Ui {
class pregunta2;
}

class pregunta2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit pregunta2(QWidget *parent = nullptr);
    ~pregunta2();
    void reiniciarQuiz();
    void setTextoEnLabel(const QString &texto);


signals:
    void quizTerminado();
    void regresarAMainWindow();
private slots:
    void mostrarSiguientePregunta();
    void mostrarPreguntaAnterior();
    void mostrarRespuestas ();
    void volverAMainWindow();

private:
    Ui::pregunta2 *ui;
    QVector<Question2> preguntas;
    int preguntaActual;
    void mostrarPregunta(const Question2 &question);
    int respuestasCorrectas;


};

#endif // pregunta2_H
