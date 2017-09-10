#include "cking.h"

CKing::CKing(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{
}

vector<CField *> CKing::CheckWhichFieldsAreAvailable()
{
    vector <CField*> availableField;
    if (position->GetY() + 1 <= 8)
    {
        for (int i = position->GetX() - 1; i <= position->GetX() + 1; i++)
        {
            if (i < 65 || i > 72)
                continue;
                if (chessboard->GetField(i, position->GetY()+1)->GetVisitor() == NULL || chessboard->GetField(i, position->GetY()+1)->GetVisitor()->GetColor() != color)
                    availableField.push_back(chessboard->GetField(i, position->GetY()+1));
        }
    }
    if (position->GetY() - 1 >= 1)
    {
        for (int i = position->GetX() - 1; i <= position->GetX() + 1; i++)
        {
            if (i < 65 || i > 72)
                continue;
            if (chessboard->GetField(i, position->GetY() - 1)->GetVisitor() == NULL || chessboard->GetField(i, position->GetY() - 1)->GetVisitor()->GetColor() != color)
                availableField.push_back(chessboard->GetField(i, position->GetY() - 1));
        }
    }
    if (position->GetX() - 1 >= 65)
        if (chessboard->GetField(position->GetX() - 1, position->GetY())->GetVisitor() == NULL || chessboard->GetField(position->GetX() - 1, position->GetY())->GetVisitor()->GetColor() != color)
            availableField.push_back(chessboard->GetField(position->GetX() - 1, position->GetY()));
    if (position->GetX() + 1 <= 72)
        if (chessboard->GetField(position->GetX() + 1, position->GetY())->GetVisitor() == NULL || chessboard->GetField(position->GetX() + 1, position->GetY())->GetVisitor()->GetColor() != color)
            availableField.push_back(chessboard->GetField(position->GetX() + 1, position->GetY()));

    return availableField;
}

string CKing::SerializationPosition()
{
    string serializedData = "";
    if (GetPosition() != NULL)
    {
        serializedData += GetPosition()->GetX();
        serializedData += GetPosition()->GetY() + 48;
        serializedData += "|";
        serializedData += "W";
        if (color == 0) serializedData += "0";
        else serializedData += "1";
        serializedData += "||";
    }
    return serializedData;
}

