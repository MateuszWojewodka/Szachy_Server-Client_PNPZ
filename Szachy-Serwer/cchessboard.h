#ifndef CCHESSBOARD_H
#define CCHESSBOARD_H

#include "cfield.h"
#include <vector>

using namespace std;

class CChessboard
{
    vector< vector<CField*> > field;
public:
    CChessboard();
    CField *GetField (char sign, int digit);
};

#endif // CCHESSBOARD_H
