import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

import "../component"

import "qrc:/script/screen.js" as Behaviour

ApplicationWindow {
    id: mainWindow

    width: Behaviour.mainScreenWidth(Screen.width)
    height: Behaviour.mainScreenWidth(Screen.height)

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { text: "Open..." }
            MenuItem { text: "Close" }
        }

        Menu {
            title: "Edit"
            MenuItem { text: "Cut" }
            MenuItem { text: "Copy" }
            MenuItem { text: "Paste" }
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "green"
    }

    footer: NneMenu { }

    Component.onCompleted: {
        visible = true
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
}
