import QtQuick
import QtQuick.Window
import QtQuick.Controls

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15
import QtQuick 2.0

import Recognizer 1.0
import SampleAudioCollector 1.0

import "./TopPanel" as TopPanelItems
import "./BottomPanel" as BottomPanelItems

Window {
    id: root
    width: 350
    height: 720
    visible: true
    title: qsTr("Hello World")
    color: "pink"

    QtObject {
        id: theme
        property color mainBackground: "#0D0D0D"
        property color surfaceColor: "#1F1F1F"
        property color primaryText: "#FFFFFF"
        property color secondaryText: "#B3B3B3"
        property color accentApplyColor: "#4CAF50"
        property color accentWarningColor: "#FF5252"
        property color accentSelectedColor: "#448AFF"
        property color dividerColor: "#2C2C2C"
    }

    TopPanelItems.TopPanel {
        id: topPanel
        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
        }
        height: 50
        onMenuClicked: menuWindows.open()
        onInfoClicked: print("Info clicked!")
    }

    MenuWindows {
        id: menuWindows
        wholeWidth: root.width * 2 / 3
    }

    Rectangle {
        id: predictedBox
        anchors {
            top: topPanel.bottom
            right: parent.right
            left: parent.left
            margins: 10
        }
        height: 50
        color: "gray"
        Text {
            id: predictedText
            anchors.fill: parent
            horizontalAlignment: TextEdit.AlignHCenter
            verticalAlignment: TextEdit.AlignVCenter
        }
    }

    Rectangle {
        id: textArea
        anchors {
            right: parent.right
            left: parent.left
            top: predictedBox.bottom
            bottom: bottomPanel.top
            margins: 10
        }
        width: parent.width / 2
        color: theme.surfaceColor

        ListView {
            anchors.fill: parent
            anchors.margins: 10
            model: ListModel {
                id: resultModel
            }
            delegate: TextEdit {
                text: modelData
                wrapMode: TextEdit.Wrap
                horizontalAlignment: TextEdit.AlignHCenter
                color: theme.primaryText
            }
        }
    }

    Recognizer {
        id: rec
        Component.onCompleted: start()
    }

    BottomPanelItems.BottomPanel {
        id: bottomPanel
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        height: 70
        circleRadius: 30
        circleCompression: -10
        arcRadius: 15
        arcXPointOffset: 10
        arcYPointOffset: 10
    }

    Connections {
        target: rec
        function onNewData(data) {
            resultModel.append({
                                   "modelData": data
                               })
        }
        function onTmpData(data) {
            predictedText.text = data
        }
        function onNewLog(data) {// logModel.append({
            //                     "modelData": data
            //                 })
        }
    }


    /*
      //Copy
    Item {
        id: clipboardHandler
        property var clipboard: Qt.application.clipboard

        // Function to copy ListModel data to clipboard
        function copyListToClipboard() {
            var textToCopy = ""
            for (var i = 0; i < resultModel.count; i++) {
                textToCopy += resultModel.get(i).modelData // Get each item
                if (i < resultModel.count - 1) {
                    textToCopy += "\n" // Add newline between items
                }
            }
            // clipboard.setText(textToCopy) // Copy to clipboard
            console.log("Copied to clipboard: " + textToCopy)
        }

        function saveListToFile() {
            var textToSave = ""
            for (var i = 0; i < resultModel.count; i++) {
                textToSave += resultModel.get(i).modelData
                if (i < resultModel.count - 1) {
                    textToSave += "\n" // Newline separator
                }
            }
            // For now, log it (replace with file writing below)
            console.log("Data to save: " + textToSave)
            // Placeholder: This is where file writing would go
            return textToSave // Return for C++ integration
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: clipboardHandler.copyListToClipboard()
    }
    */


    /*
      //Chart
    SampleAudioCollector {
        id: sampleAudioCollector
    }

    AudioSampleLevel {
        id: audioSampleLevel
        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        height: 300
        Component.onCompleted: sampleAudioCollector.setAbstractSeries(
                                   audioSampleLevel.mainSeries)
    }
*/
}
