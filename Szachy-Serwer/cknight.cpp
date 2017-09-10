#include "cknight.h"

CKnight::CKnight(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{
}

vector<CField *> CKnight::CheckWhichFieldsAreAvailable()
{
}

string CKnight::SerializationPosition()
{
    string serializedData = "";
    if (GetPosition() != NULL)
    {
        serializedData += GetPosition()->GetX();
        serializedData += GetPosition()->GetY() + 48;
        serializedData += "|";
        serializedData += "K";
        if (color == 0) serializedData += "0";
        else serializedData += "1";
        serializedData += "||";
    }
    return serializedData;
}
