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
        delegate:SelectItem {
            width: parent.width
            height: 43

        }


    }





}
