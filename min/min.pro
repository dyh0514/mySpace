QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


QMAKE_PROJECT_DEPTH = 0

#*****

#***
# Include paths for Tesseract and Leptonica
INCLUDEPATH += D:/project/vcpkg/packages/tesseract_x64-windows/include
INCLUDEPATH += D:/project/vcpkg/packages/leptonica_x64-windows/include

# Library paths for Tesseract and Leptonica
LIBS += -L"D:/project/vcpkg/packages/tesseract_x64-windows/lib" -ltesseract54
LIBS += -L"D:/project/vcpkg/packages/leptonica_x64-windows/lib" -lleptonica-1.84.1

# Ensure you include Qt directories
INCLUDEPATH += D:/Qt/6.7.2/msvc2019_64/include
LIBS += -L"D:/Qt/6.7.2/msvc2019_64/lib" -lQt6Core -lQt6Gui -lQt6Widgets
