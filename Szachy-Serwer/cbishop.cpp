#include "cbishop.h"

CBishop::CBishop(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{

}

vector<CField *> CBishop::CheckWhichFieldsAreAvailable()
{
    vector <CField*> availableField;
    int i = position->GetX() + 1;
    int j = position->GetY() + 1;
    while (i <= 72 && j <= 8)
    {
        if (chessboard->GetField(i, j)->GetVisitor() == NULL)
            availableField.push_back(chessboard->GetField(i,j));
		else if (chessboard->GetField(i, j)->GetVisitor()->GetColor() != color)
		{
			availableField.push_back(chessboard->GetField(i, j));
			break;
		}
        else if (chessboard->GetField(i,j)->GetVisitor()->GetColor() == color)
            break;
        i++;
        j++;
    }

    i = position->GetX() - 1;
    j = position->GetY() - 1;
    while (i >= 65 && j >= 1)
    {
		if (chessboard->GetField(i, j)->GetVisitor() == NULL)
			availableField.push_back(chessboard->GetField(i, j));
		else if (chessboard->GetField(i, j)->GetVisitor()->GetColor() != color)
		{
			availableField.push_back(chessboard->GetField(i, j));
			break;
		}
		else if (chessboard->GetField(i, j)->GetVisitor()->GetColor() == color)
			break;
        i--;
        j--;
    }

    i = position->GetX() - 1;
    j = position->GetY() + 1;
    while (i >= 65 && j <= 8)
    {
		if (chessboard->GetField(i, j)->GetVisitor() == NULL)
			availableField.push_back(chessboard->GetField(i, j));
		else if (chessboard->GetField(i, j)->GetVisitor()->GetColor() != color)
		{
			availableField.push_back(chessboard->GetField(i, j));
			break;
		}
		else if (chessboard->GetField(i, j)->GetVisitor()->GetColor() == color)
			break;
        i--;
        j++;
    }

    i = position->GetX() + 1;
    j = position->GetY() - 1;
    while (i <= 72 && j >= 1)
    {
		if (chessboard->GetField(i, j)->GetVisitor() == NULL)
			availableField.push_back(chessboard->GetField(i, j));
		else if (chessboard->GetField(i, j)->GetVisitor()->GetColor() != color)
		{
			availableField.push_back(chessboard->GetField(i, j));
			break;
		}
		else if (chessboard->GetField(i, j)->GetVisitor()->GetColor() == color)
			break;
        i++;
        j--;
    }
    return availableField;
}

string CBishop::SerializationPosition()
{
    string serializedData = "";
    if (GetPosition() != NULL)
    {
        serializedData += GetPosition()->GetX();
        serializedData += GetPosition()->GetY() + 48;
        serializedData += "|";
        serializedData += "B";
        if (color == 0) serializedData += "0";
        else serializedData += "1";
        serializedData += "||";
    }
    return serializedData;
}
