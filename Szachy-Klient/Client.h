#ifndef CLIENT_H
#define CLIENT_H
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Client
{
    SOCKET Connection;
public:
    Client();
    string comunicationWithServer (string request);
    ~Client();
};

#endif // CLIENT_H
