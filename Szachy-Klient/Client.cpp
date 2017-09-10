#include "client.h"
#include <string>

Client::Client()
{
    WSADATA wsaData;

    int result = WSAStartup( MAKEWORD( 2, 2 ), & wsaData );
    if( result != NO_ERROR )
         printf( "Initialization error.\n" );

    sockaddr_in addr;
    memset (&addr,0,sizeof (addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons (2571);

    Connection = socket(AF_INET, SOCK_STREAM, NULL); //ustawienie socketu do komunikacji
    if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
    {
        MessageBoxA(NULL,"Nie odnaleziono serwera", "Error", MB_OK | MB_ICONERROR);
    }
    cout << "Connected!" << endl;
}

string Client::comunicationWithServer(string request)
{
    char response[4096];
    if (send (Connection,request.c_str(), request.size() + 1, 0) != SOCKET_ERROR)
    {
		//string temp = request;
        cout << "CLIENT> " << request << endl;
        //ZeroMemory(response,4096);
        if (recv (Connection, response, 4096, 0) != SOCKET_ERROR)
        {
            cout << "SERVER> " << response << endl;

        }

    }
    return response;
}

Client::~Client()
{
    closesocket(Connection);
    WSACleanup();
}
