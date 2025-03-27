#include <iostream>
#include <easyx.h>
#include <cstdio>

struct SnackCoordinate
{
    int Snack_X;
    int Snack_Y;
};

#define up=65;
#define down=66;
#define left=67;
#define right=6;

#define SnackMaxSize 100;

class Snack
{
    public:
        Snack();
        ~Snack();
        void Init_Snack();
        void DrawSnack();
        void JudgementDirections();
        void SnackMove();
        int SnackDirections;
    private:
        int speed=500;
        int SnackSize;
        SnackCoordinate snackxy[SnackMaxSize];
    protected:
}