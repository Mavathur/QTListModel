import QtQuick 2.14
import QtQuick 2.7
import QtQuick.Window 2.14
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.12


import Album 1.0
import Me 1.0

ColumnLayout{

    Frame{
        implicitWidth: 500
        implicitHeight: 250
        clip: true

        ComboBox{
            id:mycombo
            x:parent.x
            width:400
            Text {
                id: name
                text: qsTr("Albums")
            }
            model: AlbumModel{
                list: myAlbumList
            }


            delegate: RowLayout{
                width: parent.width

                ComboBox{
                    textRole: "text"
                    width:300
                    Text  {
                        id: itemName
                        text: model.description
                    }

                    model: MyModel{
                        list: myList
                    }

                    RowLayout{
                        x:60
                        RoundButton{
                            width:20
                            text: qsTr("Add Song");
                            onClicked:
                            {
                                albumItem.addSongtoAlbum()
                            }
                        }
                        RoundButton{
                            width:20
                            text: qsTr("Delete Song");
                            onClicked:
                            {
                                albumItem.deleteSongFromAlbum()
                            }
                        }
                    }

                    delegate: RowLayout{
                        width: parent.width
                        TextField{
                            readOnly: true
                            text: model.description
                            onEditingFinished: model.description = text
                            Layout.fillWidth: true
                        }
                        RoundButton{
                            id: rb1
                            radius: 20

                            Image {
                                parent: rb1
                                id: name2
                                source: "icons8-play-64.png"
                                scale: 0.5
                                x:-12
                                y:-12

                            }

                        }
                        Slider{
                            value: 200
                            id:slider


                            ToolTip {
                                parent: slider.handle
                                visible: slider.pressed
                                text: slider.valueAt(slider.position*100).toFixed(1)

                            }
                        }
                    }
                    Layout.fillWidth: true
                }
            }
        }
    }
    RowLayout{
        Button{
            text: qsTr("Add New Album");
            onClicked: myAlbumList.appendItem()
        }
        Button{
            text: qsTr("Delete Album");
            onClicked: myAlbumList.removeItems()
        }
    }

}
