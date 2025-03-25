#include <easyx.h>
#include <windows.h>
#include <iostream>

class Window
{
    public:
        Window();
        ~Window();
        void Set_Bkcolor();
        bool Create_Window();
        void Set_Window_Attribute(int width,int height,COLORREF color=BLACK,int flag=0);
    private:
        int flag;
        int width;
        int height;
        COLORREF color;
    protected:
};