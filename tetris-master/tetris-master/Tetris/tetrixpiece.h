#ifndef TETRIXPIECE_H
#define TETRIXPIECE_H
//这里没写class ，需要隐式转换为 int
enum TetrixShape{ NoShape,ZShape,SShape,LineShape,TShape,
                   SquareShape,LShape,MirroredLShape};
class TetrixPiece
{
public:
    TetrixPiece();
    void setShape(TetrixShape shape);
    void setRandomShape();
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;
    TetrixPiece rotatedLeft() const;//后面加const啥意思类
    TetrixPiece rotatedRight() const;//
    int y(int index) const {return coords[index][1];}
    int x(int index) const {return coords[index][0]; }
    TetrixShape shape(){ return pieceShape; }
private:
    void setX(int index,int value){ coords[index][0]=value;}
    void setY(int index,int value){coords[index][1]=value;}
    TetrixShape pieceShape;//抽象的描述
    int coords[4][2];//具体的描述，每个图形有四个小块，每个小块都有x和y坐标
};

#endif // TETRIXPIECE_H
