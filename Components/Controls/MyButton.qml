import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import Qt5Compat.GraphicalEffects

// Button {
//     id: root

//     background: Rectangle {
//         color: "transparent"
//         gradient: Gradient {
//             GradientStop {
//                 position: 0
//                 color: "#ffffff"
//             }
//             GradientStop {
//                 position: 1
//                 color: "#c1bbf9"
//             }
//         }
//     }
//     icon {
//         color: "blue"
//         width: root.height
//         height: width
//     }
// }
Item {
    id: root

    property string iconUrl: image.source
    property string iconMargin: image.anchors.margins
    property color iconColor: colorOverlay.color

    signal clicked

    Image {
        id: image
        anchors.fill: parent
        anchors.margins: 5
        source: iconUrl
    }

    ColorOverlay {
        id: colorOverlay
        anchors.fill: image
        source: image
        color: "#0000FF"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
