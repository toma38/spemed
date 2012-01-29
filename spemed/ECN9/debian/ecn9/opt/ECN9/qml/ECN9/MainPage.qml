import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id:root
    tools: commonTools

    Label {
        id: label
        anchors.centerIn: parent
        text: qsTr("Hello world!")
        visible: false
    }


    ListView {
        anchors.fill: parent
        model: 10
        delegate: Rectangle {

            width: root.width
            height: 100
            color: "black"

            Rectangle {
                anchors.left: parent.left
                width: 0.2*root.width
                height: parent.height
                color: "red"
            }

            Rectangle {
                anchors.right: parent.right
                width: 0.8*root.width
                height: parent.height
                color: "blue"



            }




        }

    }





}
