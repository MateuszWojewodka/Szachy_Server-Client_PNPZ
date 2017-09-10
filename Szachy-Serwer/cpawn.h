#ifndef CPAWN_H
#define CPAWN_H

#include "cfigure.h"

class CPawn : public CFigure
{
public:
    CPawn(Color color, CField *position, CChessboard *chessboard);
    vector <CField*> CheckWhichFieldsAreAvailable();
    string SerializationPosition ();
};

#endif // CPAWN_H
