QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += network
QT += sql
#QMAKE_USE += mysql
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += D:\workspace\vcpkg-master\vcpkg-master\packages\tesseract_x64-windows\include
LIBS += D:\workspace\vcpkg-master\vcpkg-master\packages\tesseract_x64-windows\lib\tesseract55.lib

INCLUDEPATH += D:\workspace\vcpkg-master\vcpkg-master\packages\leptonica_x64-windows\include
LIBS += D:\workspace\vcpkg-master\vcpkg-master\packages\leptonica_x64-windows\lib\leptonica-1.84.1.lib



SOURCES += \
    apimanager.cpp \
    database.cpp \
    historymanager.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    screenshottool.cpp \
    settingswindow.cpp \
    subtitlewindow.cpp \
    translatewindow.cpp \
    usermanager.cpp

HEADERS += \
    apimanager.h \
    database.h \
    historymanager.h \
    loginwindow.h \
    mainwindow.h \
    screenshottool.h \
    settingswindow.h \
    subtitlewindow.h \
    translatewindow.h \
    usermanager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QMAKE_PROJECT_DEPTH = 0
