import QtQuick 2.13
import QtQuick.Window 2.13

import "./view/";

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Start {
        anchors.fill: parent;
    }
}
