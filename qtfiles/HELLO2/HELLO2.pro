QT += core  gui

greaterThan(QT_MAJOR_VERSION,4) QT+= widgets

SOURCES += \
    hellodialog1.cpp \
    hellodialog2.cpp \
    main.cpp
QMAKE_PROJECT_DEPTH = 0

FORMS += \
    hellodialog.ui \
    hellodialog2.ui

HEADERS += \
    hellodialog1.h \
    hellodialog2.h
