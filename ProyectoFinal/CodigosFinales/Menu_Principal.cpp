/**
 * @file Menu_Principal.cpp
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Cuerpo del Menu Principal primeras interacciones del usuario con la aplicacion eduactiva
 * @brief Se Objeto de tipo MenuPrincipal da forma a nuestro menu principal y asigna funcionalidad a los botones para la navegacion en nuestra aplicacion
 * @version 1.0
 * @date 2023-11-26
 */
#include "Menu_Principal.h"     // Incluye la declaración de la clase MenuPrincipal
#include "ui_Menu_Principal.h"  // Incluye la interfaz de usuario de la clase MenuPrincipal


// Creando Objeto de tipo MenuPrincipal
MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);

    // Inicializa instancias de otras clases (Quiz_Estructuras, Quiz_Algoritmos, Leccion_Estructuras, Leccion_Algoritmos)
    Quiz_de_Estructuras = new Quiz_Estructuras(this);
    connect(ui->quizAlgoritmos, &QPushButton::clicked, this, &MenuPrincipal::mostrar_Quiz_Estructuras);

    Quiz_de_Algoritmos = new Quiz_Algoritmos(this);
    connect(ui->quizOrdenamieto, &QPushButton::clicked, this, &MenuPrincipal::mostrar_Quiz_Algoritmos);

    Leccion_de_Estructuras = new Leccion_Estructuras(this);
    connect(ui->ClaseAlgoritmos, &QPushButton::clicked, this, &MenuPrincipal::mostrar_Leccion_Estructuras);

    Leccion_de_Algoritmos = new Leccion_Algoritmos(this);
    connect(ui->ClaseOrdenamieto, &QPushButton::clicked, this, &MenuPrincipal::mostrar_Leccion_Algoritmos);

    // Conecta señales de retorno a la ventana principal
    connect(Leccion_de_Estructuras, &Leccion_Estructuras::regresar_a_Menu, this, &MenuPrincipal::Desplegar);
    connect(Leccion_de_Algoritmos, &Leccion_Algoritmos::regresar_a_Menu, this, &MenuPrincipal::Desplegar);
    connect(Quiz_de_Estructuras, &Quiz_Estructuras::regresar_a_Menu, this, &MenuPrincipal::Desplegar);
    connect(Quiz_de_Algoritmos, &Quiz_Algoritmos::regresar_a_Menu, this, &MenuPrincipal::Desplegar);
}

// Se despliega el menu principal con todas sus caracteristicas
MenuPrincipal::~MenuPrincipal()
{
    delete ui; // Libera la memoria utilizada por la interfaz de usuario de MenuPrincipal
}

// Muestra el nombre del usuario
void MenuPrincipal::setTextoEnLabel(const QString &texto)
{
    ui->iD->setText(texto); // Configura el texto en una etiqueta en MenuPrincipal
}

// Boton que se dirige al Quiz sobre Estrucuturas de Datos
void MenuPrincipal::mostrar_Quiz_Estructuras()
{
    Quiz_de_Estructuras->show();
    this->hide(); // Muestra la ventana del Quiz y oculta MenuPrincipal
}

// Boton que se dirige al Quiz sobre Algortimos de Ordenamiento
void MenuPrincipal::mostrar_Quiz_Algoritmos()
{
    Quiz_de_Algoritmos->show();
    this->hide(); // Muestra la ventana del Quiz y oculta MenuPrincipal
}

// Boton que se dirige a la Leccion sobre Estrucuturas de Datos
void MenuPrincipal::mostrar_Leccion_Estructuras()
{
    Leccion_de_Estructuras->show();
    this->hide(); // Muestra la ventana de la Leccion y oculta MenuPrincipal
}

// Boton que se dirige a la Leccion sobre Algortimos de Ordenamiento
void MenuPrincipal::mostrar_Leccion_Algoritmos()
{
    Leccion_de_Algoritmos->show();
    this->hide(); // Muestra la ventana de la Leccion y oculta MenuPrincipal
}

void MenuPrincipal::Desplegar()
{
    this->show(); // Muestra MenuPrincipal
}
