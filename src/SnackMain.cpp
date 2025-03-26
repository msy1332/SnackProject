#include <iostream>
#include "PutImage/PutImage.h"
#include <windows.h>
#include <easyx.h>
#include <cstdio>
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

    //测试透明贴图
    PutImage Test;
    IMAGE Test1;
    loadimage(&Test1,"../resources/Image/enemy3_down3.png");
    Test.Transparency_Map(-50,0,&Test1);
    system("pause");
    closegraph();
    return 0;
}