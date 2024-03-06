QT += quick xml quick3d positioning

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CityMapGeometry.cpp \
        OsmParser.cpp \
        Viewer3DManager.cpp \
        Viewer3DQmlBackend.cpp \
        Viewer3DUtils.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CityMapGeometry.h \
    OsmParser.h \
    Viewer3DManager.h \
    Viewer3DQmlBackend.h \
    Viewer3DQmlVariableTypes.h \
    Viewer3DUtils.h \
    earcut.h
