#ifndef CKING_H
#define CKING_H

#include "cfigure.h"

class CKing : public CFigure
{
public:
    CKing(Color color, CField *position, CChessboard *chessboard);
    vector <CField*> CheckWhichFieldsAreAvailable();
    string SerializationPosition ();
};

#endif // CKING_H
