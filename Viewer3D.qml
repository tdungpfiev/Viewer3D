import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts

import Viewer3DManager

Item{
    id: viewer3DBody
    property bool isOpen: true
    property bool _viewer3DEnabled: true


    function open(){
        if(_viewer3DEnabled === true){
            view3DManagerLoader.sourceComponent = viewer3DManagerComponent
            view3DManagerLoader.active = true;
            isOpen = true;
        }
    }

    function close(){
        isOpen = false;
    }

    visible: isOpen
    enabled: isOpen

    on_Viewer3DEnabledChanged: {
        if(_viewer3DEnabled === false){
            viewer3DBody.close();
            view3DLoader.active = false;
            view3DManagerLoader.active = false;
        }
    }

    Component{
        id: viewer3DManagerComponent

        Viewer3DManager{
            id: _viewer3DManager
        }
    }

    Loader{
        id: view3DManagerLoader

        onLoaded: {
            view3DLoader.source = "Viewer3DModel.qml"
            view3DLoader.active = true;
        }
    }

    Loader{
        id: view3DLoader
        anchors.fill: parent

        onLoaded: {
            item.viewer3DManager = view3DManagerLoader.item
        }
    }

    Binding{
        target: view3DLoader.item
        property: "isViewer3DOpen"
        value: isOpen
        when: view3DLoader.status == Loader.Ready
    }
}
