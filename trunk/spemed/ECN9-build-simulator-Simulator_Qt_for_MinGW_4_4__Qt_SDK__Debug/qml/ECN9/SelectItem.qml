import QtQuick 1.0

Rectangle {
           id:root
           height: 100
           color:"black"



           Rectangle {
               anchors.left: parent.left
               width: 0.2*root.width
               height: parent.height
               color: "black"
               Text {
                   anchors.centerIn: parent
                   text:"3"
                   font.pixelSize: 40
                   color: "white"

               }
           }

           Rectangle {
               anchors.right: parent.right
               width: 0.8*root.width
               height: parent.height
               color: "black"

               Text {
                   anchors.centerIn: parent
                   text:"sdflsdf sf slf gfh fgh fh fhf hfg hfg hfh  "
                   font.pixelSize: 30
                   width: parent.width
                   wrapMode: "WordWrap"
                   color: "white"
               }



           }




       }
