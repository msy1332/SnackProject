#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

bool Game::Game_End(Snake snake)
{
    bool Game_End=false;
    for(int i=1;i<snake.Size;i++)
    {
        if(snake.Head_X==snake.Snakexy[i].x&&snake.Head_Y==snake.Snakexy[i].y)
        {
            Game_End=true;
            break;
        }
    }
    if(snake.Head_X<0||snake.Head_X>=800||snake.Head_Y<0||snake.Head_Y>=500)
    {
        Game_End=true;
    }
    return Game_End;
}
