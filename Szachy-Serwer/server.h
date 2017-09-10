#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <process.h>
#include <stdio.h>
#include <winsock2.h>
#include "stdafx.h"

#include "cgamemanager.h"

using namespace std;
class Server
{
    int numberOfClients;
    bool giveFirstId;
public:
    CGameManager *GM;
    Server();
    void SubstractClient ();
    int GetNumberOfClients ();
    bool GetGiveFirstId ();
    void SetGiveFirstId (bool value);
};
unsigned int _stdcall ServClient(void *data);

#endif // SERVER_H

