import QtQuick 2.7
import QtQuick.Window 2.14
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.12

import Me 1.0
ApplicationWindow {
    Material.theme: Material.Dark
    Material.accent: Material.Purple
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt")

    Albums{
        anchors.centerIn: parent
    }

}
