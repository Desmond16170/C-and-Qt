QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clase1.cpp \
    clase3.cpp \
    main.cpp \
    mainwindow.cpp \
    menuprincipal.cpp \
    pregunta1.cpp \
    pregunta2.cpp

HEADERS += \
    Question.h \
    clase1.h \
    clase3.h \
    mainwindow.h \
    menuprincipal.h \
    pregunta1.h \
    pregunta2.h

FORMS += \
    clase1.ui \
    clase3.ui \
    mainwindow.ui \
    menuprincipal.ui \
    pregunta1.ui \
    pregunta2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc


