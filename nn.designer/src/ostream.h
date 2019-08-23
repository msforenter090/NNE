#pragma once

#include <QString>

namespace nne {
class OStream {
    public:
    OStream &console(const QString &line);
    OStream &log(const QString &line);
};
} // namespace nne
