#include <iostream>
#include "PutImage/PutImage.h"
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

    IMAGE PlayText;
    IMAGE PlayText1;
    loadimage(&PlayText,"../resources/Image//Text.png");
    loadimage(&PlayText1,"../resources/Image//Text.png",200*1.1,80*1.1);

    int Play_X=324;
    int play_Y=350;
    int PlayText_Width=PlayText.getwidth();
    int PlayText_Height=PlayText.getheight();

    PutImage putimage;
    putimage.Transparency_Map(324,350,&PlayText);
    //putimage.Transparency_Map(312,350,&PlayText1);
    int PlayText_Status=Normal;

    ExMessage msg;

    bool Game_Status=true;
    bool Game_Start=false;
    while(Game_Status)
    {
        if(peekmessage(&msg,EX_MOUSE|EX_KEY))
        {
            if(Game_Start)
            {
                switch(msg.message)
                {
                    case WM_LBUTTONDOWN:
                        if(msg.x>Play_Y&&msg.x<Play_X+PlayText_Width&&msg.y>Play_Y&&msg.y<Play_Y+PlayText_Height)
                        {
                            PlayText_Status=Pressed;
                        }
                        break;
                    case WM_LBUTTONUP:
                        if(msg.x>Play_Y&&msg.x<Play_X+PlayText_Width&&msg.y>Play_Y&&msg.y<Play_Y+PlayText_Height)
                        {
                            PlayText_Status=Hover;
                        }
                        break;
                    default:
                        if(msg.x>Play_Y&&msg.x<Play_X+PlayText_Width&&msg.y>Play_Y&&msg.y<Play_Y+PlayText_Height)
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
                switch(msg.message)
                {
                    case WM_KEYDOWN:
                        break;
                    case WM_KEYUP:
                        break;
                }
            }
        }
    }

    system("pause");
    closegraph();
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