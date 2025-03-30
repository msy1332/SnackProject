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
    while(flag==0)
    {
        Foodxy.x=rand()%80*10;
        Foodxy.y=rand()%50*10;
        for(int i=0;i<snake.Size;i++)
        {
            if(Foodxy.x==snake.Snakexy[i].x&&Foodxy.y==snake.Snakexy[i].y)
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
    }
}

void Food::Draw_Food()
{
    setfillcolor(RED);
    solidcircle(Foodxy.x+5,Foodxy.y+5,5);
}

void Food::Eat_Food(Snake snake1)
{
    if(snake1.Head_X==Foodxy.x&&snake1.Head_Y==Foodxy.y)
    {
        flag=0;
        snake1.Speed-=10;
        snake1.Size++;
        snake1.Score+=50;
    }
}