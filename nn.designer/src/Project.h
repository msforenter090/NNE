#pragma once

#include <QFile>
#include <QList>
#include <QString>

namespace designer {
class Project {
    Q_DISABLE_COPY(Project)

private:
    QString _id;
    QList<QFile *> _networkFiles;

public:
    explicit Project(const QString &id, const QList<QFile *> &networkFiles);
    const QString& id() const;
    const QList<QFile *> &networkFiles() const;
    unsigned int count() const;
};
} // namespace nne
