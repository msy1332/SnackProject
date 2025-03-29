#include "Food.h"

Food::Food()
{

}

Food::~Food()
{

}

void Food::Init_Food()
{
    flag=0;
    number=1;
}

void Food::Generate_Food(Snake snake)
{
    srand(time(0));
    for(int i=0;i<number;i++)
    {
        while(!flag)
        {
            Foodxy.x=rand()%80*10;
            Foodxy.x=rand()%50*10;
            for(int i=0;i<snake.Size;i++)
            {
                if(Foodxy.x==snake.Snakexy[i].x&&Foodxy.y==snake.Snakexy[i].y)
                {
                    break;
                }
            }
        }
    }
    flag=1;
}

void Food::Draw_Food()
{
    setfillcolor(RED);
    solidcircle(Foodxy.x+5,Foodxy.y+5,5);
}