#include "scoremanager.h"
#include <QDateTime>
#include <QDebug>
#include <algorithm>

ScoreManager::ScoreManager(QObject *parent)
    : QObject(parent)
    , m_settings("TetrisGame", "Tetris")
{
}

void ScoreManager::saveScore(const ScoreEntry &entry)
{
    int count = m_settings.value(KEY_COUNT, 0).toInt();
    QString key = QString("%1%2").arg(KEY_PREFIX).arg(count);
    m_settings.setValue(key + "/playerName", entry.playerName);
    m_settings.setValue(key + "/score", entry.score);
    m_settings.setValue(key + "/level", entry.level);
    m_settings.setValue(key + "/linesCleared", entry.linesCleared);
    m_settings.setValue(key + "/dateTime", entry.dateTime);
    m_settings.setValue(KEY_COUNT, count + 1);
}

QVector<ScoreEntry> ScoreManager::getTopScores(int count)
{
    QVector<ScoreEntry> allScores;
    int total = m_settings.value(KEY_COUNT, 0).toInt();
    
    for (int i = 0; i < total; ++i) {
        QString key = QString("%1%2").arg(KEY_PREFIX).arg(i);
        ScoreEntry entry;
        entry.playerName = m_settings.value(key + "/playerName", "Unknown").toString();
        entry.score = m_settings.value(key + "/score", 0).toInt();
        entry.level = m_settings.value(key + "/level", 1).toInt();
        entry.linesCleared = m_settings.value(key + "/linesCleared", 0).toInt();
        entry.dateTime = m_settings.value(key + "/dateTime", "").toString();
        allScores.append(entry);
    }
    
    // Sort by score descending
    std::sort(allScores.begin(), allScores.end(), [](const ScoreEntry &a, const ScoreEntry &b) {
        return a.score > b.score;
    });
    
    // Return top N
    if (allScores.size() > count) {
        allScores.resize(count);
    }
    
    return allScores;
}

QVector<ScoreEntry> ScoreManager::getHistory(int count)
{
    QVector<ScoreEntry> history;
    int total = m_settings.value(KEY_COUNT, 0).toInt();
    
    int startIndex = qMax(0, total - count);
    for (int i = total - 1; i >= startIndex; --i) {
        QString key = QString("%1%2").arg(KEY_PREFIX).arg(i);
        ScoreEntry entry;
        entry.playerName = m_settings.value(key + "/playerName", "Unknown").toString();
        entry.score = m_settings.value(key + "/score", 0).toInt();
        entry.level = m_settings.value(key + "/level", 1).toInt();
        entry.linesCleared = m_settings.value(key + "/linesCleared", 0).toInt();
        entry.dateTime = m_settings.value(key + "/dateTime", "").toString();
        history.append(entry);
    }
    
    return history;
}
