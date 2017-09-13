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
			if (position->GetY() + 1 <= 8)
				if (chessboard->GetField(position->GetX(), position->GetY() + 1)->GetVisitor() == NULL)
					availableField.push_back(chessboard->GetField(position->GetX(), position->GetY() + 1));
			if ((position->GetX() + 1) <= 72 && (position->GetY() + 1) <= 8)
				if (chessboard->GetField(position->GetX() + 1, position->GetY() + 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 1, position->GetY() + 1)->GetVisitor()->GetColor() == 1)
					availableField.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() + 1));
			if (position->GetX() - 1 >= 65 && position->GetY() + 1 <= 8)
				if (chessboard->GetField(position->GetX() - 1, position->GetY() + 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 1, position->GetY() + 1)->GetVisitor()->GetColor() == 1)
					availableField.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() + 1));
				return availableField;
		}
		case black:
		{
			if (position->GetY() - 1 >= 1)
				if (chessboard->GetField(position->GetX(), position->GetY() - 1)->GetVisitor() == NULL)
					availableField.push_back(chessboard->GetField(position->GetX(), position->GetY() - 1));
			if (position->GetX() + 1 <= 72 && position->GetY() - 1 >= 1)
				if (chessboard->GetField(position->GetX() + 1, position->GetY() - 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 1, position->GetY() - 1)->GetVisitor()->GetColor() == 0)
					availableField.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() - 1));
			if (position->GetX() - 1 >= 65 && position->GetY() - 1 >= 1)
				if (chessboard->GetField(position->GetX() - 1, position->GetY() - 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 1, position->GetY() - 1)->GetVisitor()->GetColor() == 0)
					availableField.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() - 1));
			return availableField;
		}
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
