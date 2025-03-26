#include <easyx.h>
#include <iostream>
#include <windows.h>
#include <cmath>

class PutImage
{
    public:
        PutImage();
        ~PutImage();
        void Transparency_Map(int x,int y,IMAGE *img);
        void Elf_Transparency_Map(int x, int y, int dstWidth, int dstHeight,IMAGE *img, int srcX, int srcY);
    private:
    protected:
};