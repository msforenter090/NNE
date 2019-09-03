#pragma once

#include <QObject>
#include "Project.h"

namespace designer {
// Global model.
class Workspace {
    Q_DISABLE_COPY(Workspace)

private:
    Project *project;
};
}
