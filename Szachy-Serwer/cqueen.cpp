#include "cqueen.h"

CQueen::CQueen(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{
}

vector<CField *> CQueen::CheckWhichFieldsAreAvailable()
{
    vector <CField*> availableField1, availableField2;
    CCastel *helpCastel = new CCastel (color,position,chessboard);
    CBishop *helpBishop = new CBishop (color, position, chessboard);
    availableField1 = helpCastel->CheckWhichFieldsAreAvailable();
	availableField2 = helpBishop->CheckWhichFieldsAreAvailable();
    availableField1.insert(availableField1.begin(), availableField2.begin(), availableField2.end());
    delete helpCastel;
    delete helpBishop;
	position->SetVisitor(this);
    return availableField1;
}

string CQueen::SerializationPosition()
{
    string serializedData = "";
    if (GetPosition() != NULL)
    {
        serializedData += GetPosition()->GetX();
        serializedData += GetPosition()->GetY() + 48;
        serializedData += "|";
        serializedData += "Q";
        if (color == 0) serializedData += "0";
        else serializedData += "1";
        serializedData += "||";
    }
    return serializedData;
}
