#include <easyx.h>
#include <iostream>
#include <windows.h>

class PutImage
{
    public:
        PutImage();
        ~PutImage();
        void Transparency_Map(int x,int y,IMAGE *img);
        void Transparency_Image_S(int x,int y,IMAGE *img);
    private:
    protected:
};