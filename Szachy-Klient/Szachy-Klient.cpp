#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "Client.h"
#include "CChessboard.h"

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[] = _T("CodeBlocksWindowsApp");


//CLIENT
Client *client;
string request = "";
string id = "";

//GRAPHIC
//Chessboard
CChessboard *chessboard;

int CChessboard::xSize = 720;
int CChessboard::ySize = 720;

//buttons
HWND g_hBGraj, g_hBWyjscie, g_hBStart, g_hBPowrot;

//labels
HWND hLPleaseWait, hLStartGame;

//image variables
HBITMAP bmpfieldw, bmpfieldb, bmpPawnBB, bmpPawnBW, bmpPawnWW, bmpPawnWB;
HBITMAP bmpOldFieldW, bmpOldFieldB, bmpOldPawnBB, bmpOldPawnBW, bmpOldPawnWW, bmpOldPawnWB;
HDC hdc, hdcfieldw, hdcfieldb, hdcPawnBB, hdcPawnBW, hdcPawnWW, hdcPawnWB;


int WINAPI WinMain(HINSTANCE hThisInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszArgument,
	int nCmdShow)
{
	HWND hwnd;               /* This is the handle for our window */
	MSG messages;            /* Here messages to the application are saved */
	WNDCLASSEX wincl;        /* Data structure for the windowclass */

							 /* The Window structure */
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
	wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
	wincl.cbSize = sizeof(WNDCLASSEX);

	/* Use default icon and mouse-pointer */
	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;                 /* No menu */
	wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
	wincl.cbWndExtra = 0;                      /* structure or the window instance */
											   /* Use Windows's default colour as the background of the window */
	wincl.hbrBackground = (HBRUSH)COLOR_WINDOW;

	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx(&wincl))
		return 0;

	/* The class is registered, let's create the program*/
	hwnd = CreateWindowEx(
		0,                   /* Extended possibilites for variation */
		szClassName,         /* Classname */
		_T("Code::Blocks Template Windows App"),       /* Title Text */
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, /* default window (disable resize)*/
		CW_USEDEFAULT,       /* Windows decides the position */
		CW_USEDEFAULT,       /* where the window ends up on the screen */
		900,                 /* The programs width */
		748,                 /* and height in pixels */
		HWND_DESKTOP,        /* The window is a child-window to desktop */
		NULL,                /* No menu */
		hThisInstance,       /* Program Instance handler */
		NULL                 /* No Window Creation data */
	);

	//create chessboard, which has fields x and y positions
	chessboard = new CChessboard();

	//create buttons
	g_hBGraj = CreateWindowEx(0, (LPCWSTR)"BUTTON", (LPCWSTR)"Graj", WS_CHILD | WS_VISIBLE, 735, 100, 150, 30, hwnd, NULL, hThisInstance, NULL);
	g_hBWyjscie = CreateWindowEx(0, (LPCWSTR)"BUTTON", (LPCWSTR)"Wyjscie", WS_CHILD | WS_VISIBLE, 735, 150, 150, 30, hwnd, NULL, hThisInstance, NULL);
	g_hBStart = CreateWindowEx(0, (LPCWSTR)"BUTTON", (LPCWSTR)"Start", WS_CHILD, 735, 100, 150, 30, hwnd, NULL, hThisInstance, NULL);
	g_hBPowrot = CreateWindowEx(0, (LPCWSTR)"BUTTON", (LPCWSTR)"Powrot", WS_CHILD, 735, 150, 150, 30, hwnd, NULL, hThisInstance, NULL);

	//create labels
	hLPleaseWait = CreateWindowEx(0, (LPCWSTR)"STATIC", NULL, WS_CHILD |
		SS_CENTER | WS_VISIBLE, 735, 50, 150, 30, hwnd, NULL, hThisInstance, NULL);
	SetWindowText(hLPleaseWait, (LPCWSTR)"Prosze czekac");
	ShowWindow(hLPleaseWait, SW_HIDE);

	hLStartGame = CreateWindowEx(0, (LPCWSTR)"STATIC", NULL, WS_CHILD |
		SS_CENTER | WS_VISIBLE, 735, 50, 150, 30, hwnd, NULL, hThisInstance, NULL);
	SetWindowText(hLStartGame, (LPCWSTR)"Nacisnij start");
	ShowWindow(hLStartGame, SW_HIDE);

	/* Make the window visible on the screen */
	ShowWindow(hwnd, nCmdShow);

	/* Run the message loop. It will run until GetMessage() returns 0 */
	while (GetMessage(&messages, NULL, 0, 0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&messages);
		/* Send message to WindowProcedure */
		DispatchMessage(&messages);
	}

	/* The program return-value is 0 - The value that PostQuitMessage() gave */
	return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

void PrepareToShowImage(LPCSTR path, HDC &hdcType, HBITMAP &bmpType, HBITMAP &bmpOldType)
{
	bmpType = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hdcType = CreateCompatibleDC(hdc);
	bmpOldType = (HBITMAP)SelectObject(hdcType, bmpType);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)                  /* handle the messages */
	{
	case WM_TIMER:
	{
		if (request == "whenStart")
		{
			if (client->comunicationWithServer(request) == "now")
			{
				ShowWindow(hLPleaseWait, SW_HIDE);
				ShowWindow(hLStartGame, SW_SHOW);
				ShowWindow(g_hBStart, SW_SHOW);
			}
		}
		else
		{
			request = "update";
			chessboard->DeserializeFigurePositions(client->comunicationWithServer(request));
		}

		//image functions
		hdc = GetDC(hwnd);
		PrepareToShowImage("img//fieldb.bmp", hdcfieldb, bmpfieldb, bmpOldFieldB);
		PrepareToShowImage("img//fieldw.bmp", hdcfieldw, bmpfieldw, bmpOldFieldW);
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (j % 2 == 0)
				{
					BitBlt(hdc, i * 180, j * 90, 90, 90, hdcfieldw, 0, 0, SRCCOPY);
					BitBlt(hdc, 90 + i * 180, j * 90, 90, 90, hdcfieldb, 0, 0, SRCCOPY);
				}
				else
				{
					BitBlt(hdc, 90 + i * 180, j * 90, 90, 90, hdcfieldw, 0, 0, SRCCOPY);
					BitBlt(hdc, i * 180, j * 90, 90, 90, hdcfieldb, 0, 0, SRCCOPY);
				}
			}
		}

		PrepareToShowImage("img//pawnBB.bmp", hdcPawnBB, bmpPawnBB, bmpOldPawnBB);
		PrepareToShowImage("img//pawnBW.bmp", hdcPawnBW, bmpPawnBW, bmpOldPawnBW);
		PrepareToShowImage("img//pawnWW.bmp", hdcPawnWW, bmpPawnWW, bmpOldPawnWW);
		PrepareToShowImage("img//pawnWB.bmp", hdcPawnWB, bmpPawnWB, bmpOldPawnWB);
		for (int i = 65; i < 73; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				if (chessboard->GetField(i, j)->GetVisitor() != NULL)
				{
					if (chessboard->GetField(i, j)->GetVisitor()->GetType() == 'P')
					{
						if (chessboard->GetField(i, j)->GetVisitor()->GetColor() == 1 && chessboard->GetField(i, j)->GetColor() == 1)
							BitBlt(hdc, chessboard->GetField(i, j)->GetXPosition(), chessboard->GetField(i, j)->GetYPosition(), 90, 90, hdcPawnBB, 0, 0, SRCCOPY);
						if (chessboard->GetField(i, j)->GetVisitor()->GetColor() == 1 && chessboard->GetField(i, j)->GetColor() == 0)
							BitBlt(hdc, chessboard->GetField(i, j)->GetXPosition(), chessboard->GetField(i, j)->GetYPosition(), 90, 90, hdcPawnBW, 0, 0, SRCCOPY);
						if (chessboard->GetField(i, j)->GetVisitor()->GetColor() == 0 && chessboard->GetField(i, j)->GetColor() == 0)
							BitBlt(hdc, chessboard->GetField(i, j)->GetXPosition(), chessboard->GetField(i, j)->GetYPosition(), 90, 90, hdcPawnWW, 0, 0, SRCCOPY);
						if (chessboard->GetField(i, j)->GetVisitor()->GetColor() == 0 && chessboard->GetField(i, j)->GetColor() == 1)
							BitBlt(hdc, chessboard->GetField(i, j)->GetXPosition(), chessboard->GetField(i, j)->GetYPosition(), 90, 90, hdcPawnWB, 0, 0, SRCCOPY);
					}
				}
			}
		}

		ReleaseDC(hwnd, hdc);
		break;
	}

	case WM_CTLCOLORSTATIC:
	{
		HWND hCtl = (HWND)lParam;
		HDC hdc = (HDC)wParam;
		if (hCtl == hLPleaseWait || hCtl == hLStartGame)
		{
			SetBkMode(hdc, COLOR_WINDOW);
			return(LRESULT)GetStockObject(COLOR_WINDOW);
		}
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
		break;

	case WM_COMMAND:
		if ((HWND)lParam == g_hBGraj)
		{
			//LOGIC
			client = new Client();
			request = "whenStart";
			SetTimer(hwnd, 0, 2000, (TIMERPROC)NULL);
			//GRAPHIC
			ShowWindow(g_hBGraj, SW_HIDE);
			ShowWindow(g_hBWyjscie, SW_HIDE);
			ShowWindow(g_hBPowrot, SW_SHOW);
			ShowWindow(hLPleaseWait, SW_SHOW);
		}
		if ((HWND)lParam == g_hBWyjscie)
		{
			exit(0);
		}
		if ((HWND)lParam == g_hBPowrot)
		{
			//LOGIC
			delete client;
			KillTimer(hwnd, 0);
			//GRAPHIC
			ShowWindow(g_hBGraj, SW_SHOW);
			ShowWindow(g_hBWyjscie, SW_SHOW);
			ShowWindow(g_hBPowrot, SW_HIDE);
			ShowWindow(hLPleaseWait, SW_HIDE);
			ShowWindow(hLStartGame, SW_HIDE);
			ShowWindow(g_hBStart, SW_HIDE);
		}
		if ((HWND)lParam == g_hBStart)
		{
			request = "giveId";
			ShowWindow(hLStartGame, SW_HIDE);
			ShowWindow(g_hBStart, SW_HIDE);
			ShowWindow(g_hBPowrot, SW_HIDE);
			id = client->comunicationWithServer(request);
		}
		break;

	default:                      /* for messages that we don't deal with */
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
