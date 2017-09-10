#ifndef CQUEEN_H
#define CQUEEN_H

#include "ccastel.h"
#include "cbishop.h"

class CQueen : public CFigure
{
public:
    CQueen(Color color, CField *position, CChessboard *chessboard);
    vector <CField*> CheckWhichFieldsAreAvailable();
    string SerializationPosition ();
};

#endif // CQUEEN_H
