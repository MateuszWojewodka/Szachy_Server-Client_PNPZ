#include "cpawn.h"

CPawn::CPawn(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{

}

vector<CField *> CPawn::CheckWhichFieldsAreAvailable()
{
    vector <CField*> availableField;
    switch (color)
    {
        case white:
        {
            if (chessboard->GetField(position->GetX(),position->GetY() + 1)->GetVisitor() == NULL)
                availableField.push_back(chessboard->GetField(position->GetX(),position->GetY() + 1));
                return availableField;
        }
        case black:
        {
        if (chessboard->GetField(position->GetX(),position->GetY() - 1)->GetVisitor() == NULL)
            availableField.push_back(chessboard->GetField(position->GetX(),position->GetY() - 1));
            return availableField;
        }
        default:
            return availableField;
    }
}

string CPawn::SerializationPosition()
{
    string serializedData = "";
    if (GetPosition() != NULL)
    {
        serializedData += GetPosition()->GetX();
        serializedData += GetPosition()->GetY() + 48;
        serializedData += "|";
        serializedData += "P";
        if (color == 0) serializedData += "0";
        else serializedData += "1";
        serializedData += "||";
    }
    return serializedData;
}
