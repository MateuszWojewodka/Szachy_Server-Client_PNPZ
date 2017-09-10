#include "ccastel.h"

CCastel::CCastel(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{
}

vector<CField *> CCastel::CheckWhichFieldsAreAvailable()
{
    vector <CField*> availableField;
    for (int i = position->GetY() + 1; i <= 8 ; i++)
    {
        if (chessboard->GetField(position->GetX(), i)->GetVisitor() == NULL || chessboard->GetField(position->GetX(), i)->GetVisitor()->GetColor() != color)
            availableField.push_back(chessboard->GetField(position->GetX(), i));
        if (chessboard->GetField(position->GetX(), i)->GetVisitor() != NULL)
            break;
    }
    for (int i = position->GetY() - 1; i >= 1 ; i--)
    {
        if (chessboard->GetField(position->GetX(), i)->GetVisitor() == NULL || chessboard->GetField(position->GetX(), i)->GetVisitor()->GetColor() != color)
            availableField.push_back(chessboard->GetField(position->GetX(), i));
        if (chessboard->GetField(position->GetX(), i)->GetVisitor() != NULL)
            break;
    }
    for (int i = position->GetX() + 1; i <= 72 ; i++)
    {
        if (chessboard->GetField(i, position->GetY())->GetVisitor() == NULL || chessboard->GetField(i, position->GetY())->GetVisitor()->GetColor() != color)
            availableField.push_back(chessboard->GetField(i, position->GetY()));
        if (chessboard->GetField(i, position->GetY())->GetVisitor() != NULL)
            break;
    }
    for (int i = position->GetX() - 1; i >= 65 ; i--)
    {
        if (chessboard->GetField(i, position->GetY())->GetVisitor() == NULL || chessboard->GetField(i, position->GetY())->GetVisitor()->GetColor() != color)
            availableField.push_back(chessboard->GetField(i, position->GetY()));
        if (chessboard->GetField(i, position->GetY())->GetVisitor() != NULL)
            break;
    }
    return availableField;
}

string CCastel::SerializationPosition()
{
    string serializedData = "";
    if (GetPosition() != NULL)
    {
        serializedData += GetPosition()->GetX();
        serializedData += GetPosition()->GetY() + 48;
        serializedData += "|";
        serializedData += "C";
        if (color == 0) serializedData += "0";
        else serializedData += "1";
        serializedData += "||";
    }
    return serializedData;
}
