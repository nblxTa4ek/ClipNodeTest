#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "annotationbase.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<AnnotationBase>("com.clipnodetest.qml", 1, 0, "AnnotationBase");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

