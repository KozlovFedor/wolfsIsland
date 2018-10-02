import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

import "./Cell.qml"

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Wolf's island")


    Rectangle {
        id: map
        color: "#ffffaa"
        z: 1
        anchors.bottom: toolBar.top
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top

        Grid {
            id: grid
            anchors.fill: parent
            z: 2
            
            Cell { grassLevel: 1 }
        }
    }

    Rectangle {
        id: toolBar
        width: parent.width; height: 30
        color: activePalette.window
        anchors.bottom: parent.bottom

        Button {
            text: "New Game"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.top: parent.top
            onClicked: console.log("This doesn't do anything yet...")
        }

        Text {
            id: score
            anchors { right: parent.right; verticalCenter: parent.verticalCenter }
            text: "Score: Who knows?"
        }
    }
}

/*##^## Designer {
    D{i:5;anchors_height:400;anchors_width:400;anchors_x:127;anchors_y:34}
}
 ##^##*/
