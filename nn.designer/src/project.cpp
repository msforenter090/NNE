#include "project.h"

nne::Project::Project(const QList<QFile *> &networks,
                      const QList<QFile *> &trainingSets,
                      const QList<QFile *> &training)
    : _networks(networks), _trainingSets(trainingSets), _training(training) {}

const QList<QFile *> &nne::Project::networks() const { return _networks; }
const QList<QFile *> &nne::Project::trainingSets() const {
    return _trainingSets;
}
const QList<QFile *> &nne::Project::training() const { return _training; }
