import QtQuick 2.6
import QtQuick.Window 2.2
import QtWayland.Compositor 1.3

WaylandCompositor {
    // The output defines the screen.
    WaylandOutput {
        id: output
        objectName: "output"
        sizeFollowsWindow: true
        window: Window {
            id: splash
            color: "transparent"
            modality: Qt.ApplicationModal
                flags: Qt.SplashScreen
                property int timeoutInterval: 2000
                signal timeout
                x: (Screen.width - splashImage.width) / 2
                y: (Screen.height - splashImage.height) / 2
                width: splashImage.width
                height: splashImage.height
                Image {
                    id: splashImage
                    source: "qrc:/image/logo.png"
                    MouseArea {
                        anchors.fill: parent
                    }
                }
                Component.onCompleted: visible = true
            Repeater {
                model: shellSurfaces
                // ShellSurfaceItem handles displaying a shell surface.
                // It has implementations for things like interactive
                // resize/move, and forwarding of mouse and keyboard
                // events to the client process.
                ShellSurfaceItem {
                    autoCreatePopupItems: true
                    shellSurface: modelData
                    onSurfaceDestroyed: shellSurfaces.remove(index)
                }
            }
        }
    }

    WlShell {
        onWlShellSurfaceCreated: {
            shellSurfaces.append({shellSurface: shellSurface});
        }
    }
    XdgShellV6 {
        onToplevelCreated: {
            shellSurfaces.append({shellSurface: xdgSurface});
        }
    }
    XdgShell {
        onToplevelCreated: {
            shellSurfaces.append({shellSurface: xdgSurface});
        }
    }
    ListModel { id: shellSurfaces }
}
