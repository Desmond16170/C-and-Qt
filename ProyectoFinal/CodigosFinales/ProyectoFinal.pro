QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    Clase_Educativa_Alg.cpp \
    Clase_Educativa_Est.cpp \
    Menu_Principal.cpp \
    Quiz_Algoritmos.cpp \
    Quiz_Desde_ClaseAlg.cpp \
    Quiz_Desde_ClaseEst.cpp \
    Quiz_Estructuras.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Clase_Educativa_Alg.h \
    Clase_Educativa_Est.h \
    Menu_Principal.h \
    Quiz_Algoritmos.h \
    Quiz_Desde_ClaseAlg.h \
    Quiz_Desde_ClaseEst.h \
    Quiz_Estructuras.h \
    mainwindow.h

FORMS += \
    Clase_Educativa_Alg.ui \
    Clase_Educativa_Est.ui \
    Menu_Principal.ui \
    Quiz_Algoritmos.ui \
    Quiz_Desde_ClaseAlg.ui \
    Quiz_Desde_ClaseEst.ui \
    Quiz_Estructuras.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

DISTFILES += \
    images/Bubblesort.png \
    images/Clase.png \
    images/Menu.png \
    images/Merge-Sort-Algorithm.png \
    images/Respuestas.png \
    images/Siguiente.png \
    images/diccionario.png \
    images/image002.jpg \
    images/image002.png \
    images/image003.png \
    images/image005.jpg \
    images/image007.png \
    images/image009.png \
    images/image011.png \
    images/image013.png \
    images/image015.png \
    images/image017.jpg \
    images/image019.png \
    images/insertionsort.png \
    images/orden.png \
    images/quick-sort-part-1.png \
    images/quick-sort-part-2.png \
    images/selection-short.png

# Configuración del ícono de la aplicación para Windows
win32: RC_ICONS += images/appicon.ico

