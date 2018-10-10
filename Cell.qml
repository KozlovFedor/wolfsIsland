import QtQuick 2.9


Rectangle {
    id: background

    implicitWidth: 30
    implicitHeight: 30
    //border.width: 1

    property int grassLevel
    property var colorDict: {0: "#ffffff", 1: "#ddffdd", 2: "#bbffbb", 3: "#99ff99"}
    color: colorDict[grassLevel]
}
