<div style="text-align: justify">

# Aplicación Educativa sobre Estructuras de Datos y Algoritmos de Ordenamiento con Interfaz Gráfica en C++
## Estudiantes:
# Luis Fernando Herrera Vargas & Diego Padilla Rodríguez

## Descripción del Proyecto

Este proyecto tiene como objetivo principal desarrollar una aplicación educativa programada en C++ que permitirá a los usuarios sin conocimientos en el área y a personas con experiencia en la misma aprender sobre Estructuras de Datos y Algoritmos de Ordenamiento. La aplicación contará con una interfaz gráfica atractiva y amigable para facilitar la comprensión y el aprendizaje de estos conceptos fundamentales en informática.

## Aspectos Clave del Proyecto

### ¿Que es una librería de interfaz gráfica de usuario?

Una librería es una es un archivo que podemos incluir a nuestro programa que le agrega nuevas posibilidades al código, este archivo contiene diversas funcionalidades que vienen desarrolladas y especificadas dentro de sí por lo que nos permite utilizarlas para llevar a cabo diferentes tareas, sin tener que crear nuestras propias funciones si no que aprenderemos a utilizar las opciones que nos brindan las librerías que incluiremos a nuestro código, permitiéndonos ahorrar tiempo y aumentando las capacidades de nuestro programa, existen varios tipos de librerías como las que se encargan de entrada y salida de información, operaciones matemáticas, manejo de archivos, manejo de memoria, etc.

En nuestro caso estaremos abarcando las librerías que nos permiten crear una interfaz gráfica de usuario (GUI) para nuestro programa que hará posible que se muestre en pantalla la funcionalidad del mismo, las interfaces gráficas funcionan por medio de widgets que son una pequeña aplicación o componente que nos permite interactuar con el programa o la computadora de una forma más interactiva, algunos widgets son las ventanas emergentes, cuadros de diálogo, botones e iconos con diferentes funcionalidades.


### Investigación y Selección de Librería para el desarrollo del proyecto.

Se llevo a cabo una investigación para seleccionar la librería de interfaz gráfica adecuada.
- Qt [5]:
    - Descripción: Qt es una librería de interfaz gráfica de usuario (GUI) ampliamente utilizada en el desarrollo  de       aplicaciones C++. Es desarrollada por la empresa Qt Company y se caracteriza por ser una librería de código abierto.
        - Características y Ventajas:
        - Multiplataforma: Qt es conocida por su capacidad multiplataforma, lo que significa que 
        puedes desarrollar una aplicación una vez y ejecutarla en diferentes sistemas operativos, 
        como Windows, macOS, Linux, Android e iOS.
        - Amplia Gama de Componentes: Qt ofrece una amplia gama de componentes y widgets que facilitan 
        la creación de interfaces gráficas interactivas y atractivas.
        - Lenguaje de Programación: Qt se puede utilizar con C++ y también admite Python, JavaScript y otros lenguajes de programación.
        - Soporte Activo: Qt tiene una comunidad activa y un soporte sólido, lo que garantiza actualizaciones y correcciones de errores regulares.
        - Desarrollo Rápido: Qt permite el desarrollo rápido de aplicaciones gracias a su diseño modular y herramientas de diseño gráfico.
        - Licencia: Qt se distribuye bajo una licencia dual, lo que significa que puedes elegir entre una licencia de código abierto o una licencia comercial, dependiendo de tus necesidades.

- GTK+ (GIMP Toolkit)[8]:
    - Descripción: GTK+ es una librería de interfaz gráfica de usuario ampliamente utilizada en el desarrollo de aplicaciones C++. Es una parte integral de muchos entornos de escritorio Linux, como GNOME.
        - Características y Ventajas:
        - Aspecto Nativo: GTK+ se utiliza para crear interfaces de usuario con un aspecto nativo en sistemas operativos basados en GTK, como muchas distribuciones de Linux.
        - Sencillo y Liviano: GTK+ es conocido por su simplicidad y ligereza en comparación con algunas otras librerías de interfaz gráfica. Esto lo hace adecuado para aplicaciones de bajo consumo de recursos.
        - Personalización: GTK+ es altamente personalizable y ofrece la capacidad de adaptar la apariencia y el comportamiento de la interfaz gráfica.
        - Lenguajes de Programación: Aunque es conocido por su uso en C, GTK+ tiene enlaces disponibles para varios otros lenguajes de programación, incluyendo Python, C#, y otros.
        - Código Abierto: GTK+ es una librería de código abierto con una comunidad activa. 

- WxWidgets [10]:
    - Descripción: wxWidgets es una librería C++ que permite el desarrollo de aplicaciones multiplataforma con una interfaz de usuario nativa. Anteriormente se conocía como wxWindows.
        - Características y Ventajas:
        - Interfaz Nativa: wxWidgets se enfoca en proporcionar una interfaz de usuario nativa en diferentes sistemas operativos, lo que significa que las aplicaciones creadas con wxWidgets se verán y se comportan de manera nativa.
        - Multiplataforma: Al igual que Qt, wxWidgets es multiplataforma y es compatible con una amplia variedad de sistemas operativos.
        - Soporte para Varios Lenguajes: Aunque está basado en C++, wxWidgets admite varios lenguajes de programación, incluyendo Python, Perl y otros.
        - Amplia Compatibilidad: wxWidgets es compatible con una amplia gama de compiladores, incluyendo GCC, Visual C++, y otros.
        - Documentación: wxWidgets tiene una documentación completa y una comunidad activa que proporciona soporte.
        Licencia: wxWidgets se distribuye bajo la Licencia Pública wxWidgets (wxWindows) y se puede utilizar en proyectos de código abierto y comerciales.

Librería Seleccionada y Justificación.
- Qt:
    - Seleccionamos Qt ya que nos pareció la más indicada luego de la investigación que realizamos, las razones del porqué escogimos Qt se deben a las características que esta librería nos ofrece, una de las discutidas por el grupo fue la capacidad de funcionar en multiplataforma ya que nos pareció lo correcto elegir una librería que funcionase tanto en Windows como en Linux y además de los otros sistemas operativos que también abarca esta librería por lo que le añade un plus a nuestro programa, el detalle ser open source (Software Libre) también influyó en nuestra decisión ya que es importante para nosotros que todas las personas puedan tener acceso a este programa ya que la idea es crear un programa funcional, interactivo y luego compartirlo con cualquier persona que esté interesado en utilizarlo o estudiarlo, por razones de compilación también nos pareció la mejor opción ya que cuenta con un entorno de desarrollo propio y además este es de software libre y nos trae muchos beneficios más, como el depurado visual y la capacidad de ser un editor de código avanzado con herramientas como el revisado de sintaxis que es de gran ayuda. [4]

    - En resumen, se escogió esta librería más que todo por los detalles antes mencionados de esta manera se establece que se desarrolla el proyecto en base a la librería Qt que resulta ser de las más populares entre los desarrolladores de aplicaciones en c++.
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/Qt.png" />
</p>

### Contenido de la Aplicación Educativa

- La aplicación ofrecerá lecciones interactivas y ejercicios prácticos sobre Estructuras de Datos y Algoritmos.
- Se cubrirán conceptos como arreglos, listas enlazadas, cola, pila, árbol binario de búsqueda, diccionario, cola de prioridad y grafo.
- Se incluirán detalles y ejemplos de algoritmos de ordenamiento como Selection sort (selección), Bubble sort (burbuja), Insertion sort (inserción), Merge sort (combinación) y QuickSort(rápido) algunos vistos en clase y otros por indagación personal.

### Automatización de la Compilación y Ejecución

- Se automatizará el proceso de compilación y ejecución del programa a través de un Makefile.

### Buenas Prácticas de Desarrollo

- La implementación de la aplicación seguirá buenas prácticas relacionadas con la mantenibilidad, escalabilidad y legibilidad del código.
- Se incluirán comentarios descriptivos, la documentación Doxygen y la debida modularidad del programa para una tener una aplicación eficiente.

### Resumen General

- Este programa se basa en una aplicación interactiva que se será de tipo de educativa refiriéndose a que contará con distintos módulos o partes que tendrán un enfoque dirigido hacia el aprendizaje en nuestro caso se tratara de curiosidades y temas diversos, se abarcarán distintos temas de programación en c++ lo cual le dará dinamismo al programa y evitará que sea aburrido para el usuario, tenemos la posibilidad de agregar una sección dirigida al ocio pero no creemos que sea muy educativa por así decirlo pero de todas formas en una idea que planteamos. 

1. Sección 1 Menú de inicio.

- Se dará la bienvenida al usuario se le pedirá su nombre para que este quede registrado y así poder darle una atención personalizada. En el menú de inicio contendrá los módulos en los cuales se encontrarán las diferentes actividades que podrá realizar el usuario.

***Las secciones del 2 al 5 se planea que sean similares dependiendo del tema a tratar.***

2. Sección 2 Primera actividad:

- Ordenamiento de información se planea realizar una actividad donde el usuario tenga que ingresar alguna palabra clave al programa y este buscará la respuesta más adecuada.

3. Sección 3 Presentación de información:

- Se le brindará al usuario detalles sobre el tema que desea conocer, dando información valiosa y ejemplos para que logre entender mejor el tema a tratar.

4. Sección 4 Cuestionario: 

- Sesión de práctica, se planea fomentar el conocimiento por medio de una serie de preguntas tipo cuestionario, que serán de selección única de modo que el usuario podrá recibir retroalimentación para saber si el tema de estudio está siendo comprendido de la manera correcta.


5. Sección 5 Evaluación de lo aprendido

- Este apartado se enfocará en brindar detalles importantes sobre la materia y el cuestionario, para dar apoyo al usuario de forma que si no respondió de la manera correcta que logre entender porque no acertó con la respuesta que brindó. Con este método de aprendizaje pensamos evitar la frustración de no acertar con la respuesta y no saber en qué fallamos.

6. Sección 6 Juego:

- Zona de ocio pensamos incluir una actividad que sea meramente de ocio sin fines educativos, podría ser un simple juego del gato para brindarle al programa dinamismo y más características.


### Recursos Visuales

- A continuación, se proporcionarán imágenes y recursos visuales para complementar la propuesta del proyecto, nuestra idea es proporcionar la posible interfaz gráfica que va a tener el proyecto a desarrollar.

* Menú de Inicio
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/1.jpg" />
</p>

* Eligiendo tema de interés
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/2.jpg" />
</p>

* Presentando información
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/3.jpg" />
</p>

* Profundizando
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/4.jpg" />
</p>

* Opción de Cuestionario
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/5.1.jpg" />
</p>

* Opción de Cuestionario
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/5.2.jpg" />
</p>

* Actvidad de ocio
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/6.jpg" />
</p>

* Vista General de las ideas iniciales (Se observa como el proyecto tiene variedad de opciones)
<p align="center">
    <img src="https://github.com/DiegoPadillaRod/ie0217-proyecto/blob/main/Propuesta/Imagenes/Vista%20general%20.png" />
</p>


## Cronograma

### Propuesta (15%)

- **Semana 1-3:** Investigación, selección de librería y definición de la aplicación.
- **Fecha límite de entrega avance número 1:** 22 de octubre de 2023.

### Avance (25%)

- **Semana 4-6:** Instalación, configuración, desarrollo de la interfaz y funcionalidades básicas.
- **Fecha límite de entrega avance número 2:** 12 de noviembre de 2023.

### Final (60%) 

- **Semana 7-8:** Finalización de la interfaz, desarrollo de contenido y funcionalidades avanzadas.
- **Fecha límite de entrega final:** 28 de noviembre de 2023.

## Requisitos

- Se necesita un compilador de C++ compatible para compilar el código de la aplicación.

## Referencias

[1]	C++ UI Libraries • Memdump. (s. f.). https://philippegroarke.com/posts/2018/c++_ui_solutions/

[2]	Library. GitHub. https://github.com/wxWidgets/wxWidgets

[3]	Oliveira, M. (2022, 10 enero). The 7 best C++ Frameworks for creating graphical Interfaces. Terminal Root. https://terminalroot.com/the-7-best-cpp-frameworks-for-creating-graphical-interfaces/

[4]	QT Creator/es - QT Wiki. (s. f.). https://wiki.qt.io/Qt_Creator/es

[5]	QT for Beginners - QT Wiki. (s. f.). https://wiki.qt.io/Qt_for_Beginners

[6]	QT. GitHub. https://github.com/qt

[7]	Team, G. (s. f.). The GTK Project - a free and open-source cross-platform widget toolkit. The GTK Team. https://www.gtk.org/

[8]	What is QT Framework, why to use it, and how? (2023, 16 octubre). https://lembergsolutions.com/blog/why-use-qt-framework#:~:text=Qt%20is%20a%20cross%2Dplatform%20framework%20that%20is%20used%20for,Qt%20Design%20Studio%2C%20and%20others.

[9]	wxWidgets. (s. f.). GitHub – WxWidgets/WxWidgets: Cross-Platform C++ GUI. https://github.com/wxWidgets/wxWidgets

[10] WXWidgets: Documentation. (s. f.). https://docs.wxwidgets.org/3.2/


## Licencia

Este proyecto se distribuye bajo la [Licencia MIT](LICENSE).

</div>