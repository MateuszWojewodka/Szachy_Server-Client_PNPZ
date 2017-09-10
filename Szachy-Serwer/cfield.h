#ifndef CFIELD_H
#define CFIELD_H

#include <iostream>

class CFigure;

using namespace std;

class CField
{
public:
    enum Color { white, black };
private:
    char x;
    int y;
    CFigure *visitor;
    Color color;
public:
    CField(char x, int y);
    void SetVisitor (CFigure *visitor);
    char GetX();
    int GetY();
    CFigure *GetVisitor ();
};

#endif // CFIELD_H
