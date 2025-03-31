/*
#include "PutImage/PutImage.h"
#include <windows.h>
#include <iostream>
#include <easyx.h>
#include <cstring>
#include <string>
#include <time.h>
using namespace std;
IMAGE ButtonImage[3];
struct Button
{
    
    int Button_Width;
    int Button_Height;
    int Button_X;
    int Button_Y;
}button;

void Init_Button()
{
    char Path[50]="";
    for(int i=0;i<3;i++)
    {
        sprintf(Path,"../resources/Image/Button%d.png",i+1);
        loadimage(&ButtonImage[i],Path,707/4,249/4);
    }
    button.Button_Width=707/4;
    button.Button_Height=249/4;
    button.Button_X=312;
    button.Button_Y=380;
}

bool Button_Judgement(ExMessage msg)
{
    if(msg.x>button.Button_X&&msg.x<button.Button_X+button.Button_Width&&msg.y>button.Button_Y&&msg.y<button.Button_Y+button.Button_Height) return 1;
    else return 0;
}
enum Direction{
    Up      =65, 
    Down    =66, 
    Left    =67, 
    Right   =68
};
enum ButtonStatus{
    Normal  =0,
    Hover   =1,
    Pressed =2
};

struct Snake_Position
{
    int x;
    int y;
};

struct Snake
{
    int Size;
    int Score;
    int Speed;
    int Head_X;
    int Head_Y;
    int Direction;
    Snake_Position snakexy[100];
}snake;

void Init_Sanck()
{
    snake.Size=3;
    snake.Score=0;
    snake.Speed=100;
    snake.Direction=Right;
    snake.Head_X=100;
    snake.Head_Y=100;
    snake.snakexy[0].x=100;
    snake.snakexy[0].y=100;
    snake.snakexy[1].x=90;
    snake.snakexy[1].y=100;
    snake.snakexy[2].x=80;
    snake.snakexy[2].y=100;
}

void SnakeMove()
{
    for(int i=snake.Size-1;i>=0;i--)
    {
        snake.snakexy[i]=snake.snakexy[i-1];
    }
    snake.snakexy[0].x=snake.Head_X;
    snake.snakexy[0].y=snake.Head_Y;
}

void Judge_Direction()
{
    switch(snake.Direction)
    {
        case Up:
            snake.Head_Y-=10;
            break;
        case Down:
            snake.Head_Y+=10;
            break;
        case Left:
            snake.Head_X-=10;
            break;
        case Right:
            snake.Head_X+=10;
            break;
    }
}
void DrawSnake()
{
    setfillcolor(RGB(32, 172, 74));
    // setlinecolor(RGB(206, 239, 107));
    for(int i=0;i<snake.Size;i++)
    {
        solidroundrect(snake.snakexy[i].x,snake.snakexy[i].y,snake.snakexy[i].x+10,snake.snakexy[i].y+10,5,5);
    }
}

struct Food
{
    int x;
    int y;
    int flag;
}food;

void Generate_Food()
{
    srand(time(0));
    if(food.flag==0)
    {
        while(food.flag!=1)
        {
            food.x=rand()%80*10;
            food.y=rand()%50*10;
            for(int i=0;i<snake.Size;i++)
            {
                if(snake.snakexy[i].x==food.x&&snake.snakexy[i].y==food.y)
                {
                    break;
                }
                else
                {
                    food.flag=1;
                }
            }
        }
    }
}

void DrawFood()
{
    setfillcolor(RED);
    solidcircle(food.x+5,food.y+5,5);
}

void Eat_Food()
{
    if(snake.Head_X==food.x&&snake.Head_Y==food.y)
    {
        food.flag=0;
        snake.Size++;
        snake.Speed-=10;
        snake.Score+=50;
    }
}

void Score()
{
    char score[10]="";
    sprintf(score,"score:%d",snake.Score);
    settextcolor(BLACK);
    outtextxy(0,0,score);
}

bool Judge_Game()
{
    bool Game=true;
    for(int i=1;i<snake.Size;i++)
    {
        if(snake.Head_X==snake.snakexy[i].x&&snake.Head_Y==snake.snakexy[i].y)
        {
            Game=false;
            break;
        }
    }
    if(snake.Head_X<0||snake.Head_X>=800||snake.Head_Y<0||snake.Head_Y>=500)
    {
        Game=false;
    }
    return Game;
}

int main()
{
    //创建窗口
    initgraph(800,500,EX_SHOWCONSOLE);
    setbkcolor(RGB(164, 238, 186));
    cleardevice();

    //加载背景图片
    IMAGE BackImage;
    loadimage(&BackImage,"../resources/Image/BackImage.png");
    putimage(0,0,&BackImage);

    //加载按钮图片
    Init_Button();
    putimage(312,380,&ButtonImage[0]);

    //定义透明贴图类变量
    PutImage put_image;

    //定义鼠标消息
    ExMessage msg;

    bool Game_Status=true;//游戏的运行状态
    bool Game_Start=false;//游戏的开始状态
    int Button_Status=Normal;

    int Fps=60/1000;
    int StartTime=0;
    int StopTime=0;
    //初始化蛇
    Init_Sanck();

    //游戏的主循环
    while(Game_Status)
    {
        // StartTime=clock();
        if(peekmessage(&msg,EX_MOUSE | EX_KEY))
        {
            if(!Game_Start)
            {
                switch(msg.message)
                {
                    case WM_LBUTTONDOWN:
                        if(Button_Judgement(msg)) 
                        {
                            Button_Status=Pressed;
                            Game_Start=true;
                            cout<<"Play"<<endl;
                            Init_Sanck();
                            cleardevice();
                        }
                        break;
                    case WM_LBUTTONUP:
                        if(Button_Judgement(msg)) Button_Status=Hover;
                        break;
                    default:
                        if(Button_Judgement(msg)) Button_Status=Hover;
                        else Button_Status=Normal;
                        break;
                }
            }
            else
            {
                switch(msg.vkcode)
                {
                    case 'w':
                    case 'W':
                    case VK_UP:
                        if(snake.Direction!=Down)   snake.Direction=Up;
                        break;
                    case 's':
                    case 'S':
                    case VK_DOWN:
                        if(snake.Direction!=Up)     snake.Direction=Down;
                        break;
                    case 'a':
                    case 'A':
                    case VK_LEFT:
                        if(snake.Direction!=Right)  snake.Direction=Left;
                        break;
                    case 'd':
                    case 'D':
                    case VK_RIGHT:
                        if(snake.Direction!=Left)   snake.Direction=Right;
                        break;                
                }
            }
        }
        BeginBatchDraw();
        cleardevice();
        if(!Game_Start)
        {
            if(Button_Status==Pressed) 
            {
                putimage(0,0,&BackImage);
                put_image.Transparency_Map(button.Button_X,button.Button_Y,&ButtonImage[2]);
            }
            else if(Button_Status==Hover)
            {
                putimage(0,0,&BackImage);
                put_image.Transparency_Map(button.Button_X,button.Button_Y,&ButtonImage[1]);
            }
            else
            {
                putimage(0,0,&BackImage);
                put_image.Transparency_Map(button.Button_X,button.Button_Y,&ButtonImage[0]);
            }
        }
        else
        {
            Generate_Food();
            DrawFood();
            DrawSnake();
            Judge_Direction();
            SnakeMove();
            Eat_Food();
            Score();
            if(!Judge_Game())
            {
                Game_Start=false;
            }
            Sleep(snake.Speed);
        }
        EndBatchDraw();
        // StopTime=clock();
        // if(StopTime-StartTime<Fps)
        // {
        //     Sleep(StopTime-StartTime);
        // }
    }

    system("pause");
    closegraph();
    return 0;
}
*/
#include "PutImage/PutImage.h"
#include "Snake/Snake.h"
#include "Game/Game.h"
#include "Food/Food.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <easyx.h>
#include <cstring>
#include <string>
#include <time.h>
#include <cmath>
#pragma comment(lib,"Winmm.lib")
using namespace std;
IMAGE ButtonImage[3];
struct Button
{
    
    int Button_Width;
    int Button_Height;
    int Button_X;
    int Button_Y;
}button;

void Init_Button()
{
    char Path[50]="";
    for(int i=0;i<3;i++)
    {
        sprintf(Path,"../resources/Image/Button%d.png",i+1);
        loadimage(&ButtonImage[i],Path,707/4,249/4);
    }
    button.Button_Width=707/4;
    button.Button_Height=249/4;
    button.Button_X=312;
    button.Button_Y=380;
}

bool Button_Judgement(ExMessage msg)
{
    if(msg.x>button.Button_X&&msg.x<button.Button_X+button.Button_Width&&msg.y>button.Button_Y&&msg.y<button.Button_Y+button.Button_Height) return 1;
    else return 0;
}

enum ButtonStatus{
    Normal  =0,
    Hover   =1,
    Pressed =2
};

enum GameStatus{
    Menu       =0,
    BeginGame  =1,
    EndGame    =2
};

int main()
{
    //创建窗口
    initgraph(800,500,EX_SHOWCONSOLE);
    setbkcolor(RGB(164, 238, 186));
    cleardevice();

    //加载背景图片
    IMAGE BackImage;
    loadimage(&BackImage,"../resources/Image/BackImage.png");
    putimage(0,0,&BackImage);

    //加载结束图片
    IMAGE EndImage;
    loadimage(&EndImage,"../resources/Image/GameOver.png");

    //加载按钮图片
    Init_Button();
    putimage(312,380,&ButtonImage[0]);

    //定义透明贴图类变量
    PutImage put_image;

    //定义鼠标消息
    ExMessage msg;

    int Game_Status=Menu;//游戏的运行状态
    int Game_Start=Menu;//游戏的开始状态
    int Button_Status=Normal;
    bool Running=true;

    Snake snake;
    Food food;
    Game game;
    //初始化蛇
    snake.Init_Snake();
    food.Init_Food();

    int Fps=16/1000;
    int StartTime=0;
    int StopTime=0;
    int Timepiece=0;
    int LastTimeMove=clock();

    mciSendString("open ../resources/Music/SnakeBgm.mp3 alias bgm",NULL,0,NULL);
    mciSendString("open ../resources/Music/j57gx-hru1n.mp3 alias bgm1",NULL,0,NULL);
    int MusicStatus=0;

    char Scorestring[50]="";

    //游戏的主循环
    while(Running)
    {
        StartTime=clock();
        if(peekmessage(&msg,EX_MOUSE | EX_KEY))
        {
            if(Game_Status==Menu)
            {
                switch(msg.message)
                {
                    case WM_LBUTTONDOWN:
                        if(Button_Judgement(msg)) 
                        {
                            Button_Status=Pressed;
                            Game_Status=BeginGame;
                            snake.Init_Snake();
                            mciSendString("play bgm repeat",NULL,0,NULL);
                            cleardevice();
                        }
                        break;
                    case WM_LBUTTONUP:
                        if(Button_Judgement(msg)) Button_Status=Hover;
                        break;
                    default:
                        if(Button_Judgement(msg)) Button_Status=Hover;
                        else Button_Status=Normal;
                        break;
                }
            }
            else if(Game_Status==BeginGame)
            {
                switch(msg.message)
                {
                    case WM_KEYDOWN:
                        switch(msg.vkcode)
                        {
                            case 'w':
                            case 'W':
                            case VK_UP:
                                if(snake.Direction!=Down)   snake.Direction=Up;
                                cout<<"W"<<endl;
                                break;
                            case 's':
                            case 'S':
                            case VK_DOWN:
                                cout<<"S"<<endl;
                                if(snake.Direction!=Up)   snake.Direction=Down;
                                break;
                            case 'a':
                            case 'A':
                            case VK_LEFT:
                                cout<<"A"<<endl;
                                if(snake.Direction!=Right)   snake.Direction=Left;
                                break;
                            case 'd':
                            case 'D':
                            case VK_RIGHT:
                                cout<<"D"<<endl;
                                if(snake.Direction!=Left)   snake.Direction=Right;
                                break;  
                            case VK_SPACE:
                                if(MusicStatus==0)
                                {
                                    mciSendString("play bgm1 repeat",NULL,0,NULL);
                                    MusicStatus=1;  
                                }
                                else
                                {
                                    mciSendString("stop bgm1",NULL,0,NULL);    
                                    MusicStatus=0;
                                }                       
                        }
                    break;
                }
            }
            else
            {
                switch(msg.message)
                {
                    case WM_KEYDOWN:
                        switch(msg.vkcode)
                        {
                            case VK_ESCAPE:
                                Init_Button();
                                Button_Status=Normal;
                                Game_Status=Menu;
                                break;
                            case 'R':
                            case 'r':
                                snake.Init_Snake();
                                Game_Status=BeginGame;
                                mciSendString("play bgm repeat",NULL,0,NULL);
                                break;
                        }
                        break;
                }
            }
        }
        BeginBatchDraw();
        cleardevice();
        if(Game_Status==Menu)
        {
            if(Button_Status==Pressed) 
            {
                putimage(0,0,&BackImage);
                put_image.Transparency_Map(button.Button_X,button.Button_Y,&ButtonImage[2]);
            }
            else if(Button_Status==Hover)
            {
                putimage(0,0,&BackImage);
                put_image.Transparency_Map(button.Button_X,button.Button_Y,&ButtonImage[1]);
            }
            else
            {
                putimage(0,0,&BackImage);
                put_image.Transparency_Map(button.Button_X,button.Button_Y,&ButtonImage[0]);
            }
        }
        else if(Game_Status==BeginGame)
        {
            food.Generate_Food(snake);
            setfillcolor(RGB(32, 172, 74));
            for(int i=0;i<snake.Size;i++)
            {
                solidroundrect(snake.Snakexy[i].x,snake.Snakexy[i].y,snake.Snakexy[i].x+10,snake.Snakexy[i].y+10,10,10);
            }
            setfillcolor(RED);
            solidcircle(food.Foodxy.x+5,food.Foodxy.y+5,5); 
            // food.Eat_Food(snake);
            for(int i=0;i<snake.Size;i++)
            {
                cout<<"x:"<<snake.Snakexy[i].x<<"\ty:"<<snake.Snakexy[i].y<<"\ti:"<<i<<"\tsize:"<<snake.Size<<"\tfoodx:"<<food.Foodxy.x<<"\tfoody:"<<food.Foodxy.y<<"\tspeed:"<<snake.Speed<<endl;
            }
            if(snake.Head_X==food.Foodxy.x&&snake.Head_Y==food.Foodxy.y)
            {
                food.flag=0;
                snake.Speed=max(10,snake.Speed-=100);
                snake.Size++;
                snake.Score+=50;
            }
            if(game.Game_End(snake))
            {
                Game_Status=EndGame;
                mciSendString("stop bgm",NULL,0,NULL);
            }
            sprintf(Scorestring,"score:%d",snake.Score);
            settextcolor(BLACK);
            outtextxy(0,0,Scorestring);
        }
        else
        {
            put_image.Transparency_Map(0,0,&EndImage);
            setfillcolor(RGB(32, 172, 74));
            for(int i=0;i<snake.Size;i++)
            {
                solidroundrect(snake.Snakexy[i].x,snake.Snakexy[i].y,snake.Snakexy[i].x+10,snake.Snakexy[i].y+10,10,10);
            }
            setfillcolor(RED);
            solidcircle(food.Foodxy.x+5,food.Foodxy.y+5,5); 
        }
        EndBatchDraw();
        if(Game_Status==BeginGame)
        {
            Timepiece=clock();
            if(Timepiece-LastTimeMove>=snake.Speed) 
            {
                snake.Judgment_Snake_Direction();
                snake.Move_Snake();
                LastTimeMove=Timepiece;
            }
        }
        StopTime=clock();
        if(StopTime-StartTime<Fps)
        {
            Sleep(Fps-StopTime-StartTime);
        }
    }

    system("pause");
    closegraph();
    return 0;
}