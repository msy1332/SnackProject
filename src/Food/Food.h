#include "../Snake/Snake.h"
#include <iostream>
#include <easyx.h>
#include <time.h>
#pragma once

#define Food_Max 100

struct Food_Position
{
    int x;
    int y;
};

class Food
{
    public:
        Food();
        ~Food();
        int number;
        int flag;
        void Init_Food();
        void Draw_Food();
        void Eat_Food(Snake snake);
        Food_Position Foodxy;
        void Generate_Food(Snake snake1); 
    private:
        // Food_Position Foodxy[Food_Max];
    protected:
};