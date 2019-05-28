import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

import "qrc:/script/screen.js" as Behaviour

Window {
    id: splash

    color: "transparent"
    modality: Qt.ApplicationModal

    flags: Qt.SplashScreen

    width: Behaviour.splashScreenWidth(Screen.width)
    height: Behaviour.splashScreenWidth(Screen.height)

    ColumnLayout {
        anchors.fill: parent
        layoutDirection: Qt.LeftToRight

        Image {
            Layout.fillWidth: true
            Layout.fillHeight: true
            source: "qrc:/image/logo.png"
        }

        ProgressBar {
            id: progress
            height: 46
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignBottom
            value: .5
        }
    }

    Component.onCompleted: {
        visible = true
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
}
