#include "Viewer3DQmlBackend.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QUrl>

#define GPS_REF_NOT_SET                 0
#define GPS_REF_SET_BY_MAP              1
#define GPS_REF_SET_BY_VEHICLE          2

Viewer3DQmlBackend::Viewer3DQmlBackend(QObject *parent)
    : QObject{parent}
{
    _gpsRefSet = GPS_REF_NOT_SET;
}

void Viewer3DQmlBackend::init(OsmParser* osmThr)
{
    _osmParserThread = osmThr;

    connect(_osmParserThread, &OsmParser::gpsRefChanged, this, &Viewer3DQmlBackend::_gpsRefChangedEvent);
}

void Viewer3DQmlBackend::_gpsRefChangedEvent(QGeoCoordinate newGpsRef, bool isRefSet)
{
    if(isRefSet){
        _gpsRef = newGpsRef;
        _gpsRefSet = GPS_REF_SET_BY_MAP;
        emit gpsRefChanged();
        qDebug() << "3D viewer gps reference set by osm map:" << _gpsRef.latitude() << _gpsRef.longitude() << _gpsRef.altitude();
    }else{
        _gpsRefSet = GPS_REF_NOT_SET;
    }
}
