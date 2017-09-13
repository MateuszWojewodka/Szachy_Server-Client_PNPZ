#include "cgamemanager.h"

CGameManager::CGameManager()
{
	chessboard = new CChessboard();

	for (int i = 0; i < 8; i++)
		figureW.push_back(new CPawn(CFigure::white, chessboard->GetField(65 + i, 2), chessboard)); //[0-7]
	figureW.push_back(new CCastel(CFigure::white, chessboard->GetField('A', 1), chessboard)); //8
	figureW.push_back(new CCastel(CFigure::white, chessboard->GetField('H', 1), chessboard)); //9
	figureW.push_back(new CKnight(CFigure::white, chessboard->GetField('B', 1), chessboard)); //10
	figureW.push_back(new CKnight(CFigure::white, chessboard->GetField('G', 1), chessboard)); //11
	figureW.push_back(new CBishop(CFigure::white, chessboard->GetField('C', 1), chessboard)); //12
	figureW.push_back(new CBishop(CFigure::white, chessboard->GetField('F', 1), chessboard)); //13
	figureW.push_back(new CKing(CFigure::white, chessboard->GetField('E', 1), chessboard)); //14
	figureW.push_back(new CQueen(CFigure::white, chessboard->GetField('D', 1), chessboard)); //15
	for (int i = 0; i < 8; i++)
		figureB.push_back(new CPawn(CFigure::black, chessboard->GetField(65 + i, 7), chessboard));
	figureB.push_back(new CCastel(CFigure::black, chessboard->GetField('A', 8), chessboard));
	figureB.push_back(new CCastel(CFigure::black, chessboard->GetField('H', 8), chessboard));
	figureB.push_back(new CKnight(CFigure::black, chessboard->GetField('B', 8), chessboard));
	figureB.push_back(new CKnight(CFigure::black, chessboard->GetField('G', 8), chessboard));
	figureB.push_back(new CBishop(CFigure::black, chessboard->GetField('C', 8), chessboard));
	figureB.push_back(new CBishop(CFigure::black, chessboard->GetField('F', 8), chessboard));
	figureB.push_back(new CKing(CFigure::black, chessboard->GetField('E', 8), chessboard));
	figureB.push_back(new CQueen(CFigure::black, chessboard->GetField('D', 8), chessboard));

	playerW = new CPlayer(figureW);
	playerB = new CPlayer(figureB);

	currentPlayer = playerW;

	DeleteFigure('A', 2);
}

string CGameManager::CurrentPlayerAction(string request)
{
	IfMyKingIsInDanger();
	//pierwsze warunki: jesli w zapytaniu bylo pW lub pB (zapytania zwiazane z nacisnieciem LPM) sprawdz czy pytajacy to gracz ktorego jest ruch
	if ((request.find("pW") != string::npos && playerW == currentPlayer) || (request.find("pB") != string::npos && playerB == currentPlayer))
	{
		char x = request[3];
		int y = (int)(request[4] - 48);
		//jesli spelniony war 1 to sprawdz czy gracz zaznaczyl jakas figure WCZESNIEJ
		if (currentPlayer->GetMarkedFigure() == NULL)
		{
			//jesli nie zaznaczyl to sprawdz czy na tym polu jest figura i czy jest jego jesli tak to ja zaznacz
			if ((request.find("pW") != string::npos && chessboard->GetField(x, y)->GetVisitor() != NULL && chessboard->GetField(x, y)->GetVisitor()->GetColor() == 0)
				|| (request.find("pB") != string::npos && chessboard->GetField(x, y)->GetVisitor() != NULL && chessboard->GetField(x, y)->GetVisitor()->GetColor() == 1))
			{
				currentPlayer->SetMarkedFigure(chessboard->GetField(x, y)->GetVisitor());
				return SerializationAvailableFields(x, y);
			}
		}
		//jesli gracz zaznaczyl WCZESNIEJ figure to:
		else
		{
			string search = " ";
			search = x + std::to_string(y);
			//sprawdz czy zaznaczyl TERAZ pole na ktore moze sie ruszyc
			if (SerializationAvailableFields(currentPlayer->GetMarkedFigure()->GetPosition()->GetX(), currentPlayer->GetMarkedFigure()->GetPosition()->GetY()).find(search) != string::npos)
			{
				//obsluga bicia [ustawienie pozycji pionka bitego na 0]
				if (chessboard->GetField(x, y)->GetVisitor() != NULL) chessboard->GetField(x, y)->GetVisitor()->SetPosition(NULL);
				//aktualizacja goscia na ZAZNACZONYM polu
				chessboard->GetField(x, y)->SetVisitor(currentPlayer->GetMarkedFigure());
				//POPRZEDNIE pole visitor jako null
				currentPlayer->GetMarkedFigure()->GetPosition()->SetVisitor(NULL);
				//aktualizacja pola figury
				currentPlayer->GetMarkedFigure()->SetPosition(chessboard->GetField(x, y));
				//zaznaczona figura ponownie 0
				currentPlayer->SetMarkedFigure(NULL);
				//przyznanie ruchu drugiemu graczowi
				if (currentPlayer == playerW) currentPlayer = playerB;
				else currentPlayer = playerW;
				//aktualizacja
				return SerializationFigurePosition();
			}
			else
			{
				//jesli nie zaznaczyl TERAZ pola na ktore moze sie ruszyc sprobuj zmienic aktywna figure (analogiczny kod jak w 43 linijcee)
				if ((request.find("pW") != string::npos && chessboard->GetField(x, y)->GetVisitor() != NULL && chessboard->GetField(x, y)->GetVisitor()->GetColor() == 0)
					|| (request.find("pB") != string::npos && chessboard->GetField(x, y)->GetVisitor() != NULL && chessboard->GetField(x, y)->GetVisitor()->GetColor() == 1))
				{
					currentPlayer->SetMarkedFigure(chessboard->GetField(x, y)->GetVisitor());
					return SerializationAvailableFields(x, y);
				}
			}
		}
	}
	return "";
}

void CGameManager::DeleteFigure(char x, int y)
{
	chessboard->GetField(x, y)->GetVisitor()->SetPosition(NULL);
	chessboard->GetField(x, y)->SetVisitor(NULL);
}

string CGameManager::SerializationFigurePosition()
{
	string serializedData = "";
	for (int i = 0; i < figureW.size(); i++)
		serializedData += figureW[i]->SerializationPosition();
	for (int i = 0; i < figureB.size(); i++)
		serializedData += figureB[i]->SerializationPosition();
	return serializedData;
}

string CGameManager::SerializationAvailableFields(char x, int y)
{
	string stringAvailableField = "";
	stringAvailableField = chessboard->GetField(x, y)->GetVisitor()->SerializationAvailablePosition();
	return stringAvailableField;
}

bool CGameManager::IfMyKingIsInDanger()
{
	CPlayer *oppositePlayer;
	vector <CFigure*> oppositeFigure;
	vector <CFigure*> myFigure;
	
	//ustalenie jaki gracz to przeciwnik
	if (currentPlayer == playerB) 
	{
		myFigure = figureB;
		oppositePlayer = playerW;
		oppositeFigure = figureW;
	}
		
	else if (currentPlayer == playerW) 
	{
		myFigure = figureW;
		oppositePlayer = playerB;
		oppositeFigure = figureB;
	}

	//wspolrzedne mojego krola
	CField *myKingsField = myFigure[14]->GetPosition();

	//sprawdzanie kazdej wrogiej figury czy nie bije mojego krola
	for each  (auto figure in oppositeFigure)
	{
		if (figure->GetPosition() != NULL) 
		{
			for each (auto field in figure->CheckWhichFieldsAreAvailable())
			{
				if (field->GetX() == myKingsField->GetX() &&
					field->GetY() == myKingsField->GetY()) 
				{
					if (currentPlayer == playerB)
						cout << "Bia³e szachuj¹ czarne!" << endl;
					else if (currentPlayer == playerW)
						cout << "Czarne szachuj¹ bia³e" << endl;
					return true;
				}
			}
		}
	}
	return false;
}

bool CGameManager::IfMyKingWillBeInDangerAfterMove(char x, int y)
{
	return false;
}
