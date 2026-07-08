#include "tetrixpiece.h"
#include<QRandomGenerator>
TetrixPiece::TetrixPiece() {
    setShape(NoShape);//先进行初始化
}
void TetrixPiece::setShape(TetrixShape shape)
{
    //不同形状四个块的位置
    static constexpr int coordsTable[9][4][2]={
        {{0,0},{0,0},{0,0},{0,0}},//NoShape
        {{0,-1},{0,0},{-1,0},{-1,1}},//ZShape
        {{0,-1},{0,0},{1,0},{1,1}},//SShape
        {{0,-1},{0,0},{0,1},{0,2}},//LineShape
        {{-1,0},{0,0},{1,0},{0,1}},//TShape
        {{0,0},{1,0},{0,1},{1,1}},//SquareShape
        {{-1,-1},{0,-1},{0,0},{0,1}},//MirroredLShape
        {{1,-1},{0,-1},{0,0},{0,1}},//LShape
        {{0,0},{0,0},{0,0},{0,0}}//StoneShape (不会作为方块出现
    };
    //设置具体的描述
    for(int i=0;i<4;++i){
        for(int j=0;j<2;++j){
            coords[i][j]=coordsTable[shape][i][j];
        }
    }
    //设置抽象的描述
    pieceShape=shape;
}
void TetrixPiece::setRandomShape()//实现随机的设置一个形状
{
    setShape(TetrixShape(QRandomGenerator::global()->bounded(7)+1));//生成1-7之间的随机数 (不会选StoneShape
}
int TetrixPiece::minX() const
{
    int min=coords[0][0];
    for(int i=1;i<4;++i)
        min=qMin(min,coords[i][0]);
    return min;
}
int TetrixPiece::minY() const
{
    int min=coords[0][1];
    for(int i=1;i<4;++i)
        min=qMin(min,coords[i][1]);
    return min;
}
int TetrixPiece::maxX() const
{
    int max=coords[0][0];
    for(int i=1;i<4;++i)
        max=qMax(max,coords[i][0]);
    return max;
}
int TetrixPiece::maxY() const
{
    int max=coords[0][1];
    for(int i=1;i<4;++i)
        max=qMax(max,coords[i][1]);
    return max;
}
TetrixPiece TetrixPiece::rotatedLeft() const
{
    //逆时针旋转（y,-x);//y轴正方向向下
    if(pieceShape==SquareShape)return *this;
    TetrixPiece result;
    result.setShape(pieceShape);
    //旋转90度，改变四个小块的坐标
    for(int i=0;i<4;i++){
        result.setX(i,y(i));
        result.setY(i,-x(i));
    }
    return result;
}
TetrixPiece TetrixPiece::rotatedRight() const
{
    //顺时针旋转（-y,x）;
    if(pieceShape==SquareShape)return *this;
    TetrixPiece result;
    result.setShape(pieceShape);
    //旋转90度，改变四个小块的坐标
    for(int i=0;i<4;i++){
        result.setX(i,-y(i));
        result.setY(i,x(i));
    }
    return result;
}
