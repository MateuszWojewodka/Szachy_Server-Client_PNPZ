#ifndef CPLAYER_H
#define CPLAYER_H

#include "cfigure.h"

#include <vector>

using namespace std;

class CPlayer
{
    vector <CFigure*> myFigure;
    CFigure *markedFigure;
    CField *markedField;
public:
    CPlayer(vector <CFigure*> myFigure);
    void SetMarkedFigure (CFigure *markedFigure);
    CFigure *GetMarkedFigure ();
};

#endif // CPLAYER_H
