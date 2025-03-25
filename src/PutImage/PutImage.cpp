#include "PutImage.h"
#include <easyx.h>

PutImage::PutImage()
{

}

PutImage::~PutImage()
{

}

void PutImage::Transparency_Map(int x,int y,IMAGE *img)
{
    DWORD *Master_Drawing=GetImageBuffer();
    // if(GetImageBuffer()!=nullptr)
    // {
    //    Master_Drawing=GetImageBuffer();
    // }
    std::cout<<"nullptr"<<std::endl;
    DWORD *Object_Map=GetImageBuffer(img);
    int win_w=getwidth();
    int win_h=getheight();
    int img_w=img->getwidth();
    int img_h=img->getheight();
    for(int i=0;i<img_w;i++)
    {
        for(int j=0;j<img_h;j++)
        {
            UCHAR alpha=Object_Map[j*img_w+i]>>24;
            if(alpha>200)
            {
                Master_Drawing[(y+j)*win_w+(x+i)]=Object_Map[j*img_w+i];
            }
        }
    }
}
void PutImage::Transparency_Image_S(int x,int y,IMAGE *img)
{
    //获取窗口的图片缓冲区数组指针（他是个一维数组）
    DWORD *Before_conversion_Buffer=GetImageBuffer();//使用GetImageBuffer获取图片缓冲区数组指针,如果没有参数就是获取窗口缓冲区指针
    //获取img的图片的缓冲区数组指针（他是个一维数组）
    DWORD *After_conversion_Buffer=GetImageBuffer(img);//使用GetImageBuffer获取图片缓冲区数组指针
    int win_w=getwidth();//获取窗口的宽度
    int win_h=getheight();//获取窗口的高度
    int img_w=img->getwidth();//获取图片宽度
    int img_h=img->getheight();//获取图片的高度
    int real_w=img_w;//将图片的宽度赋值给图片的实际宽度
    int real_h=img_h;//将图片的高度赋值给图片的实际高度
    if(x+img_w>win_w&&x>0)//判断是否超过右边界
    {
        real_w=win_w-x;//实际的宽度等于窗口的宽度减去贴图的x坐标
    }
    if(y+img_h>win_h&&y>0)//判断是否超过下边界
    {
        real_h=win_h-y;//实际的高度等于窗口的高度减去贴图的Y坐标
    }
    if(x<0)//判断是否超过左边界
    {
        After_conversion_Buffer+=abs(x)-1;//让指针偏移向后偏移
        real_w-=abs(x);//改变图片的实际的宽度
        x=0;//把x赋值为0
    }
    if(y<0)//判断是否超过上边界
    {
        After_conversion_Buffer+=abs(y)*img_w;//让指针向后偏移
        real_h-=abs(y);//改变他的高度
        y=0;//把y赋值为0
    }
    //遍历这个一维数组
    for(int i=0;i<real_w;i++)
    {
        for(int j=0;j<real_h;j++)
        {
            UCHAR alpha=After_conversion_Buffer[j*img_w+i]>>24;
            if(alpha>200)
            {
                Before_conversion_Buffer[(y+j)*win_w+(x+i)]=After_conversion_Buffer[j*img_w+i];
            }
        }
    }
}