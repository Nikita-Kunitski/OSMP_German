#include <winsock2.h>
#include <stdio.h>
 #pragma comment(lib, "Ws2_32.lib")
int main(void)
{
    WORD sockVer;
    WSADATA wsaData;
    int retVal;
 
    sockVer = MAKEWORD(2,2);
 
    WSAStartup(sockVer, &wsaData);
 
    //Создаем сокет
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
 
    if(servSock == INVALID_SOCKET)
    {
        printf("Unable to create socket\n");
		getchar();
        WSACleanup();
        return SOCKET_ERROR;
    }
	SOCKADDR_IN sin;
    sin.sin_family = PF_INET;
    sin.sin_port = htons(1111);
    sin.sin_addr.s_addr = INADDR_ANY;
 
    retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));
    if(retVal == SOCKET_ERROR)
    {
        printf("Unable to bind\n");
        WSACleanup();
        return SOCKET_ERROR;
    }
 
    //Пытаемся начать слушать сокет
    retVal = listen(servSock, 10);
    if(retVal == SOCKET_ERROR)
    {
        printf("Unable to listen\n");
        WSACleanup();
        return SOCKET_ERROR;
    }
    //Ждем клиента
    SOCKET clientSock;
 
    clientSock = accept(servSock, NULL, NULL);
 
    if(clientSock == INVALID_SOCKET)
    {
        printf("Unable to accept\n");
        WSACleanup();
        return SOCKET_ERROR;
    }
 
    char szReq[8]; 
    retVal = recv(clientSock, szReq, 8, 0);
 
    if(retVal == SOCKET_ERROR)
    {
        printf("Unable to recv\n");
        return SOCKET_ERROR;
    }
 
    printf("Got the request from client\n%s\n",szReq);
	
 
    char *szResp = "Response";
 
    printf("Sending response from server\n");
	getchar();
    retVal = send(clientSock, szResp, strlen(szResp), 0);
 
    if(retVal == SOCKET_ERROR)
    {
        printf("Unable to send\n");
        return SOCKET_ERROR;
    }
 
    //Закрываем сокет
    closesocket(clientSock);
    closesocket(servSock);
 
    WSACleanup();
    return 0;
}
