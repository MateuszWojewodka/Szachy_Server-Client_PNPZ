#ifndef CCASTEL_H
#define CCASTEL_H

#include "cfigure.h"

class CCastel : public CFigure
{
public:
    CCastel(Color color, CField *position, CChessboard *chessboard);
    vector <CField*> CheckWhichFieldsAreAvailable();
    string SerializationPosition ();
};

#endif // CCASTEL_H
