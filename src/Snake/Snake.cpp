#include "Snake.h"

Snake::Snake()
{

}

Snake::~Snake()
{

}

void Snake::Init_Snake()
{
    Score           =0;
    Size            =3;
    Speed           =500;
    Direction       =Right;
    Head_X          =100;
    Head_Y          =100;
    Snakexy[0].x    =100;
    Snakexy[0].y    =100;
    Snakexy[1].x    =90;
    Snakexy[1].y    =100;
    Snakexy[2].x    =80;
    Snakexy[2].y    =100;
}

void Snake::Judgment_Snake_Direction()
{
    switch(Direction)
    {
        case Up:
            Head_Y-=10;
            break;
        case Down:
            Head_Y+=10;
            break;
        case Left:
            Head_X-=10;
            break;
        case Right:
            Head_X+=10;
            break;
    }
}

void Snake::Move_Snake()
{
    for(int i=Size-1;i>=0;i--)
    {
        Snakexy[i]=Snakexy[i-1];
    }
    Snakexy[0].x=Head_X;
    Snakexy[0].y=Head_Y;
}

void Snake::Draw_Snake()
{
    setfillcolor(RGB(32, 172, 74));
    for(int i=0;i<Size;i++)
    {
        solidroundrect(Snakexy[i].x,Snakexy[i].y,Snakexy[i].x+10,Snakexy[i].y+10,10,10);
    }
}