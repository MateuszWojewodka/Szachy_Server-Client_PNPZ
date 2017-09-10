#include "cqueen.h"

CQueen::CQueen(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{
}

vector<CField *> CQueen::CheckWhichFieldsAreAvailable()
{
    vector <CField*> availableField;
    CCastel *helpCastel = new CCastel(color,position,chessboard);
    CBishop *helpBishop = new CBishop (color, position, chessboard);
    availableField = helpCastel->CheckWhichFieldsAreAvailable();
    availableField.insert(availableField.end(), helpBishop->CheckWhichFieldsAreAvailable().begin(), helpBishop->CheckWhichFieldsAreAvailable().end());
    delete helpCastel;
    delete helpBishop;
    return availableField;
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
