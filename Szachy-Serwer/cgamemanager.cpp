#include "cgamemanager.h"

CGameManager::CGameManager()
{
    chessboard = new CChessboard ();

    for (int i = 0; i < 8; i++)
        figureW.push_back(new CPawn(CFigure::white, chessboard->GetField(65+i,2), chessboard)); //[0-7]
    figureW.push_back(new CCastel(CFigure::white, chessboard->GetField('A',1), chessboard)); //8
    figureW.push_back(new CCastel(CFigure::white, chessboard->GetField('H',1), chessboard)); //9
    figureW.push_back(new CKnight(CFigure::white, chessboard->GetField('B',1), chessboard)); //10
    figureW.push_back(new CKnight(CFigure::white, chessboard->GetField('G',1), chessboard)); //11
    figureW.push_back(new CBishop(CFigure::white, chessboard->GetField('C',1), chessboard)); //12
    figureW.push_back(new CBishop(CFigure::white, chessboard->GetField('F',1), chessboard)); //13
    figureW.push_back(new CKing(CFigure::white, chessboard->GetField('E',1), chessboard)); //14
    figureW.push_back(new CQueen(CFigure::white, chessboard->GetField('D',1), chessboard)); //15
    for (int i = 0; i < 8; i++)
        figureB.push_back(new CPawn(CFigure::black, chessboard->GetField(65+i,7), chessboard));
    figureB.push_back(new CCastel(CFigure::black, chessboard->GetField('A',8), chessboard));
    figureB.push_back(new CCastel(CFigure::black, chessboard->GetField('H',8), chessboard));
    figureB.push_back(new CKnight(CFigure::black, chessboard->GetField('B',8), chessboard));
    figureB.push_back(new CKnight(CFigure::black, chessboard->GetField('G',8), chessboard));
    figureB.push_back(new CBishop(CFigure::black, chessboard->GetField('C',8), chessboard));
    figureB.push_back(new CBishop(CFigure::black, chessboard->GetField('F',8), chessboard));
    figureB.push_back(new CKing(CFigure::black, chessboard->GetField('E',8), chessboard));
    figureB.push_back(new CQueen(CFigure::black, chessboard->GetField('D',8), chessboard));

    playerW = new CPlayer (figureW);
    playerB = new CPlayer (figureB);

    currentPlayer = playerW;
}

string CGameManager::CurrentPlayerAction(string request)
{
    if ((request.find("pW")!= string::npos && playerW == currentPlayer) || (request.find("pB")!= NULL && playerB == currentPlayer))
    {
        char x = request[3];
        int y = (int) (request[4] - 48); //convert ASCII
        if (currentPlayer->GetMarkedFigure() == NULL)
        {
            if ((request.find("pW")!= string::npos && chessboard->GetField(x,y)->GetVisitor() != NULL && chessboard->GetField(x,y)->GetVisitor()->GetColor() == 0)
                    || (request.find("pB")!= string::npos && chessboard->GetField(x,y)->GetVisitor() != NULL && chessboard->GetField(x,y)->GetVisitor()->GetColor() == 1))
            {
                currentPlayer->SetMarkedFigure(chessboard->GetField(x,y)->GetVisitor());
                return SerializationAvailableFields(x,y);
            }
        }
        else
        {
            if (SerializationAvailableFields(currentPlayer->GetMarkedFigure()->GetPosition()->GetX(),currentPlayer->GetMarkedFigure()->GetPosition()->GetY()).find(x+y))
            {
                chessboard->GetField(x,y)->SetVisitor(currentPlayer->GetMarkedFigure());
                currentPlayer->GetMarkedFigure()->SetPosition(chessboard->GetField(x,y));
                currentPlayer->SetMarkedFigure(NULL);
                if (currentPlayer == playerW) currentPlayer = playerB;
                else currentPlayer = playerW;
                return SerializationFigurePosition();
            }
        }
    }
    return "";
}

void CGameManager::DeleteFigure(char x, int y)
{
    chessboard->GetField(x,y)->GetVisitor()->SetPosition(NULL);
    chessboard->GetField(x,y)->SetVisitor(NULL);
}

string CGameManager::SerializationFigurePosition()
{
    string serializedData = "";
    for (int i = 0 ; i < figureW.size(); i++)
        serializedData += figureW[i]->SerializationPosition();
    for (int i = 0 ; i < figureB.size(); i++)
        serializedData += figureB[i]->SerializationPosition();
    return serializedData;
}

string CGameManager::SerializationAvailableFields(char x, int y)
{
    string stringAvailableField = "";
    stringAvailableField = chessboard->GetField(x,y)->GetVisitor()->SerializationAvailablePosition();
    cout << stringAvailableField;
    return stringAvailableField;
}

