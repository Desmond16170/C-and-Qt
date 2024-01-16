#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "pregunta1.h"
#include "pregunta2.h"
#include "clase1.h"
#include "clase3.h"
#include <QMainWindow>

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuPrincipal(QWidget *parent = nullptr);
    ~MenuPrincipal();
    void setTextoEnLabel(const QString &texto);

private slots: // Usa esto si estás en Qt 4
    void mostrarPregunta1();
    void mostrarPregunta2();
    void mostrarClase1();
    void mostrarClase3();


private:
    Ui::MenuPrincipal *ui;
    pregunta1 *miPregunta1;
    pregunta2 *miPregunta2;
    Clase1 *miClase1;
    Clase3 *miClase3;
};

#endif // MENUPRINCIPAL_H
