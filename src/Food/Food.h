#include "../Snake/Snake.h"
#include <iostream>
#include <easyx.h>
#include <time.h>

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
        void Init_Food();
        void Draw_Food();
        void Generate_Food(Snake snake);
    private:
        int number;
        int flag;
        Food_Position Foodxy;
    protected:
};