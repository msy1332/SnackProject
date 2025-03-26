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
    DWORD *Object_Map=GetImageBuffer(img);
    int win_w=getwidth();
    int win_h=getheight();
    int img_w=img->getwidth();
    int img_h=img->getheight();
    int real_w=img_w;
    int real_h=img_h;
    if(x+img_w>win_w)
    {
        real_w=win_w-x;
    }
    if(y+img_h>win_h)
    {
        real_h=win_h-y;
    }
    if(x<0)
    {
        Object_Map+=abs(x);
        real_w-=abs(x);
        x=0;
    }
    if(y<0)
    {
        Object_Map+=abs(y)*img_w;
        real_h-=abs(y);
        y=0;
    }
    for(int i=0;i<real_w;i++)
    {
        for(int j=0;j<real_h;j++)
        {
            UCHAR alpha=Object_Map[j*img_w+i]>>24;
            if(alpha>200)
            {
                Master_Drawing[(y+j)*win_w+(x+i)]=Object_Map[j*img_w+i];
            }
        }
    }
}

void PutImage::Elf_Transparency_Map(int x, int y, int dstWidth, int dstHeight,IMAGE *img, int srcX, int srcY)
{
    DWORD *Master_Drawing=GetImageBuffer();
    DWORD *Object_Map=GetImageBuffer(img);
    int win_w=getwidth();
    int win_h=getheight();
    int img_w=img->getwidth();
    int img_h=img->getheight();
    int real_w=dstWidth;
    int real_h=dstHeight;
    Object_Map+=srcX+y*img_w;
    if(x+img_w>win_w)
    {
        real_w=win_w-x;
    }
    if(y+img_h>win_h)
    {
        real_h=win_h-y;
    }
    if(x<0)
    {
        Object_Map+=abs(x);
        real_w-=abs(x);
        x=0;
    }
    if(y<0)
    {
        Object_Map+=abs(y)*img_w;
        real_h-=abs(y);
        y=0;
    }
    for(int i=0;i<real_w;i++)
    {
        for(int j=0;j<real_h;j++)
        {
            UCHAR alpha=Object_Map[j*img_w+i]>>24;
            if(alpha>200)
            {
                Master_Drawing[(y+j)*win_w+(x+i)]=Object_Map[j*img_w+i];
            }
        }
    }
}