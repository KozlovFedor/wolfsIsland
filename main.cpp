#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mapmodel.h"
#include "map.h"

#define MAP_WIDTH 5
#define MAP_HEIGHT 3

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Register needed C++ classes to qml
    qmlRegisterType<MapModel>("Map", 1, 0, "MapModel");
    qmlRegisterUncreatableType<Map>("Map", 1, 0, "Map",
        QStringLiteral("Map should not be created in QML"));

    Map map(MAP_WIDTH, MAP_HEIGHT);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty(QStringLiteral("mMap"), &map);
    engine.rootContext()->setContextProperty(QStringLiteral("mMapWidth"), MAP_WIDTH);
    engine.rootContext()->setContextProperty(QStringLiteral("mMapHeight"), MAP_HEIGHT);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
