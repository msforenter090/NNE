#pragma once

#include <QFile>
#include <QList>
#include <QString>

namespace nne {
class Project {
    Q_DISABLE_COPY(Project)
    private:
    QList<QFile *> _networks;
    QList<QFile *> _trainingSets;
    QList<QFile *> _training;

    public:
    explicit Project(const QList<QFile *> &networks,
                     const QList<QFile *> &trainingSets,
                     const QList<QFile *> &training);

    const QList<QFile *> &networks() const;
    const QList<QFile *> &trainingSets() const;
    const QList<QFile *> &training() const;
};
} // namespace nne
