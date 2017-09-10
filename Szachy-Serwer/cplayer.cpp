#include "cplayer.h"

CPlayer::CPlayer(vector<CFigure *> myFigure)
{
    this->myFigure = myFigure;
    markedFigure = NULL;
    markedField = NULL;
}

void CPlayer::SetMarkedFigure(CFigure *markedFigure)
{
    for (int i = 0; i < myFigure.size(); i++)
    {
        if (myFigure[i] == markedFigure)
            this->markedFigure = markedFigure;
    }
}

CFigure *CPlayer::GetMarkedFigure()
{
    return markedFigure;
}
