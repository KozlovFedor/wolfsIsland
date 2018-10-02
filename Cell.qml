import QtQuick 2.0

Rectangle {
    id: cell

    property int grassLevel

    width: 50
    height: 50
    color: Qt.rgba(1 - (grassLevel / 3), 1, 1 - (grassLevel / 3), 1)
}
