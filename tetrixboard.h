#ifndef TETRIXBOARD_H
#define TETRIXBOARD_H

#include <QFrame>
#include <QObject>
#include <QPointer>
#include <QBasicTimer>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QAudioOutput>
#include <QList>
#include <QTimer>
#include <QPixmap>
#include "tetrixpiece.h"
#include "aiplayer.h"

class QLabel;
class TetrixBoard : public QFrame
{
    Q_OBJECT
public:
    enum GameMode { SinglePlayer, AIBattle, PVPBattle, AdventureMode };
    enum PlayerType { Player1, Player2 };
    TetrixBoard(QWidget *parent = nullptr);
    void setNextPieceLabel(QLabel *label);
    void setGameMode(GameMode mode);
    void setDifficulty(int difficulty);
    void setVolume(int volume);
    void setPlayerType(PlayerType type) { playerType = type; }
    void setOpponentBoard(TetrixBoard *opponent) { opponentBoard = opponent; }
    void setAdventureLevel(int level) { adventureLevel = level; isEndlessMode = (level == -1); }
    void setBackgroundPixmap(const QPixmap &pixmap) { m_bgPixmap = pixmap; update(); }
    TetrixPiece getCurrentPiece() const { return curPiece; }
    void makeAIMove(int targetX, int targetY, int rotations);
    bool getIsStarted() const { return isStarted; }
    bool getIsPaused() const { return isPaused; }
    TetrixShape getShapeAt(int x, int y) const { return boardBBlocks[y * BoardWidth + x]; }
    static const int BoardWidth = 12;
    static const int BoardHeight = 22;
    
    // 新功能：道具和技能
    void useHardShell();
    void useEarthquake();

public slots:
    void start();
    void pause();
    void addGarbageLines(int numLines);
    
    // 新功能：聚集碎裂和冻结碎裂
    void startCollapseShatter();
    void startFreezeShatter();

signals:
    void levelChanged(int level);
    void scoreChanged(int score);
    void linesRemovedChanged(int numLines);
    void sendAttack(int numLines);
    void stoneLinesChanged(int numStones);
    void shieldActiveChanged(bool active);
    void earthquakeReadyChanged(bool ready);
    void showWarning(int numLines);
    void screenShake();
    void gameOver(int finalScore, int finalLevel, int linesCleared);
    void hitEffect(int hitCount, const QPoint &pos);
    void bubbleEffect(const QString &text, const QPoint &pos);
    // 闯关模式信号
    void energyChanged(int current, int max);
    void monsterHealthChanged(int current, int max);
    void lineClearedFlash();
    void monsterAngry();
    void adventureLevelComplete();
    void adventureGameOver(bool won);
    void luckyMessage(const QString &message);
    void monsterHit();

private:
    enum {
        DropScore = 10,
        NextLevelNumber = 20
    };
    int squareWidth() { return contentsRect().width() / BoardWidth; }
    int squareHeight() { return contentsRect().height() / BoardHeight; }

    bool tryMove(const TetrixPiece &newPiece, int newX, int newY);
    TetrixShape &shapeAt(int x, int y) { return boardBBlocks[y * BoardWidth + x]; }
    void clearBoard();
    void showNextPiece();
    void drawSquare(QPainter &painter, int x, int y, TetrixShape shape, bool isGhost = false);
    void drawGhostPiece(QPainter &painter, int boardTop);
    int calculateGhostY();
    void oneLineDown();
    void pieceDropped(int dropHeight);
    int timeoutTime() { return 1000 / (1 + level); }
    void removeFullLines();
    void dropDown();
    void newPiece();
    void aiMove();
    
    // 新功能：辅助方法
    void generateStoneLine(int y);
    void checkShieldExpire();
    void triggerShield();
    void updateShatterAnimation(); // 更新碎裂动画

private:
    QPointer<QLabel> nextPieceLabel;
    TetrixPiece nextPiece;
    TetrixPiece curPiece;
    int curX;
    int curY;
    TetrixShape boardBBlocks[BoardWidth * BoardHeight];
    bool isStarted = false;
    bool isPaused = false;
    int numLinesRemoved = 0;
    int numPiecesDropped = 0;
    int score = 0;
    int level = 1;
    QBasicTimer timer;
    QMediaPlayer bgMusic;
    QAudioOutput audioOutput;
    QSoundEffect removeSound;
    QSoundEffect downSound;
    QSoundEffect gameoverSound;
    GameMode gameMode = SinglePlayer;
    int difficulty = 1;
    AIPlayer *aiPlayer = nullptr;
    QBasicTimer aiTimer;
    
    // 新功能：成员变量
    PlayerType playerType = Player1;
    TetrixBoard *opponentBoard = nullptr;
    int stoneLinesCount = 0;
    bool shieldActive = false;
    QTimer *shieldTimer = nullptr;
    int consecutiveClears = 0;
    bool earthquakeReady = false;
    QSoundEffect stoneSound;
    QSoundEffect shieldSound;
    QSoundEffect earthquakeSound;
    // 新功能：石头垃圾行计数器
    int piecesDroppedSinceLastStone = 0; // 距离上次生成石头垃圾行后已下落的方块数
    
    // 特效相关
    QList<int> clearingLines; // 正在消除的行
    QTimer *clearEffectTimer;
    int clearEffectStage;
    int m_consecutiveHits; // 连击数
    QTimer *m_hitResetTimer; // 连击重置计时器
    
    // 新功能：碎裂动画相关
    bool isInShatterAnimation; // 是否在碎裂动画中
    QList<TetrixShape> originalBoard; // 原始棋盘备份
    QTimer *shatterTimer; // 碎裂动画计时器
    int shatterStage; // 碎裂阶段
    enum ShatterType { NoShatter, CollapseShatter, FreezeShatter } shatterType; // 碎裂类型
    QList<QPoint> shatterPieces; // 碎裂碎片位置
    QSoundEffect shatterSound; // 碎裂音效
    
    // 闯关模式相关
    int adventureLevel; // 当前关卡
    bool isEndlessMode; // 是否无尽模式
    int currentEnergy; // 当前能量
    int maxEnergy; // 最大能量
    int monsterHealth; // 怪兽当前血量
    int maxMonsterHealth; // 怪兽最大血量
    int targetScore; // 目标分数
    QTimer *monsterTimer; // 怪兽发怒计时器
    int flashStage; // 闪光动画阶段
    QTimer *flashTimer; // 闪光动画计时器
    int monsterInterval; // 怪兽发怒间隔时间
    QTimer *specialBlockTimer; // 特殊方块计时器
    int specialBlockInterval; // 特殊方块间隔时间
    bool hasSpecialBlock; // 是否有特殊方块
    int specialBlockX; // 特殊方块X
    int specialBlockY; // 特殊方块Y
    int lastScoreMilestone; // 上次触发分数里程碑（1000分倍数）
    
    // 背景图片
    QPixmap m_bgPixmap; // 游戏框背景图片

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // TETRIXBOARD_H
