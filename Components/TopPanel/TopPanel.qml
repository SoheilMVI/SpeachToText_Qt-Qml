import QtQuick

import "./Buttons" as MyButtons

Item {
    id: root

    signal menuClicked
    signal infoClicked

    Loader {
        id: left
        anchors {
            left: parent.left
            // horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            // verticalCenterOffset: -30
        }

        width: root.height - 5
        height: root.height - 5
        sourceComponent: MyButtons.Menu {
            onClicked: root.menuClicked()
        }
    }

    Loader {
        id: right
        anchors {
            right: parent.right
            // horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            // verticalCenterOffset: -30
        }
        width: left.width
        height: left.height
        sourceComponent: MyButtons.Info {
            onClicked: root.infoClicked()
        }
    }
}
