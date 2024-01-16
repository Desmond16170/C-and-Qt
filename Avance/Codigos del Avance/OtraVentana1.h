// OtraVentana1.h

#ifndef OTRAVENTANA1_H
#define OTRAVENTANA1_H

#include <QMainWindow>

namespace Ui {
class OtraVentana1;
}

class OtraVentana1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtraVentana1(QWidget *parent = nullptr);
    ~OtraVentana1();

private:
    Ui::OtraVentana1 *ui;
};

#endif // OtraVentana1_H
