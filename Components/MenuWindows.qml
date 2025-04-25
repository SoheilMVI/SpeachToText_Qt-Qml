import QtQuick
import QtQuick.Controls

Popup {
    id: root
    x: 0
    y: 0
    required property real wholeWidth

    height: parent.height
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    background: Rectangle {}
    enter: Transition {
        NumberAnimation {
            property: "width"
            from: 0
            to: root.wholeWidth
        }
    }
    exit: Transition {
        NumberAnimation {
            property: "width"
            to: 0
        }
    }
}
