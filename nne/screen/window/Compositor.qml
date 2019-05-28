import QtQuick 2.6
import QtWayland.Compositor 1.3

// import "/creen/window/splash.qml"
// import "/screen/main.qml"

WaylandCompositor {
    // The output defines the screen.
    WaylandOutput {
        window: Splash {

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
