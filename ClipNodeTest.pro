TEMPLATE = app

# Default rules for deployment.
include(deployment.pri)

QT += qml quick quick-private core-private gui-private qml-private
CONFIG += c++11

SOURCES += main.cpp \
    annotationbase.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =



HEADERS += \
    annotationbase.h

