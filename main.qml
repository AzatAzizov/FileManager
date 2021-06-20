import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.12

import Manager 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Manager {
        id: manager
    }

    Button {
        id: button
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 50
        text: "CreateDir"
        onClicked: manager.createDir();
    }

    ListView{
        anchors {
            top: button.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        model: /*Manager*/ manager
//        width: parent.width
//        height: parent.height


        delegate: Rectangle {
//            width: implicitWidth
            width: parent.width
            height: 30
            id: rectangle1
//            border.color: area.pressed ? "gold" : "black"

            Text {
                id: textDelegate
                anchors.centerIn: parent
                text: model.name+model.path
            }
        }
    }

}

