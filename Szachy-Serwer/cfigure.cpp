#include "cfigure.h"

CFigure::CFigure(Color color, CField *position, CChessboard *chessboard)
{
    this->color = color;
    this->position = position;
    this->chessboard = chessboard;
    this->position->SetVisitor(this);
}

CFigure::Color CFigure::GetColor()
{
    return color;
}

CField *CFigure::GetPosition()
{
    return position;
}

void CFigure::SetPosition(CField *position)
{
    this->position = position;
}

string CFigure::SerializationAvailablePosition()
{
    string stringAvailablePosition = "";
    vector <CField*> availablePositions = CheckWhichFieldsAreAvailable();
    for (int i = 0 ; i < availablePositions.size(); i++)
    {
        stringAvailablePosition += availablePositions[i]->GetX();
        stringAvailablePosition += std::to_string(availablePositions[i]->GetY());
        stringAvailablePosition += '|';
    }
    return stringAvailablePosition;
}

std::string to_string(int i)
{
    {
        std::ostringstream o;
        o << i;
        return o.str();
    }
}
