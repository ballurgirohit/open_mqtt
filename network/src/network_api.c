#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "util.h"
#include "network_api.h"

int Network_Cofigure(){

}

STATUS Network_Connect(ServerConfig *config, int *sock_fd){
	int sock = INVALID_SOCKET;
	STATUS status = ERROR;

	if(!sock_fd || !config){
		return INVALID_PARAM;
	}

	if(SOCKET_ERROR == (sock = socket(AF_INET, 0, 0))){
		perror("socket");
		return SOCKET_ERROR;
	}

	*sock_fd = sock;

	//if(SOCKET_ERROR == connect();)
}

int Network_Send(int sock, ubyte8 *buff, ubyte32 size){
	return send(sock, buff, size, 0);
}

int Network_Recv(int sock, ubyte8 *buff, ubyte32 size){
	return recv(sock, buff, size, 0);
}
