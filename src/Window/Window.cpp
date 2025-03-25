#include "window.h"

Window::Window()
{

}

Window::~Window()
{

}

bool Window::Create_Window()
{
    HWND hwdn= initgraph(this->width,this->height,this->flag);
    if(hwdn==nullptr)
    {
        std::cerr<<"No initgraph"<<std::endl;
        return -1;
    }
    else
    {
        return 0;
    }
}
void Window::Set_Bkcolor()
{
    setbkcolor(this->color);
}
void Window::Set_Window_Attribute(int width,int height,COLORREF color,int flag)
{
    this->width=width;
    this->height=height;
    this->color=color;
    this->flag=flag;
}