import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Layouts 1.3

import Map 1.0

ColumnLayout {
    Rectangle {
        id: background
        width: childrenRect.width + 1
        height: childrenRect.height + 1
        color: "#000000"

        GridView {
            id: grid
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            cellWidth: 50
            cellHeight: 50
            width: cellHeight * mMapWidth
            height: cellHeight * mMapHeight
            clip: true

            model: MapModel {
                map: mMap
            }

            delegate: Cell {
                width: grid.cellWidth -1
                height: grid.cellHeight -1

                grassLevel: model.cell
            }
        }
    }

    Button {
        text: qsTr("Next step")
        onClicked: map.nextStepButtonPressed()
    }
}
