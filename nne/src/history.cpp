#include "history.h"

nne::HistoryElement::HistoryElement(const QDateTime &date,
                                    const unsigned int code,
                                    const QString &description,
                                    const QList<HistoryParam *> &params)
    : _date(date), _code(code), _description(description), _params(params) {}

const QDateTime &nne::HistoryElement::date() const { return _date; }
unsigned int nne::HistoryElement::code() const { return _code; }
const QString &nne::HistoryElement::description() const { return _description; }
const QList<nne::HistoryParam *> &nne::HistoryElement::params() {
    return _params;
}

nne::History::History(const QList<HistoryElement *> &history)
    : _history(history) {}
const QList<nne::HistoryElement *> &nne::History::history() const {
    return _history;
}

nne::History *loadFromDate(const QFile &historyFile, const QDateTime &from,
                           const QDateTime &to) {
    return nullptr;
}
