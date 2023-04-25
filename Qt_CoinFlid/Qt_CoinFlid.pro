QT       += core gui multimedia
QT += multimediawidgets
#multimedia
QT += core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose_level_scene.cpp \
    dataconfig.cpp \
    main.cpp \
    mainwindow.cpp \
    mycoin_button.cpp \
    mypushbutton.cpp \
    mypushbutton2.cpp \
    play_scene.cpp

HEADERS += \
    choose_level_scene.h \
    dataconfig.h \
    mainwindow.h \
    mycoin_button.h \
    mypushbutton.h \
    mypushbutton2.h \
    play_scene.h

FORMS += \
    choose_level_scene.ui \
    mainwindow.ui \
    mycoin_button.ui \
    mypushbutton.ui \
    mypushbutton2.ui \
    play_scene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
