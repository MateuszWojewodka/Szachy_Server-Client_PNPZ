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
	class CGameFinished
	{
	#pragma region GameFinishedClassDeff



		bool IfWhiteWon;
		bool IfBlackWon;

	public:
		CGameFinished() { IfWhiteWon = false; IfBlackWon = false; }
		void WhiteWon() { IfWhiteWon = true; IfBlackWon = false; }
		void BlackWon() { IfBlackWon = true; IfWhiteWon = false; }
		string WhoWon()
		{
			if (IfWhiteWon) return "white";
			else if (IfBlackWon) return "black";
			else return "noone";
		}
	#pragma endregion
	};

    CChessboard *chessboard;
    vector <CFigure*> figureW;
    vector <CFigure*> figureB;
    CPlayer *playerW;
    CPlayer *playerB;
    CPlayer *currentPlayer;
	CGameFinished GameFinishedFlag;

public:
    CGameManager();
    string CurrentPlayerAction(string request);
    void DeleteFigure(char x, int y);
    string SerializationFigurePosition ();
    string SerializationAvailableFields (char x, int y);
	bool IfMyKingIsInDanger(CField *myKingsField);
	bool IfMyKingWillBeInDangerAfterMove(CField *fromField, CField *toField);
	bool IfThereIsCheckMate();
};

#endif // CGAMEMANAGER_H
