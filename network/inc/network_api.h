#ifndef __NETWORK_H__
#define __NETWORK_H__

#define URL_LENGTH 255
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

typedef struct server_config{
	ubyte8 url[URL_LENGTH];
	ubyte16 port;
}ServerConfig;

STATUS Network_Connect(ServerConfig *config, int *sock_fd);

int Network_Recv(int sock, ubyte8 *buff, ubyte32 size);

#endif //__NETWORK_H__
