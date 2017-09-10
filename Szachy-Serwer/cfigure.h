#ifndef CFIGURE_H
#define CFIGURE_H

#include "cfield.h"
#include "cchessboard.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class CFigure
{
public:
    enum Color { white, black };

protected:
    Color color;
    CField *position;
    CChessboard *chessboard;

public:
    CFigure(Color color, CField *position, CChessboard *chessboard);
    virtual vector <CField*> CheckWhichFieldsAreAvailable () = 0;
    virtual string SerializationPosition () = 0;
    string SerializationAvailablePosition ();

    Color GetColor ();
    CField *GetPosition();

    void SetPosition (CField *position);
};

std::string to_string( int i );

#endif // CFIGURE_H
