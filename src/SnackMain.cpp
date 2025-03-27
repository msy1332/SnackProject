#include <iostream>
#include "PutImage/PutImage.h"
#include "Snack/Snack.h"
#include <windows.h>
#include <easyx.h>
#include <cstdio>
#define Normal   1
#define Hover    0
#define Pressed -1
using namespace std;
int main()
{
    //创建窗口和设置背景颜色
    initgraph(844,500,EX_SHOWCONSOLE);
    setbkcolor(WHITE);
    cleardevice();

    //加载背景图片和输出背景图片
    IMAGE BackDrop_Img;
    loadimage(&BackDrop_Img,"../resources/Image/SnackBackdrop.jpg",844,500);
    putimage(0,0,&BackDrop_Img);

    //加载按钮
    PutImage put_image;
    IMAGE Button1;
    IMAGE Button2;
    IMAGE Button3;
    int PlayText_Status=Normal;
    loadimage(&Button1,"../resources/Image/Button1.png",707/4,249/4);
    loadimage(&Button2,"../resources/Image/Button2.png",707/4,249/4);
    loadimage(&Button3,"../resources/Image/Button3.png",707/4,249/4);

    int Button_X=344;
    int Button_Y=380;
    int Button_Width=Button1.getwidth();
    int Button_Height=Button1.getheight(); 

    //定义鼠标消息
    ExMessage msg;

    bool Game_Status=true;//游戏的运行状态
    bool Game_Start=false;//游戏的开始状态

    Snack snack;
    snack.Init_Snack();

    //游戏的主循环
    while(Game_Status)
    {
        //获取鼠标消息
        if(peekmessage(&msg,EX_MOUSE|EX_KEY))
        {
            //判断游戏是否开始
            if(!Game_Start)
            {
                switch(msg.message)
                {
                    case WM_LBUTTONDOWN:
                        if(msg.x>Button_X&&msg.x<Button_X+Button_Width&&msg.y>Button_Y&&msg.y<Button_Y+Button_Height)
                        {
                            PlayText_Status=Pressed;
                        }
                        break;
                    case WM_LBUTTONUP:
                        if(msg.x>Button_X&&msg.x<Button_X+Button_Width&&msg.y>Button_Y&&msg.y<Button_Y+Button_Height)
                        {
                            Game_Start=true;
                            PlayText_Status=Hover;
                        }
                        break;
                    default:
                        if(msg.x>Button_X&&msg.x<Button_X+Button_Width&&msg.y>Button_Y&&msg.y<Button_Y+Button_Height)
                        {
                            PlayText_Status=Hover;
                        }
                        else
                        {
                            PlayText_Status=Normal;
                        }
                        break;
                }
            }
            else
            {
                //获取按键消息
                switch(msg.message)
                {
                    case WM_KEYDOWN://按键按下消息
                        switch(msg.vkcode)
                        {
                            case 'w':
                            case 'W':
                                cout<<"W Press"<<endl;
                                break;
                            case 's':
                            case 'S':
                                cout<<"S Press"<<endl;
                                break;
                            case 'd':
                            case 'D':
                                cout<<"D Press"<<endl;
                                break;
                            case 'n':
                            case 'N':
                                cout<<"N Press"<<endl;
                                break;
                        }
                        break;
                    case WM_KEYUP://按键弹起消息
                    switch(msg.vkcode)
                    {
                        case 'w':
                        case 'W':
                            cout<<"W Bounce UP"<<endl;
                            break;
                        case 's':
                        case 'S':
                            cout<<"S Bounce UP"<<endl;
                            break;
                        case 'd':
                        case 'D':
                            cout<<"D Bounce UP"<<endl;
                            break;
                        case 'n':
                        case 'N':
                            cout<<"N Bounce UP"<<endl;
                            break;
                    }
                        break;
                }
            }
        }
        BeginBatchDraw();//开始双缓冲绘图
        cleardevice();//清屏
        if(!Game_Start)//判断游戏是否开始游戏
        {
            if(PlayText_Status==Pressed)
            {
                putimage(0,0,&BackDrop_Img);
                put_image.Transparency_Map(344,380,&Button3);
            }
            else if(PlayText_Status==Hover)
            {
                putimage(0,0,&BackDrop_Img);
                put_image.Transparency_Map(344,380,&Button1);
            }
            else
            {
                putimage(0,0,&BackDrop_Img);
                put_image.Transparency_Map(344,380,&Button2);
            }
        }
        else
        {
            snack.
        }
        EndBatchDraw();//结束双缓冲绘图
    }

    system("pause");//暂停窗口
    closegraph();//关闭窗口
    return 0;
}
/*
    //测试透明贴图
    PutImage Test;
    IMAGE Test1;
    loadimage(&Test1,"../resources/Image/enemy3_down3.png");
    //Test.Transparency_Map(-50,0,&Test1);

    IMAGE Test2;
    loadimage(&Test2,"../resources/Image/Sprite_table_Img.png");
    Test.Elf_Transparency_Map(0,0,69,95,&Test2,69*2,0);
*/