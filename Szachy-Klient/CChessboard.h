#ifndef CCHESSBOARD_H
#define CCHESSBOARD_H

#include "CField.h"
#include <vector>
#include <iostream>

using namespace std;

class CChessboard
{
    static int xSize;
    static int ySize;
    vector< vector<CField*> > field;
    vector <CFigure*> figure;
    public:
        CChessboard();
        void DeserializeFigurePositions (string data);
		//bool CheckIfChessboardChange(string data);
        CField *GetField (char sign, int digit);
        virtual ~CChessboard();
};

#endif // CCHESSBOARD_H
