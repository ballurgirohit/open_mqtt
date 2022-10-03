#include <stdio.h>
#include <stdlib.h>
#include "mqtt_api.h"
#include "util.h"
#include "network_api.h"
#include "config.h"

sbyte32 main(){
	sbyte32 sock = INVALID_SOCKET;
	ServerConfig config;

	MQTT_API_Configure();

	config.port = port;
	strncpy(config.url, url, strlen(url));

	if(SUCCESS == Network_Connect(&config, &sock)){

	}
}
