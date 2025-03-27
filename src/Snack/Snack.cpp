#include "Snack.h"

Snack::Snack()
{

}

Snack::~Snack()
{

}

void Snack::Init_Snack()
{
    this->SnackMaxSize=100;
    this->SnackSize=3;
    this->SnackDirections=right;
    this->snackxy[0].Snack_X=100;
    this->snackxy[0].Snack_Y=100;
    this->snackxy[1].Snack_X=90;
    this->snackxy[1].Snack_Y=100;
    this->snackxy[2].Snack_X=80;
    this->snackxy[2].Snack_Y=100;
}

void Snack::DrawSnack()
{
    for(int i=0;i<SnackSize;i++)
    {
        fillrectangle(snackxy[i].Snack_X,snackxy[i].Snack_Y,snackxy[i].Snack_X+10,snackxy[i].Snack_Y+10);
    }
}

void Snack::JudgementDirections()
{
    switch(this->SnackDirections)
    {
        case up:
            snackxy[0].Snack_Y+=10;
            break;
        caes down:
            snackxy[0].Snack_Y-=10;
            break;
        case left:
            snackxy[0].Snack_X-=10;
            break;
        case right:
            snackxy[0].Snack_X+=10;
            break;
    }
}

void Snack::SnackMove()
{
    for(int i=1;i<SnackSize;i++)
    {
        Snackxy[i]=Snackxy[i-1];
    }
}