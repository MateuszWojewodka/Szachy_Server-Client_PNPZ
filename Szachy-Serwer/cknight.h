#ifndef CKNIGHT_H
#define CKNIGHT_H

#include "cfigure.h"

class CKnight : public CFigure
{
public:
    CKnight(Color color, CField *position, CChessboard *chessboard);
    vector <CField*> CheckWhichFieldsAreAvailable();
    string SerializationPosition ();
};

#endif // CKNIGHT_H
