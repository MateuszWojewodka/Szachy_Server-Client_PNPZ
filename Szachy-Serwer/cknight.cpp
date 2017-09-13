#include "cknight.h"

CKnight::CKnight(Color color, CField *position, CChessboard *chessboard) : CFigure (color, position, chessboard)
{
}

vector<CField *> CKnight::CheckWhichFieldsAreAvailable()
{
	vector <CField*> availableFields;
	switch (color)
	{
		case white:
		{
			if (position->GetX() - 2 >= 65)
			{
				if (position->GetY() + 1 <= 8)
				{
					if (chessboard->GetField(position->GetX() - 2, position->GetY() + 1)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() + 1));
					if (chessboard->GetField(position->GetX() - 2, position->GetY() + 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 2, position->GetY() + 1)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() + 1));
				}
				if (position->GetY() - 1 >= 1)
				{
					if (chessboard->GetField(position->GetX() - 2, position->GetY() - 1)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() - 1));
					if (chessboard->GetField(position->GetX() - 2, position->GetY() - 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 2, position->GetY() - 1)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() - 1));
				}
			}
			if (position->GetX() + 2 <= 72)
			{
				if (position->GetY() + 1 <= 8)
				{
					if (chessboard->GetField(position->GetX() + 2, position->GetY() + 1)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() + 1));
					if (chessboard->GetField(position->GetX() + 2, position->GetY() + 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 2, position->GetY() + 1)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() + 1));
				}
				if (position->GetY() - 1 >= 1)
				{
					if (chessboard->GetField(position->GetX() + 2, position->GetY() - 1)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() - 1));
					if (chessboard->GetField(position->GetX() + 2, position->GetY() - 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 2, position->GetY() - 1)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() - 1));
				}
			}

			if (position->GetY() - 2 >= 1)
			{
				if (position->GetX() + 1 <= 72)
				{
					if (chessboard->GetField(position->GetX() + 1, position->GetY() - 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() - 2));
					if (chessboard->GetField(position->GetX() + 1, position->GetY() - 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 1, position->GetY() - 2)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() - 2));
				}
				if (position->GetX() - 1 >= 65)
				{
					if (chessboard->GetField(position->GetX() - 1, position->GetY() - 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() - 2));
					if (chessboard->GetField(position->GetX() - 1, position->GetY() - 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 1, position->GetY() - 2)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() - 2));
				}
			}
			if (position->GetY() + 2 <= 8)
			{
				if (position->GetX() + 1 <= 72)
				{
					if (chessboard->GetField(position->GetX() + 1, position->GetY() + 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() + 2));
					if (chessboard->GetField(position->GetX() + 1, position->GetY() + 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 1, position->GetY() + 2)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() + 2));
				}
				if (position->GetX() - 1 >= 65)
				{
					if (chessboard->GetField(position->GetX() - 1, position->GetY() + 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() + 2));
					if (chessboard->GetField(position->GetX() - 1, position->GetY() + 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 1, position->GetY() + 2)->GetVisitor()->GetColor() == 1)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() + 2));
				}
			}
			return availableFields;
		}
		case black:
		{
			if (position->GetY() + 1 <= 8)
			{
				if (chessboard->GetField(position->GetX() - 2, position->GetY() + 1)->GetVisitor() == NULL)
					availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() + 1));
				if (chessboard->GetField(position->GetX() - 2, position->GetY() + 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 2, position->GetY() + 1)->GetVisitor()->GetColor() == 0)
					availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() + 1));
			}
			if (position->GetY() - 1 >= 1)
			{
				if (chessboard->GetField(position->GetX() - 2, position->GetY() - 1)->GetVisitor() == NULL)
					availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() - 1));
				if (chessboard->GetField(position->GetX() - 2, position->GetY() - 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 2, position->GetY() - 1)->GetVisitor()->GetColor() == 0)
					availableFields.push_back(chessboard->GetField(position->GetX() - 2, position->GetY() - 1));
			}
			if (position->GetX() + 2 <= 72)
			{
				if (position->GetY() + 1 <= 8)
				{
					if (chessboard->GetField(position->GetX() + 2, position->GetY() + 1)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() + 1));
					if (chessboard->GetField(position->GetX() + 2, position->GetY() + 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 2, position->GetY() + 1)->GetVisitor()->GetColor() == 0)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() + 1));
				}
				if (position->GetY() - 1 >= 1)
				{
					if (chessboard->GetField(position->GetX() + 2, position->GetY() - 1)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() - 1));
					if (chessboard->GetField(position->GetX() + 2, position->GetY() - 1)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 2, position->GetY() - 1)->GetVisitor()->GetColor() == 0)
						availableFields.push_back(chessboard->GetField(position->GetX() + 2, position->GetY() - 1));
				}
			}

			if (position->GetY() - 2 >= 1)
			{
				if (position->GetX() + 1 <= 72)
				{
					if (chessboard->GetField(position->GetX() + 1, position->GetY() - 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() - 2));
					if (chessboard->GetField(position->GetX() + 1, position->GetY() - 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 1, position->GetY() - 2)->GetVisitor()->GetColor() == 0)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() - 2));
				}
				if (position->GetX() - 1 >= 65)
				{
					if (chessboard->GetField(position->GetX() - 1, position->GetY() - 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() - 2));
					if (chessboard->GetField(position->GetX() - 1, position->GetY() - 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 1, position->GetY() - 2)->GetVisitor()->GetColor() == 0)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() - 2));
				}
			}
			if (position->GetY() + 2 <= 8)
			{
				if (position->GetX() + 1 <= 72)
				{
					if (chessboard->GetField(position->GetX() + 1, position->GetY() + 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() + 2));
					if (chessboard->GetField(position->GetX() + 1, position->GetY() + 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() + 1, position->GetY() + 2)->GetVisitor()->GetColor() == 0)
						availableFields.push_back(chessboard->GetField(position->GetX() + 1, position->GetY() + 2));
				}
				if (position->GetX() - 1 >= 65)
				{
					if (chessboard->GetField(position->GetX() - 1, position->GetY() + 2)->GetVisitor() == NULL)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() + 2));
					if (chessboard->GetField(position->GetX() - 1, position->GetY() + 2)->GetVisitor() != NULL && chessboard->GetField(position->GetX() - 1, position->GetY() + 2)->GetVisitor()->GetColor() == 0)
						availableFields.push_back(chessboard->GetField(position->GetX() - 1, position->GetY() + 2));
				}
			}
		}
		return availableFields;
	}
	return availableFields;
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
