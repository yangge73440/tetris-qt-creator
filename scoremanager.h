#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <QObject>
#include <QVector>
#include <QSettings>

struct ScoreEntry {
    QString playerName;
    int score;
    int level;
    int linesCleared;
    QString dateTime;
};

class ScoreManager : public QObject
{
    Q_OBJECT
public:
    explicit ScoreManager(QObject *parent = nullptr);
    
    void saveScore(const ScoreEntry &entry);
    QVector<ScoreEntry> getTopScores(int count = 10);
    QVector<ScoreEntry> getHistory(int count = 50);

private:
    QSettings m_settings;
    static constexpr const char* KEY_PREFIX = "Score_";
    static constexpr const char* KEY_COUNT = "ScoreCount";
};

#endif // SCOREMANAGER_H
