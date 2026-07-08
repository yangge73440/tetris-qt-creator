#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "tetrixpiece.h"

class TetrixBoard;

class AIPlayer
{
public:
    AIPlayer(TetrixBoard *board, int difficulty = 1); // 1=Easy, 2=Medium, 3=Hard
    void setDifficulty(int difficulty);
    void makeMove(TetrixPiece piece, int &targetX, int &targetY, int &rotations);

private:
    TetrixBoard *board;
    int difficulty;
    double evaluatePosition(TetrixPiece piece, int x, int y);
    double calculateAggregateHeight();
    double calculateCompleteLines();
    double calculateHoles();
    double calculateBumpiness();
};

#endif // AIPLAYER_H
