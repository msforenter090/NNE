import QtQuick 2.12
import QtQuick.Controls 2.5

Item {
    id: name

    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent

        Item {
            id: firstPage
            Rectangle {
                color: "red"
                anchors.fill: parent
            }
        }

        Item {
            id: secondPage
            Rectangle {
                color: "blue"
                anchors.fill: parent
            }
        }

        Item {
            id: thirdPage
            Rectangle {
                color: "yellow"
                anchors.fill: parent
            }
        }
    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
