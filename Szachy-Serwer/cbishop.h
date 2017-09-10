#ifndef CBISHOP_H
#define CBISHOP_H

#include "cfigure.h"

class CBishop : public CFigure
{
public:
    CBishop(Color color, CField *position, CChessboard *chessboard);
    vector <CField*> CheckWhichFieldsAreAvailable();
    string SerializationPosition ();

};

#endif // CBISHOP_H
