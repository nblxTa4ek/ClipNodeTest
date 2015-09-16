import QtQuick 2.4
import QtQuick.Window 2.2

import com.clipnodetest.qml 1.0

Window {
    visible: true
    width: 800
    height: 600

    MouseArea {
        id: mouseArea1
        anchors.fill: parent
        onClicked: {
            annotation.clip = !annotation.clip
        }
    }

	Rectangle {
            id: backgroundRectangle
            width: 660
            height: 500
            color: "#a6bde2"
            radius: 50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

    AnnotationBase {
        id: annotation
        anchors.centerIn: parent
        width: 400
        height: 400
        clip: true

        Rectangle {
            id: clipRectangle
            anchors.centerIn: parent
            width: 200
            height: 200
            color: "#dc3535"
            radius: 15
            clip: true
            rotation: 45
            border.width: 0

            Rectangle {
                id: rectangle
                x: 69
                y: -48
                width: 200
                height: 200
                color: "#eaac30"
            }
        }

        Text {
            text: qsTr("Hello World")
            anchors.centerIn: parent
        }
    }
}

