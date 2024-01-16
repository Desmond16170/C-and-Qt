/**
 * @file Clase_Educativa_Est.cpp
 * @author Luis Fernando Herrera Vargas & Diego Padilla Rodríguez
 * @title Cuerpo de Leccion Educativa sobre Algoritmos de Ordenamiento
 * @brief Se crea el Objeto de tipo Leccion_Estructuras que contiene toda la estrucutura de la ventana, que presentara la informacion correspondiente a la Leccion sobre Estructuras de Datos
 * @version 1.0
 * @date 2023-11-26
 */
#include "Clase_Educativa_Est.h" // Incluye la declaración de la clase
#include "ui_Clase_Educativa_Est.h" // Incluye la interfaz de usuario
#include <QMessageBox> // Incluye la clase para mostrar mensajes de información

// Creando Objeto de tipo Leccion_Estructuras
Leccion_Estructuras::Leccion_Estructuras(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clase_Estructuras),
    paginaActual(0),
    Verificando(0),
    Quiz_Estructuras(new Quiz_Desde_Estructuras(this))
{
    // Aca se definieron los paginas a mostras sobre los diferentes "subtemas" de materia de leccion
    // La pagina tendra un plantilla establecida, la cual se diseño en la interfaz de usuario
    ui->setupUi(this);
    texto.append({ "Estructuras de Datos", // Titulo
                      {"¿Qué son?\n" // Contenido
                       "\n"
                       "Las estructuras de datos en C++ son diferentes métodos de organización de información, "
                       "nos permiten almacenar y manejar datos de forma ordenada y eficiente, es importante tener "
                       "en cuenta que la estructura que vayamos a utilizar en nuestro programa depende de "
                       "las necesidades de este. "
                       "A continuación, veremos los tipos y funciones de las diferentes estructuras de datos."},3 ,
                      "Estructuras"}); // Imagen

    texto.append({ "Estructuras de Datos",
                      {"Tipos de estructuras de datos:\n"
                       "\n"
                       "Lineales: \n"
                       "Son aquellas donde los elementos contenidos ocupan "
                       "lugares sucesivos, por lo tanto, cada elemento "
                       "tiene un único sucesor y a su vez un único predecesor, "
                       "de esta manera sabemos que los elementos están ubicados "
                       "uno al lado del otro relacionados linealmente."},3 ,
                      "Estructuras"});

    texto.append({ "Estructuras de Datos",
                      {"Tipos de Estructuras Lineales: \n"
                       "\n"
                       "Estáticas:\n"
                       "Es una característica atribuida al manejo de la memoria "
                       "que hará este tipo de estructura de datos lineal, "
                       "se refiere a que el espacio que ocupa en la memoria no puede ser modificado "
                       "una vez se haya ejecutado el programa por así decirlo se define la "
                       "cantidad de elementos antes de ejecutar el programa y "
                       "esta no cambiará una vez de inicio el programa. "},3 ,
                      "Estructuras"});

    texto.append({ "Estructuras de Datos",
                      {"Tipos de Estructuras Lineales: \n"
                       "\n"
                       "Dinámicas: \n"
                       "De igual forma esta característica se relaciona con el manejo de la memoria que hará este "
                       "tipo de estructura de datos lineal, en este caso "
                       "el especio designado en la memoria puede "
                       "ir cambiando una vez se ejecute el programa, por ejemplo, "
                       "si en el programa se decide "
                       "quitar o poner más elementos dentro de una estructura "
                       " una vez el programa haya iniciado"
                       "es posible por medio una estructura de datos dinámica."},3 ,
                      "Estructuras"});

    texto.append({ "Estructuras de Datos",
                      {"Tipos de estructuras de datos:\n"
                       "\n"
                       "No Lineales:\n"
                       "Son aquellas donde los elementos contenidos están "
                       "enlazados, sabiendo esto tenemos que "
                       "cada elemento puede tener varios sucesores como varios predecesores a la vez, por lo "
                       "tanto, cada elemento tiene la capacidad de estar conectado a otro componente, estas a su "
                       "vez son dinámicas."
                       },3 ,
                      "Estructuras"});

    texto.append({ "Arreglos (Arrays): son Lineales y Estáticos",
                      {"Descripción: \n"
                       "Almacenan elementos del mismo tipo en una secuencia contigua de memoria. "
                       "Permiten acceder rápidamente a cualquier elemento mediante su índice.\n"
                       "\n"
                       "Uso típico: \n"
                       "Almacenamiento eficiente de datos homogéneos."
                       },3 ,
                      "Arreglos"});

    texto.append({ "Listas Enlazadas (Linked Lists): son Lineales y Dinámicas",
                      {"Descripción:: \n"
                       "Cada elemento contiene un enlace (o referencia) "
                       "al siguiente elemento en la secuencia. Esto facilita la inserción y "
                       "eliminación de elementos en cualquier posición.\n"
                       "\n"
                       "Uso típico: \n"
                       "Cuando la frecuencia de inserciones y eliminaciones es alta."},3 ,
                      "Listas"});

    texto.append({ "Pilas (Stacks): son Lineales y Dinámicas",
                      {"Descripción: \n"
                       "Siguen el principio de último en entrar, primero en salir "
                       "(LIFO). Los elementos se añaden o eliminan solo desde un extremo (la cima de la pila).\n"
                       "\n"
                       "Uso típico: \n"
                       "Seguimiento de llamadas a funciones, "
                       "revertir de elementos sacar de una pila y ubicarlos en otra."
                      },3 ,
                      "Pilas"});

    texto.append({ "Pilas (Stacks)",
                      {"Operaciones:\n"
                       "Push: agrega un elemento a la parte superior de una pila.\n"
                       "\n"
                       "Pop: elimina un elemento de la parte superior de una pila.\n"
                       "\n"
                       "IsEmpty: comprueba si la pila está vacía.\n"
                       "\n"
                       "IsFull: comprueba si la pila está llena.\n"
                       "\n"
                       "Peek: obtiene el valor del elemento superior sin eliminarlo."
                      },3 ,
                      "Pilas_Ope"});

    texto.append({ "Colas (Queues): son Lineales y Dinámicas",
                      {"Descripción: \n"
                       "Siguen el principio de ""primero en entrar, primero en salir"" (FIFO). "
                       "Los elementos se añaden al final de la cola y se eliminan desde el frente.\n"
                       "\n"
                       "Uso típico: \n"
                       "Gestión de tareas en un orden secuencial."
                      },3 ,
                      "Colas"});

    texto.append({ "Colas (Queues)",
                      {"Operaciones:\n"
                      "Enqueue: agrega un elemento al final de la cola.\n"
                      "\n"
                      "Dequeue: elimina un elemento del frente de la cola.\n"
                      "\n"
                      "IsEmpty: comprueba si la cola está vacía.\n"
                      "\n"
                      "IsFull: comprueba si la cola está llena.\n"
                      "\n"
                      "Peek: obtiene el valor del frente de la cola sin eliminarlo."
                      },3 ,
                      "Colas"});

    texto.append({ "Árboles (Tree): son No Lineales",
                      {"Descripción: \n"
                       "Los árboles son estructuras jerárquicas que "
                        "consisten en nodos conectados por aristas. Cada nodo "
                        "tiene un nodo padre (excepto el nodo superior, llamado raíz) "
                        "y cero o más nodos hijos.\n"
                        "\n"
                        "Uso Típico: \n"
                        "Almacenar información jerárquica, como la estructura de un sistema de archivos, "
                        "la organización de una empresa o las relaciones familiares."
                      },3 ,
                      "Arbol"});

    texto.append({ "Grafos (Graphs): son No Lineales",
                      {"Descripción:\n"
                       "Los grafos son estructuras que consisten en nodos "
                       "(nodos/vértices) y conexiones entre esos nodos (aristas/edges). "
                       "Pueden ser dirigidos (las aristas tienen una dirección) o no dirigidos, "
                       "son capaces de relacionar y conectar elementos entre sí.\n"
                       "\n"
                       "Uso Típico: \n"
                       "Modelar relaciones complejas entre entidades, como redes sociales, mapas de carreteras, "
                       "relaciones de dependencia en sistemas, etc."
                      },3 ,
                      "Grafo"});

    texto.append({ "Colas de Prioridad (Priority Queues): son No Lineales",
                      {"Descripción:\n"
                       "Similar a una cola ya que sigue el principio de FIFO, "
                       "pero cada elemento tiene asignada una prioridad y se accede o "
                       "elimina el elemento dependiendo de su prioridad.\n"
                       "\n"
                       "Uso típico: \n"
                       "Útil en algoritmos que requieren acceso prioritario a los datos."
                      },3 ,
                      "Colas_Pri"});


    texto.append({ 	"Arbol Binario de Búsqueda (BST): son No Lineales",
                      {"Descripción: \n"
                       "Es un tipo de árbol binario en el que cada nodo tiene, "
                       "como máximo, dos hijos. La propiedad clave es que, para cada nodo, "
                       "todos los nodos en su subárbol izquierdo tienen claves menores "
                       "y todos los nodos en su subárbol derecho tienen claves mayores.\n"
                       "\n"
                       "Uso típico: \n"
                       "Almacenar información donde se necesita recuperar valores "
                       "rápidamente a través de una clave única, como la implementación de tablas de "
                       "símbolos en compiladores, almacenamiento de configuraciones, etc."
                      },3 ,
                      "Arbol_Bin"});

    texto.append({ 	"Diccionario(Dictionary): son No Lineales",
                      {"Descripción: Un diccionario es una estructura de datos que almacena pares "
                       "clave-valor, donde cada clave es única y "
                       "está asociada a un valor específico. "
                       "Permite la búsqueda eficiente de valores "
                       "mediante la clave correspondiente.\n"
                       "\n"
                       "Uso Típico: \n"
                       "Almacenar información donde se necesita recuperar valores "
                       "rápidamente a través de una clave única,"
                       "como la implementación de tablas de símbolos en "
                       "compiladores, almacenamiento de configuraciones, etc."
                      },3 ,
                      "diccionario"});

    // Mostrando las paginas en orden
    mostrarPagina(texto[paginaActual]);

    // Conectando botones a clases
    connect(ui->BotonSiguiente, &QPushButton::clicked, this, &Leccion_Estructuras::mostrarSiguientePagina);
    connect(ui->BotonAnterior, &QPushButton::clicked, this, &::Leccion_Estructuras::mostrarPaginaAnterior);
    connect(ui->irQuiz1, &QPushButton::clicked, this, &Leccion_Estructuras::irQuiz1);
    connect(ui->botonVolver, &QPushButton::clicked, this, &::Leccion_Estructuras::volver_a_Menu);
    connect(Quiz_Estructuras, &Quiz_Desde_Estructuras::regreso_a_Leccion, this, &Leccion_Estructuras::volviendo_a_Leccion);

    // Mostrar la primera pagina
    mostrarPagina(texto[paginaActual]);
}

// Metodo para mostrar cada pagina en la interfaz, nos permite saber si algo salio mal
void Leccion_Estructuras::mostrarPagina(const Contenido_Leccion1 &Contenido_Leccion1) {
    ui->questionLabel->setText(Contenido_Leccion1.Info); // Título del tema
    ui->texto->setText(Contenido_Leccion1.Orden[0]); // Información a mostrar

    // Brindandelo la direccion y cargando las imagenes que se utilizaran en cada tema
    QString imagePath = ":/images/images/" +  Contenido_Leccion1.Imagen_del_Tema;
    QPixmap image(imagePath);

    if (!image.isNull()) {
        ui->imagen->setPixmap(image);
        ui->imagen->setScaledContents(true); // Escalar la imagen según el tamaño del QLabel
    } else {
        // Manejar el caso en que la imagen no se pueda cargar
        QMessageBox::warning(this, "Error de Carga", "No se pudo cargar la imagen: " + imagePath);
    }
}

// Maneja el regreso desde a la leccion del quiz
void Leccion_Estructuras::volviendo_a_Leccion() {
    this->show(); // Muestra la ventana de la leccion
}

// Configura el texto en un QLabel de la interfaz
void Leccion_Estructuras::setTextoEnLabel(const QString &texto) {
    ui->iD->setText(texto);
}

// Realiza la accion del boton que muestra la pagina siguiente
void Leccion_Estructuras::mostrarSiguientePagina() {
    int respuestaSeleccionada = -1;

    // Verificar si la pagina esta bien creada
    if (paginaActual < texto.size() && respuestaSeleccionada == texto[paginaActual].Validacion) {
        Verificando++;
    }

    // Accede a la siguiente pagina solo si aún hay mas materia por mostrar
    if (paginaActual + 1 < texto.size()) {
        paginaActual++;
        mostrarPagina(texto[paginaActual]);
    } else {
        // No sucede nada
    }
}

// Realiza la accion del boton que muestra la pagina anterior
void Leccion_Estructuras::mostrarPaginaAnterior() {
    if (paginaActual > 0) {
        paginaActual--;
        mostrarPagina(texto[paginaActual]);
    }
}

// Realiza la accion del boton "Quiz"
void Leccion_Estructuras::irQuiz1() {
    Quiz_Estructuras->show(); // Muestra la ventana del quiz
    this->close(); // cierra esta ventana
}

// Destructor de la clase Leccion_Estructura
Leccion_Estructuras::~Leccion_Estructuras() {
    delete ui;
}

// Realiza la accion del boton para volver al menu principal
void Leccion_Estructuras::volver_a_Menu() {
    emit regresar_a_Menu();
    this->hide(); // oculta esta ventana
}

// Muestra la ventana de la leccion educativa
void Leccion_Estructuras::mostrarLeccion_Estructuras() {
    this->show();
}
