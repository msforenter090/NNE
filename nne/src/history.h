#pragma once

#include <QList>
#include <QString>
#include <QDateTime>

namespace nne
{
    class HistoryParam
    {
        Q_DISABLE_COPY(HistoryParam)

    private:

    };

    /**
     * @brief One history elemant in project history chain.
     */
    class HistoryElement
    {
        Q_DISABLE_COPY(HistoryElement)

    private:
        const QDateTime                 _date;
        const unsigned int              _code;
        const QString                   _description;
        const QList<HistoryParam*>      _params;

    public:
        HistoryElement(const QDateTime& date, const unsigned int code,
                       const QString &description,
                       const QList<HistoryParam*> &params);

        const QDateTime& date() const;
        unsigned int code() const;
        const QString& description() const;
        const QList<HistoryParam*>& params();
    };

    /**
     * @brief Tracks loaded listory.
     */
    class History
    {
        Q_DISABLE_COPY(History)

    private:
        const QList<HistoryElement*>    _history;


    public:
        History(const QList<HistoryElement*> &history);

        const QList<HistoryElement*>& history() const;
    };

    /**
     * @brief Loads history in specified range.
     * @param histortFile       History file to load from.
     * @param from              start of history range
     * @param to                end of history range
     * @return                  loaded History or null if errors out.
     */
    History* loadFromDate(const QFile& historyFile, const QDateTime &from, const QDateTime &to);
}
