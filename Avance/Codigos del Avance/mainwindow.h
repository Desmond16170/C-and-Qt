#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menuprincipal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void mostrarMainWindow();


private slots:
    void on_botonEnter_clicked();



private:
    Ui::MainWindow *ui;
    MenuPrincipal *menu; // Instancia de la segunda ventana

};
#endif // MAINWINDOW_H
