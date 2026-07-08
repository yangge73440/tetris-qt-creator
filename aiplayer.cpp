#include "aiplayer.h"
#include "tetrixboard.h"
#include <QDebug>
#include <vector>
#include <algorithm>

AIPlayer::AIPlayer(TetrixBoard *board, int difficulty)
    : board(board)
    , difficulty(difficulty)
{
}

void AIPlayer::setDifficulty(int difficulty)
{
    this->difficulty = difficulty;
}

void AIPlayer::makeMove(TetrixPiece piece, int &targetX, int &targetY, int &rotations)
{
    double bestScore = -1e9;
    targetX = 0;
    targetY = 0;
    rotations = 0;

    TetrixPiece rotatedPiece = piece;
    for (int rot = 0; rot < 4; ++rot) {
        int minX = 0 - rotatedPiece.minX();
        int maxX = TetrixBoard::BoardWidth - 1 - rotatedPiece.maxX();
        for (int x = minX; x <= maxX; ++x) {
            int y = 0;
            // Find the lowest possible y for this position
            while (true) {
                bool collision = false;
                for (int i = 0; i < 4; ++i) {
                    int px = x + rotatedPiece.x(i);
                    int py = y - rotatedPiece.y(i);
                    if (px < 0 || px >= TetrixBoard::BoardWidth || py < 0 || py >= TetrixBoard::BoardHeight) {
                        collision = true;
                        break;
                    }
                    if (board->getShapeAt(px, py) != NoShape) {
                        collision = true;
                        break;
                    }
                }
                if (!collision) {
                    y++;
                } else {
                    y--;
                    break;
                }
            }
            if (y < 0) continue;

            double score = evaluatePosition(rotatedPiece, x, y);
            if (score > bestScore) {
                bestScore = score;
                targetX = x;
                targetY = y;
                rotations = rot;
            }
        }
        rotatedPiece = rotatedPiece.rotatedRight();
    }
}

double AIPlayer::evaluatePosition(TetrixPiece piece, int x, int y)
{
    // 1. Create a copy of the current board
    std::vector<TetrixShape> tempBoard(TetrixBoard::BoardWidth * TetrixBoard::BoardHeight);
    for (int i = 0; i < TetrixBoard::BoardWidth; ++i) {
        for (int j = 0; j < TetrixBoard::BoardHeight; ++j) {
            tempBoard[j * TetrixBoard::BoardWidth + i] = board->getShapeAt(i, j);
        }
    }

    // 2. Place the piece in the temp board
    for (int i = 0; i < 4; ++i) {
        int px = x + piece.x(i);
        int py = y - piece.y(i);
        if (px >= 0 && px < TetrixBoard::BoardWidth && py >= 0 && py < TetrixBoard::BoardHeight) {
            tempBoard[py * TetrixBoard::BoardWidth + px] = piece.shape();
        }
    }

    // 3. Calculate complete lines
    int linesCleared = 0;
    std::vector<bool> fullLines(TetrixBoard::BoardHeight, false);
    for (int j = 0; j < TetrixBoard::BoardHeight; ++j) {
        bool full = true;
        for (int i = 0; i < TetrixBoard::BoardWidth; ++i) {
            if (tempBoard[j * TetrixBoard::BoardWidth + i] == NoShape) {
                full = false;
                break;
            }
        }
        if (full) {
            fullLines[j] = true;
            linesCleared++;
        }
    }

    // 4. Create a new temp board without full lines
    std::vector<TetrixShape> newBoard(TetrixBoard::BoardWidth * TetrixBoard::BoardHeight, NoShape);
    int writeLine = TetrixBoard::BoardHeight - 1;
    for (int j = TetrixBoard::BoardHeight - 1; j >= 0; --j) {
        if (!fullLines[j]) {
            for (int i = 0; i < TetrixBoard::BoardWidth; ++i) {
                newBoard[writeLine * TetrixBoard::BoardWidth + i] = tempBoard[j * TetrixBoard::BoardWidth + i];
            }
            writeLine--;
        }
    }

    // 5. Calculate aggregate height
    double aggregateHeight = 0;
    std::vector<int> heights(TetrixBoard::BoardWidth, 0);
    for (int i = 0; i < TetrixBoard::BoardWidth; ++i) {
        for (int j = 0; j < TetrixBoard::BoardHeight; ++j) {
            if (newBoard[j * TetrixBoard::BoardWidth + i] != NoShape) {
                heights[i] = TetrixBoard::BoardHeight - j;
                aggregateHeight += heights[i];
                break;
            }
        }
    }

    // 6. Calculate holes
    int holes = 0;
    for (int i = 0; i < TetrixBoard::BoardWidth; ++i) {
        bool foundBlock = false;
        for (int j = 0; j < TetrixBoard::BoardHeight; ++j) {
            if (newBoard[j * TetrixBoard::BoardWidth + i] != NoShape) {
                foundBlock = true;
            } else if (foundBlock) {
                holes++;
            }
        }
    }

    // 7. Calculate bumpiness
    double bumpiness = 0;
    for (int i = 0; i < TetrixBoard::BoardWidth - 1; ++i) {
        bumpiness += std::abs(heights[i] - heights[i + 1]);
    }

    // 8. Calculate max height
    double maxHeight = 0;
    for (int h : heights) {
        if (h > maxHeight) maxHeight = h;
    }

    // 9. Set weights based on difficulty (using better AI weights from standard Tetris AI)
    double weightLines, weightHeight, weightHoles, weightBumpiness, weightMaxHeight;
    switch (difficulty) {
        case 1: // Easy
            weightLines = 50;
            weightHeight = -0.5;
            weightHoles = -1;
            weightBumpiness = -0.2;
            weightMaxHeight = -0.5;
            break;
        case 2: // Medium
            weightLines = 100;
            weightHeight = -1;
            weightHoles = -3;
            weightBumpiness = -0.5;
            weightMaxHeight = -1;
            break;
        case 3: // Hard (use standard strong AI weights)
            weightLines = 300;
            weightHeight = -2;
            weightHoles = -8;
            weightBumpiness = -1.5;
            weightMaxHeight = -2;
            break;
        default:
            weightLines = 100;
            weightHeight = -1;
            weightHoles = -3;
            weightBumpiness = -0.5;
            weightMaxHeight = -1;
            break;
    }

    // 10. Calculate final score
    double score = weightLines * linesCleared +
                   weightHeight * aggregateHeight +
                   weightHoles * holes +
                   weightBumpiness * bumpiness +
                   weightMaxHeight * maxHeight;

    return score;
}

double AIPlayer::calculateAggregateHeight()
{
    return 0; // Not used, calculated directly in evaluatePosition
}

double AIPlayer::calculateCompleteLines()
{
    return 0; // Not used, calculated directly in evaluatePosition
}

double AIPlayer::calculateHoles()
{
    return 0; // Not used, calculated directly in evaluatePosition
}

double AIPlayer::calculateBumpiness()
{
    return 0; // Not used, calculated directly in evaluatePosition
}
