#include <iostream>
#include "Window/Window.h"
#include "PutImage/PutImage.h"
#include <windows.h>
using namespace std;

int main()
{
    IMAGE BackDrop_Img;
    IMAGE Test;
    
    Window window;
    PutImage putimg;
    window.Set_Window_Attribute(844,500,WHITE,EX_SHOWCONSOLE);
    if(!window.Create_Window())
    {
        closegraph();
        return -1;
    }
    window.Set_Bkcolor();
    cleardevice();
    // if(loadimage(&BackDrop_Img,"../resources/Image/SnackBackdrop.jpg",844,500)==0)
    // {
    //     closegraph();
    //     return -1;
    // }
    // putimage(0,0,&BackDrop_Img);
    // if(loadimage(&Test,"../resources/Image/Original_drawing.png")==0)
    // {
    //     closegraph();
    //     return -1;
    // }
    // putimg.Transparency_Map(0,0,&Test);
    bool run=true;
    cleardevice();
    // while(run)
    // {

    // }
    system("pause");
    closegraph();
    return 0;
}