#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "server.h"
#include <string>

#pragma comment(lib, "Ws2_32.lib")

Server server;

Server::Server()
{
    WSADATA wsaData;
    int iResult;
    sockaddr_in addr;
    SOCKET sock,client;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(2571);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    iResult = WSAStartup(MAKEWORD(2,2),&wsaData);

    if(iResult)
    {
        printf("WSA startup failed");
        return;
    }

    sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(sock == INVALID_SOCKET)
    {
        printf("Invalid socket");
        return;
    }

    iResult = bind(sock,(sockaddr*)&addr,sizeof(sockaddr_in ));

    if(iResult)
    {
        printf("bind failed %u",GetLastError());
        return;
    }

    iResult = listen(sock,SOMAXCONN);

    if(iResult)
    {
        printf("iResult failed %u",GetLastError());
        return;
    }
    numberOfClients = 0;
    giveFirstId = false;
    GM = new CGameManager ();

    while(client = accept(sock,0,0))
    {
        if (numberOfClients < 2)
        {
            if(client == INVALID_SOCKET)
            {
                printf("invalid client socket",GetLastError());
                continue;
            }
            _beginthreadex(0,0,ServClient,(void*)&client,0,0);
            numberOfClients++;
        }
        else if (numberOfClients == 2)
        {
            cout << "Maximum number of clients has been reached" << endl;
            return;
        }
    }
}

void Server::SubstractClient()
{
    if (numberOfClients > 0)
    {
        numberOfClients--;
        Server ();
    }
}

int Server::GetNumberOfClients()
{
    return numberOfClients;
}

bool Server::GetGiveFirstId()
{
    return giveFirstId;
}

void Server::SetGiveFirstId(bool value)
{
    giveFirstId = value;
}


unsigned int _stdcall ServClient(void *data)
{
    extern Server server;
    SOCKET* client =(SOCKET*)data;
    SOCKET Client = *client;
    printf("%s \t %d\n","Client connected",GetCurrentThreadId());
    char recvbuf[4096];
    int bytesRecv;
	char response[4096] = "";
	bool wypisz = false;
	while (true)
	{
		bytesRecv = recv(Client, recvbuf, 4096, 0);
		string recvString(recvbuf);
		wypisz = false;
		if (recvString == "whenStart")
		{
			if (server.GetNumberOfClients() == 2)
				strcpy_s(response, "now");
			else
				strcpy_s(response, " ");
		}
		else if (recvString == "giveId")
		{
			if (server.GetGiveFirstId() == false)
			{
				strcpy_s(response, "pW");
				server.SetGiveFirstId(true);
			}
			else
				strcpy_s(response, "pB");
		}
		else if (recvString.find("update") != string::npos)
		{
			string responseString;
			responseString = server.GM->SerializationFigurePosition();
			strcpy_s(response, responseString.c_str());
		}
		else if ((recvString.find("pW") != string::npos || recvString.find("pB") != string::npos))
		{
			string responseString;
			responseString = server.GM->CurrentPlayerAction(recvString);
			strcpy_s(response, responseString.c_str());
			wypisz = true;
		}
		else if (bytesRecv == SOCKET_ERROR)
		{
			closesocket(Client);
			printf("%s \t %d\n", "Client disconnected", GetCurrentThreadId());
			server.SubstractClient();
			cout << "Number of clients: " << server.GetNumberOfClients() << endl;
			return 0;
		}
		else
			strcpy_s(response, " ");
		send(Client, response, 4096, 0);
			if (wypisz)
		{
			printf("%s \t %d\n", recvbuf, GetCurrentThreadId());
			cout << "SERVER> " << response << endl;
		}
	}
    return 0;
}

