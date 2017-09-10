#include "CFigure.h"

CFigure::CFigure(char type, bool color)
{
    this->type = type;
    this->color = color;
}

char CFigure::GetType()
{
    return type;
}

bool CFigure::GetColor ()
{
    return color;
}
CFigure::~CFigure()
{
    //dtor
}
