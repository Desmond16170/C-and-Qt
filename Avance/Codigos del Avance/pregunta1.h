#ifndef PREGUNTA1_H
#define PREGUNTA1_H

#include <QMainWindow>
#include <QString>
#include <QVector>

// Estructura para representar una pregunta
struct Question {
    QString text;
    QVector<QString> options;
    int correctAnswer; // índice de la respuesta correcta
};

namespace Ui {
class pregunta1;
}

class pregunta1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit pregunta1(QWidget *parent = nullptr);
    ~pregunta1();
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
    Ui::pregunta1 *ui;
    QVector<Question> preguntas;
    int preguntaActual;
    void mostrarPregunta(const Question &question);
    int respuestasCorrectas;


};

#endif // PREGUNTA1_H
