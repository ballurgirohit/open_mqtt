INC=-Iapi/inc -Iapp/inc -Iutil/inc

mqtt : main.o mqtt_api.o
		cc -o mqtt main.o mqtt_api.o 

main.o : app/main.c 
		cc -c $(INC) app/main.c
mqtt_api.o : api/src/mqtt_api.c 
		cc -c api/src/mqtt_api.c

clean :
		rm mqtt main.o mqtt_api.o 