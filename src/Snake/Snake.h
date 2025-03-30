#include <iostream>
#include <easyx.h>
#include <cmath>
#pragma once

#define Snake_Size_Mux 100

struct Snake_Position
{
    int x;
    int y;
};

enum Snake_Direction{
    Up      =65,
    Down    =66,
    Left    =67,
    Right   =68
};

class Snake
{
    public:
        Snake();
        ~Snake();
        int Size;
        int Speed;
        int Score;
        int Head_X;
        int Head_Y;
        int Direction;
        void Init_Snake();
        void Draw_Snake();
        void Move_Snake();
        void Judgment_Snake_Direction();
        Snake_Position Snakexy[Snake_Size_Mux];
    private:
    protected:
};