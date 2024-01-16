/**
 * @file Clase_Educativa_Alg.cpp
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Cuerpo de la Leccion Educativa sobre Algoritmos de Ordenamiento
 * @brief Crea el objeto de tipo Leccion_Algoritmos que contiene toda la estrucutura de la ventana, que presentara la informacion correspondiente a la Leccion sobre Algoritmos de Ordenamiento
 * @version 1.0
 * @date 2023-11-26
 */
#include "Clase_Educativa_Alg.h"    // Incluye la declaración de la clase
#include "ui_Clase_Educativa_Alg.h" // Incluye la interfaz de usuario
#include <QMessageBox>              // Incluye la clase para mostrar mensajes de información

// Creando Objeto de tipo Leccion_Algoritmos
Leccion_Algoritmos::Leccion_Algoritmos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clase_Algoritmos),
    Pagina_Actual(0),
    Verificacion(0),
    Quiz_algoritmos(new Quiz_Desde_Algoritmos(this))
{
    // Configuración de la interfaz de usuario
    ui->setupUi(this);

    // Aca se definieron los paginas a mostras sobre los diferentes "subtemas" de materia de leccion
    // La pagina tendra un plantilla establecida, la cual se diseño en la interfaz de usuario
    texto.append({ "Algoritmos de Ordenamiento", // Titulo de la pagina
                    {"¿Qué son? \n" //Contenido
                    "\n"
                    "Se utiliza para reorganizar una matriz o lista de elementos determinada "
                    "según un operador de comparación de los elementos. "
                    "El operador de comparación se utiliza para decidir el nuevo orden de los "
                    "elementos en la estructura de datos respectiva, estos algoritmos se basan en "
                    "instrucciones lógicas y matemáticas que organizarán una serie de datos en un "
                    "orden especifico cumpliendo un rol esencial en el mundo de la programación ya que "
                    "permiten manipular los datos de manera eficiente."},
                    2 ,
                    "orden"}); // Imagen

    texto.append({ "Algoritmos de Ordenamiento",
                    {"Complejidad: \n"
                    "La complejidad de los algoritmos se mide usando la notación Big-O "
                    "que nos indica la cantidad de operaciones que un algoritmo realizará, "
                    "donde “n” será el tamaño del conjunto de datos que se desea ordenar. "},
                    1,
                    "Complejidad" });

    texto.append({ "Burbuja (Bubble Sort)",
                    {"Que es?\n"
                    "El algoritmo de ordenamiento de burbuja "
                    "compara elementos adyacentes en una lista y los intercambia "
                    "si están en el orden incorrecto. "
                    "Este proceso se repite hasta que toda la lista esté ordenada.\n"
                    "\n"
                    "Detalles Clave: \n"
                    "Compara e intercambia elementos adyacentes hasta que la lista esté ordenada."},0,
                   "Bubblesort" });

    texto.append({ "Burbuja (Bubble Sort)",
                   {"Análisis de su complejidad:\n"
                   "\n"
                   "Complejidad de tiempo:\n"
                   "O(n) en el mejor caso\n"
                   "\n"
                   "O(n^2) en un caso promedio\n"
                   "\n"
                   "O(n^2) en el peor caso\n"
                   "\n"
                   "Complejidad de Espacio:\n"
                   "O(1)"},3 ,
                    "Bubblesort"});

    texto.append({ "Inserción (Insertion Sort)",
                    {"Que es?\n"
                    "El algoritmo de ordenamiento por inserción construye una secuencia ordenada uno a uno, "
                    "insertando cada elemento en su posición correcta. Es eficiente para listas pequeñas.\n"
                   "\n"
                    "Detalles Clave:\n"
                    "Construye una secuencia ordenada uno a uno, insertando elementos en su posición correcta."},3 ,
                    "insertionsort"});

    texto.append({ "Inserción (Insertion Sort)",
                    { "Análisis de su complejidad:\n"
                    "\n"
                    "Complejidad de tiempo:\n"
                    "O(n) en el mejor caso\n"
                    "\n"
                    "O(n^2) en un caso promedio\n"
                    "\n"
                    "O(n^2) en el peor caso\n"
                    "\n"
                    "Complejidad de Espacio:\n"
                    "O(1)"},3 ,
                    "insertionsort"});

    texto.append({ "Selección (Selection Sort)",
                    {"Que es?\n"
                    "El algoritmo de ordenamiento por selección encuentra repetidamente el elemento mínimo de la lista "
                    "y lo intercambia con el primer elemento no ordenado. Este proceso se repite hasta que toda la lista esté ordenada.\n"
                    "\n"
                    "Detalles Clave\n"
                    "Encuentra el elemento mínimo de la lista y lo intercambia con el primer elemento"
                    },3 ,
                    "selection-short"});

    texto.append({ "Selección (Selection Sort)",
                    {"Análisis de su complejidad:\n"
                    "\n"
                    "Complejidad de tiempo:\n"
                    "O(n^2) en el mejor caso\n"
                    "\n"
                    "O(n^2) en un caso promedio\n"
                    "\n"
                    "O(n^2) en el peor caso\n"
                    "\n"
                    "Complejidad de Espacio:\n"
                    "O(1)"},3 ,
                    "selection-short"});

    texto.append({ "Fusión (Merge Sort)",
                    {"Que es?\n"
                    "El algoritmo de ordenamiento por fusión divide la lista en mitades, "
                    "ordena cada mitad de forma recursiva y luego combina las mitades ordenadas para obtener "
                    "la lista final ordenada.\n"
                    "\n"
                    "Detalles Clave:\n"
                    "Divide la lista en mitades, ordena cada mitad y luego combina las mitades ordenadas."},3 ,
                    "Merge-Sort-Algorithm"});

    texto.append({ "Fusión (Merge Sort)",
                    {"Análisis de su complejidad:\n"
                    "\n"
                    "Complejidad de tiempo:\n"
                    "O(n*log(n)) en el mejor caso\n"
                    "\n"
                    "O(n*log(n)) en un caso promedio\n"
                    "\n"
                    "O(n*log(n)) en el peor caso\n"
                    "\n"
                    "Complejidad de Espacio:\n"
                    "O(n)"},3 ,
                    "Merge-Sort-Algorithm"});


    texto.append({ "Rápido (Quick Sort)",
                    {"Que es?\n"
                    "El algoritmo de ordenamiento rápido selecciona un elemento llamado  ""pivote"" y reorganiza la "
                    "lista de manera que los elementos menores que el pivote estén a su izquierda y "
                    "los mayores estén a su derecha. Este proceso se repite para las sublistas resultantes.\n"
                    "\n"
                    "Detalles Clave\n"
                    "Selecciona un elemento como " "pivote"" y particiona la lista alrededor del pivote."},3 ,
                    "quick-sort-part-1"});

    texto.append({ "Rápido (Quick Sort)",
                    {"Análisis de su complejidad:\n"
                    "\n"
                    "Complejidad de tiempo:\n"
                    "O(n*log(n)) en el mejor caso\n"
                    "\n"
                    "O(n*log(n)) en un caso promedio\n"
                    "\n"
                    "O(n^2) en el peor caso\n"
                    "\n"
                    "Complejidad de Espacio:\n"
                    "O(n*log(n))"},3 ,
                    "quick-sort-part-2"});

    // Mostrando las paginas en orden
    mostrarInformacion(texto[Pagina_Actual]);

    // Conectando botones a clases
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &Leccion_Algoritmos::mostrarSiguientePagina);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &::Leccion_Algoritmos::mostrarPaginaAnterior);
    connect(ui->irQuiz1, &QPushButton::clicked, this, &::Leccion_Algoritmos::mostrarQuiz2);
    connect(ui->botonVolver, &QPushButton::clicked, this, &::Leccion_Algoritmos::volver_a_Menu);
    connect(Quiz_algoritmos, &Quiz_Desde_Algoritmos::regreso_a_Leccion, this, &::Leccion_Algoritmos::volviendo_a_Leccion);
}

// Metodo para establecer el texto en una etiqueta
void Leccion_Algoritmos::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}

// Metodo para mostrar cada pagina en la interfaz, nos permite saber si algo salio mal
void Leccion_Algoritmos::mostrarInformacion(const Contenido_Leccion2 &Contenido_Leccion2) {
    ui->questionLabel->setText(Contenido_Leccion2.Info);
    ui->texto->setText(Contenido_Leccion2.Orden[0]);

    // Brindandelo la direccion y cargando las imagenes que se utilizaran en cada tema
    QString imagePath = ":/images/images/" +  Contenido_Leccion2.Imagen_del_Tema;
    QPixmap image(imagePath);
    qDebug() << "Intentando cargar la imagen desde: " << imagePath;

    if (!image.isNull()) {
        ui->imagen->setPixmap(image);
        ui->imagen->setScaledContents(true); // Escalar la imagen según el tamaño del QLabel
    } else {
        // Manejar el caso en que la imagen no se pueda cargar
        QMessageBox::warning(this, "Error de Carga", "No se pudo cargar la imagen: " + imagePath);
    }
}

// Función para manejar el regreso a la clase desde el quiz
void Leccion_Algoritmos::volviendo_a_Leccion() {
    this->show();
}

// Función para reiniciar el quiz, cada vez que el programa cierra la nota empieza en cero de nuevo
void Leccion_Algoritmos::reiniciarQuiz() {
    Pagina_Actual = 0;
    Verificacion = 0;
    mostrarInformacion(texto[Pagina_Actual]);
}

// Realiza la accion del boton que muestra la pagina siguiente
void Leccion_Algoritmos::mostrarSiguientePagina() {
    int respuestaSeleccionada = -1;

    // Verificar si la pagina esta bien creada
    if (Pagina_Actual < texto.size() && respuestaSeleccionada == texto[Pagina_Actual].Validacion) {
        Verificacion++;
    }

    // Accede a la siguiente pagina solo si aún hay mas materia por mostrar
    if (Pagina_Actual + 1 < texto.size()) {
        Pagina_Actual++;
        mostrarInformacion(texto[Pagina_Actual]);
    } else {
        // No sucede nada
    }
}

// Realiza la accion del boton que muestra la pagina anterior
void Leccion_Algoritmos::mostrarPaginaAnterior() {
    if (Pagina_Actual > 0) {
        Pagina_Actual--;
        mostrarInformacion(texto[Pagina_Actual]);
    }
}

// Realiza la accion del boton "Quiz"
void Leccion_Algoritmos::mostrarQuiz2() {
    Quiz_algoritmos->show(); // Muestra la ventana del quiz
    this->close(); // cierra esta ventana
}

// Destructor de la clase Leccion_Algoritmos
Leccion_Algoritmos::~Leccion_Algoritmos() {
    delete ui;
}

// Realiza la accion del boton para volver al menu principal
void Leccion_Algoritmos::volver_a_Menu() {
    emit regresar_a_Menu();
    this->hide(); // oculta esta ventana
}


// Muestra la ventana de la leccion educativa
void Leccion_Algoritmos::mostrarLeccion_Algoritmos() {
    this->show();
}
