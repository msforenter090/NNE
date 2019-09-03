#include "Project.h"

designer::Project::Project(const QString &id, const QList<QFile *> &networkFiles) : _id(id), _networkFiles(networkFiles) {}

const QString& designer::Project::id() const { return _id; }
const QList<QFile *> &designer::Project::networkFiles() const { return _networkFiles; }
unsigned int designer::Project::count() const { return static_cast<unsigned int>(_networkFiles.count()); }
