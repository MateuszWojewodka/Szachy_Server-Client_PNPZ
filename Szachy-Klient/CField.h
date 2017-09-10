#ifndef CFIELD_H
#define CFIELD_H

#include "CFigure.h"

class CField
{
    char x;
    int y;
    int xPosition;
    int yPosition;
    bool color;
    CFigure *visitor;

    public:
        CField(char x, int y, int xPosition, int yPosition, CFigure *visitor);
        void SetVisitor (CFigure *visitor);
        CFigure *GetVisitor ();
        char GetX();
        int GetY();
        int GetXPosition();
        int GetYPosition();
        bool GetColor();
        virtual ~CField();
};

#endif // CFIELD_H
