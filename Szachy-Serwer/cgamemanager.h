#ifndef CGAMEMANAGER_H
#define CGAMEMANAGER_H

#include "cchessboard.h"
#include "cplayer.h"
#include "cbishop.h"
#include "ccastel.h"
#include "cpawn.h"
#include "cking.h"
#include "cknight.h"
#include "cqueen.h"

#include <cstdlib>
#include <iostream>
#include <string>

class CGameManager
{
    CChessboard *chessboard;
    vector <CFigure*> figureW;
    vector <CFigure*> figureB;
    CPlayer *playerW;
    CPlayer *playerB;
    CPlayer *currentPlayer;

public:
    CGameManager();
    string CurrentPlayerAction(string request);
    void DeleteFigure(char x, int y);
    string SerializationFigurePosition ();
    string SerializationAvailableFields (char x, int y);
	bool IfMyKingIsInDanger();
	bool IfMyKingWillBeInDangerAfterMove(char x, int y);
};

#endif // CGAMEMANAGER_H
