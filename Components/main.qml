import QtQuick
import QtQuick.Window
import QtQuick.Controls

import Recognizer 1.0
import SampleAudioCollector 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

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

    // color: theme.mainBackground
    Rectangle {
        id: panel
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
            margins: 10
        }
        width: parent.width / 2
        color: theme.surfaceColor
        ListView {
            anchors.fill: parent
            anchors.margins: 10
            model: ListModel {
                id: logModel
            }
            delegate: Text {
                text: modelData
                wrapMode: TextEdit.Wrap
                horizontalAlignment: TextEdit.AlignHCenter
                color: theme.primaryText
            }
        }
    }

    Text {
        id: tmpData
        anchors {
            top: parent.top
            right: textArea.right
            left: textArea.left
        }
        height: 50
        horizontalAlignment: TextEdit.AlignHCenter
        verticalAlignment: TextEdit.AlignVCenter
    }

    Rectangle {
        id: textArea
        anchors {
            right: parent.right
            left: panel.right
            top: tmpData.bottom
            bottom: parent.bottom
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
            delegate: Text {
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
    }

    MouseArea {
        anchors.fill: parent
        onClicked: sampleAudioCollector.setAbstractSeries(
                       audioSampleLevel.mainSeries)
    }

    Connections {
        target: rec
        function onNewData(data) {
            resultModel.append({
                                   "modelData": data
                               })
        }
        function onTmpData(data) {
            tmpData.text = data
        }
        function onNewLog(data) {
            logModel.append({
                                "modelData": data
                            })
        }
    }
}
