#include "cchessboard.h"

CChessboard::CChessboard()
{
    //set size
    field.resize(8);

    //set 'id'
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char ascii = (char)(65 + j%8);
            field[i].push_back(new CField (ascii, i+1));
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

