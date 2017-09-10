#include "CField.h"

CField::CField(char x, int y, int xPosition, int yPosition, CFigure *visitor)
{
    this->x = x;
    this->y = y;
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    if ( (x%2 != 0 && (int)y%2 != 0) || (x%2 == 0 && (int)y%2 == 0) )
        color = 1;
    else
        color = 0;
    this->visitor = visitor;
}

void CField::SetVisitor (CFigure *visitor)
{
    this->visitor = visitor;
}

CFigure *CField::GetVisitor()
{
    return visitor;
}

char CField::GetX()
{
    return x;
}

int CField::GetY()
{
    return y;
}

int CField::GetXPosition()
{
    return xPosition;
}

int CField::GetYPosition()
{
    return yPosition;
}

bool CField::GetColor ()
{
    return color;
}

CField::~CField()
{
    //dtor
}
