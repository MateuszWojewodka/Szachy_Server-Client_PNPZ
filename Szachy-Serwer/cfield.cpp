#include "cfield.h"

CField::CField(char x, int y)
{
    this->x = x;
    this->y = y;
    visitor = NULL;
    if ( (x%2 != 0 && (int)y%2 != 0) || (x%2 == 0 && (int)y%2 == 0) )
        color = black;
    else
        color = white;
}

void CField::SetVisitor(CFigure *visitor)
{
    this->visitor = visitor;
}

char CField::GetX()
{
    return x;
}

int CField::GetY()
{
    return y;
}

CFigure *CField::GetVisitor()
{
    return visitor;
}

