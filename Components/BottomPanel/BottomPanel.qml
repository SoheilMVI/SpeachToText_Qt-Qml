import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts

import "./Buttons" as MyButtons

Item {
    id: root

    property real halfWidth: root.width / 2
    property real circleRadius: 45
    property real circleCompression: -10
    property real arcRadius: 30
    property real arcXPointOffset: 10 //30
    property real arcYPointOffset: 15 //10

    property real iconSize: 40

    property alias backgroundColor: shapePath.fillColor
    property alias borderColor: shapePath.strokeColor
    property alias shapeItem: shapePath

    property alias leftFirstItemSource: leftFirst.sourceComponent
    property alias leftSecondItemSource: leftSecond.sourceComponent
    property alias middleItemSource: middle.sourceComponent
    property alias rightFirstItemSource: rightFirst.sourceComponent
    property alias rightSecondItemSource: rightSecond.sourceComponent

    Shape {
        ShapePath {
            id: shapePath
            strokeWidth: 0
            strokeColor: fillColor
            fillColor: "green"

            startX: 0
            startY: root.height

            PathLine {
                x: 0
                y: 0
            }
            PathLine {
                x: halfWidth - root.circleRadius - arcRadius - arcXPointOffset
                y: 0
            }
            PathArc {
                x: halfWidth - root.circleRadius
                y: arcRadius + arcYPointOffset
                radiusX: arcRadius + arcXPointOffset
                radiusY: arcRadius + arcYPointOffset
            }
            PathArc {
                x: halfWidth + root.circleRadius
                y: arcRadius + arcYPointOffset
                radiusX: root.circleRadius
                radiusY: root.circleRadius - circleCompression - arcYPointOffset
                direction: PathArc.Counterclockwise
            }
            PathArc {
                x: halfWidth + root.circleRadius + arcRadius + arcXPointOffset
                y: 0
                radiusX: arcRadius + arcXPointOffset
                radiusY: arcRadius + arcYPointOffset
            }
            PathLine {
                x: halfWidth * 2
                y: 0
            }
            PathLine {
                x: halfWidth * 2
                y: root.height
            }
            PathLine {
                x: 0
                y: root.height
            }
        }
    }

    Row {
        id: leftItems
        width: halfWidth - circleRadius - arcRadius
        height: root.height
        Loader {
            id: leftFirst
            width: leftItems.width / 2
            height: width
            sourceComponent: MyButtons.ModelSelector {}
        }
        Loader {
            id: leftSecond
            width: leftItems.width / 2
            height: width
            sourceComponent: MyButtons.Reset {}
        }
    }

    Loader {
        id: middle
        width: circleRadius * 2
        height: width //circleRadius * 2 + circleCompression
        sourceComponent: MyButtons.Record {}
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: circleCompression
        }
    }

    Row {
        id: rightItems
        anchors.right: parent.right
        width: leftItems.width
        height: root.height
        Loader {
            id: rightFirst
            width: leftItems.width / 2
            height: width
            sourceComponent: MyButtons.Setting {}
        }
        Loader {
            id: rightSecond
            width: leftItems.width / 2
            height: width
            sourceComponent: MyButtons.Share {}
        }
    }
}
