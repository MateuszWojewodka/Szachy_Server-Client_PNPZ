#include "CChessboard.h"

CChessboard::CChessboard()
{
    field.resize(8);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char ascii = (char)(65 + j%8);
            field[i].push_back(new CField (ascii, i+1, j*xSize/8, (7-i)*ySize/8, NULL));
        }
    }

    figure.push_back(new CFigure('P',0));
    figure.push_back(new CFigure('C',0));
    figure.push_back(new CFigure('K',0));
    figure.push_back(new CFigure('B',0));
    figure.push_back(new CFigure('Q',0));
    figure.push_back(new CFigure('W',0));
    figure.push_back(new CFigure('P',1));
    figure.push_back(new CFigure('C',1));
    figure.push_back(new CFigure('K',1));
    figure.push_back(new CFigure('B',1));
    figure.push_back(new CFigure('Q',1));
    figure.push_back(new CFigure('W',1));
}

void CChessboard::DeserializeFigurePositions (string data)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            field[i][j]->SetVisitor(NULL);

    char xDes;
    int yDes;
    char typeDes;
    bool colorDes;
    for (int i = 0 ; i < data.size() ; i += 7)
    {
        xDes = data[i];
        yDes = (int) (data[i+1] - 48);
        typeDes = data[i+3];
        int pomColor = (int) (data[i+4] - 48);
        colorDes = (bool) pomColor;

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (field[i][j]->GetX() == xDes && field[i][j]->GetY() == yDes)
                    for (int k = 0 ; k < figure.size() ; k++)
                        if (figure[k]->GetType() == typeDes && figure[k]->GetColor() == colorDes)
                        {
                            field[i][j]->SetVisitor(figure[k]);
                            break;
                        }
    }
}

CField *CChessboard::GetField(char sign, int digit)
{
    int y = (int)sign%8 - 1;
    if (y == -1)
        y=7;
    int x = digit - 1;
    return field[x][y];
}

CChessboard::~CChessboard()
{
    //dtor
}
