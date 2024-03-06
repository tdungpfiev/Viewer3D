#ifndef Viewer3DQmlBackend_H
#define Viewer3DQmlBackend_H

#include <QObject>
#include <qqml.h>
#include <QString>

#include "OsmParser.h"

class Viewer3DQmlBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QGeoCoordinate gpsRef READ gpsRef NOTIFY gpsRefChanged)

public:
    explicit Viewer3DQmlBackend(QObject *parent = nullptr);

    void init(OsmParser* osmThr=nullptr);

    QGeoCoordinate gpsRef(){return _gpsRef;}

signals:
    void gpsRefChanged();

private:
    OsmParser *_osmParserThread;

    QGeoCoordinate _gpsRef;
    uint8_t _gpsRefSet;

protected slots:
    void _gpsRefChangedEvent(QGeoCoordinate newGpsRef, bool isRefSet);
};

#endif // Viewer3DQmlBackend_H
