#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "CityMapGeometry.h"
#include "Viewer3DQmlBackend.h"
#include "Viewer3DQmlVariableTypes.h"
#include "OsmParser.h"
#include "Viewer3DManager.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<GeoCoordinateType>             ("Viewer3DManager", 1, 0, "GeoCoordinateType");
    qmlRegisterType<CityMapGeometry>               ("Viewer3DManager", 1, 0, "CityMapGeometry");
    qmlRegisterType<Viewer3DManager>               ("Viewer3DManager", 1, 0, "Viewer3DManager");
    qmlRegisterUncreatableType<Viewer3DQmlBackend> ("Viewer3DManager", 1, 0, "Viewer3DQmlBackend",  "kRefOnly");
    qmlRegisterUncreatableType<OsmParser>          ("Viewer3DManager", 1, 0, "OsmParser",           "kRefOnly");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
