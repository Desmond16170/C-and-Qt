#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QVector>

struct Question {

    QString text;
    QVector<QString> options;
    int correctAnswer; // índice de la respuesta correcta
};

#endif // QUESTION_H
