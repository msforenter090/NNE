import QtQuick 2.12
import QtQuick.Controls 2.5

TabBar {
    id: bar
    width: parent.width

    TabButton {
        text: qsTr("Work")
    }

    TabButton {
        text: qsTr("Device")
    }

    TabButton {
        text: qsTr("Activity")
    }

    TabButton {
        text: qsTr("Info")
    }
}
