#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "util.h"
#include "network_api.h"
#include <netdb.h>
#include <string.h>

sbyte32 Network_Cofigure(){

}

STATUS Network_Connect(ServerConfig *config, sbyte32 *sock_fd){
	sbyte32 sock = INVALID_SOCKET;
	STATUS status = ERROR;
	struct hostent *hp = 0;
	struct sockaddr_in addr;

	if(!sock_fd || !config){
		return INVALID_PARAM;
	}

	//Create a socket
	if(SOCKET_ERROR == (sock = socket(AF_INET, SOCK_STREAM, 0))){
		perror("socket");
		return SOCKET_ERROR;
	}

	*sock_fd = sock;

	//Resolve the server domain
	if(0 == (hp = gethostbyname2(config->url, AF_INET))){
		perror("gethostbyname2");
		return SOCKET_ERROR;
	}

	//Fill address structure
	addr.sin_family = AF_INET;
	addr.sin_port = htons(config->port);
	memcpy(&addr.sin_addr, hp->h_addr_list[0], sizeof(struct sockaddr));

#ifdef _DEBUG_
	char buffer[50];
	inet_ntop( AF_INET, &addr.sin_addr, buffer, sizeof( buffer ));
	DBG(( "address:%s\n", buffer ));
#endif

	//Connect to the server
	if(SOCKET_ERROR == connect(sock, (struct sockaddr*)&addr, sizeof(struct sockaddr))){
		perror("connect");
		return SOCKET_ERROR;
	}

	return SUCCESS;
}

sbyte32 Network_Send(sbyte32 sock, ubyte8 *buff, ubyte32 size){
	return send(sock, buff, size, 0);
}

sbyte32 Network_Recv(sbyte32 sock, ubyte8 *buff, ubyte32 size){
	return recv(sock, buff, size, 0);
}
