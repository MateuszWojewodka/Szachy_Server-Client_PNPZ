#include <iostream>
#include "server.h"
#include "cgamemanager.h"

using namespace std;

int main()
{
	//CGameManager *GM = new CGameManager();


	//GM->DeleteFigure('D',2);
	//GM->DeleteFigure('D',1);
	//GM->DeleteFigure('F',2);
	//GM->DeleteFigure('E',2);
	//GM->DeleteFigure('F',1);
	//GM->SerializationAvailableFields("playerW|E1");
	/*for (int j = 0 ; j < 8; j++)
	{
	for (int i = 0 ; i < 8 ; i++)
	{
	cout << GM->chessboard->getField(65+i, j+1)->getX();
	cout << GM->chessboard->getField(65+i, j+1)->getY();
	if (dynamic_cast <CBishop*>(GM->chessboard->getField(65+i, j+1)->getVisitor()))
	cout << "B";
	if (dynamic_cast <CCastel*>(GM->chessboard->getField(65+i, j+1)->getVisitor()))
	cout << "C";
	if (dynamic_cast <CKing*>(GM->chessboard->getField(65+i, j+1)->getVisitor()))
	cout << "KG";
	if (dynamic_cast <CKnight*>(GM->chessboard->getField(65+i, j+1)->getVisitor()))
	cout << "K";
	if (dynamic_cast <CPawn*>(GM->chessboard->getField(65+i, j+1)->getVisitor()))
	cout << "P";
	if (dynamic_cast <CQueen*>(GM->chessboard->getField(65+i, j+1)->getVisitor()))
	cout << "Q";
	cout << '\t';
	}
	cout << endl;
	}

	//test wykrywanie pol
	fieldAvailable = GM->figureW[14]->CheckWhichFieldsAreAvailable();
	cout << "Check Figure: " << GM->figureW[14]->getPosition()->getX() << GM->figureW[14]->getPosition()->getY() << endl;
	for (int i = 0 ; i < fieldAvailable.size(); i++)
	{
	cout << fieldAvailable[i]->getX();
	cout << fieldAvailable[i]->getY() << endl;
	}*/

	return 0;
}

