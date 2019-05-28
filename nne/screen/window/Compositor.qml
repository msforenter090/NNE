import QtQuick 2.6
import QtWayland.Compositor 1.3

WaylandCompositor {
    // The output defines the screen.
    WaylandOutput {
        window: Main {

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
