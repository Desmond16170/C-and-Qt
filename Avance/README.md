<div style="text-align: justify">

# Aplicación Educativa sobre Estructuras de Datos y Algoritmos de Ordenamiento con Interfaz Gráfica en C++
## Estudiantes:
# Luis Fernando Herrera Vargas & Diego Padilla Rodríguez

# Avance

## Informe Intermedio

Conforme el proyecto esta avanzando nos hemos presentado diversos retos, el más evidente es aprender algo desde cero ya que no estamos familiarizados con interfaces de usuario en c++ , por lo tanto se debe estar en un constante investigación de las posibilidades una librería como Qtnos ofrece, la resolución de probemos y ejemplos puntuales del funcionamiento de  un programa de c++ usando Qt provienen de la propia documentación de esta librería que ofrece distintos ejemplos interactivos que nos permite conocer y agregar más funciones a nuestro programa también nos hemos apoyado en la comunidad de programadores que utilizan esta librería ya que más experimentados y comparten sus conocimientos en la web.

## Desafíos encontrados:

Errores en sintaxis, inicializar clases que nos permitieran crear métodos que luego íbamos a utilizar nos resulto confuso y complicado en su momento, después de una investigación se logró obtener la forma correcta de implementar bien las clases, corrigiendo la sintaxis ya se pudo hacer uso de la clase para ir construyendo nuestra interfaz.

Realizando el quiz: Como la idea era que el usuario se desplace por el quiz con botones de anterior y siguiente, para desplegar la pregunta correspondiente se tuve un error en el cual el programa entraba en un ciclo o mostraba las preguntas aleatoriamente.

Manejo de ventanas:  El cierre repentino de ventanas fue algo que nos generó mucha confusión ya que el programa mostraba la información y automáticamente se cerraba. 

Contadores: Se implemento un contador para que el usuario pudiera avanzar en las preguntas, esto genero diversos conflictos ya que no estamos muy familiarizados con este tipo de problemas, pero indagando se llegó a una solución. 

## Soluciones adoptadas:

Para los errores de sintaxis basto con una investigación en la documentación de la librería dándonos cuenta de que obviamente es la misma sintaxis que en c++ pero al ser una librería dirigida hacia las GUI tiene algunos detalles a tomar en cuenta. 

Para la realización del quiz se genero un contador que luego de implementarlo de manera correcta, el quiz funciono de la forma adecuada según nuestras necesidades.

Para el manejo de mantenas se opto por botones como en del volver al menu que nos permiten mantener estatica la pantalla hasta que el usuario decida salir de la ventana actual.

Para el contador se realizo una extensa investigación en stackoverflow, git y en la documentación de Qt luego de implementar los nuevos conocimientos se logro realizar con exito el contador que nos permite pasar de pregunta con un boton de siguiente y devolvernos con un boton de anterior.

</div>
