INC=-I../api/inc -I../app/inc -I../util/inc -I../network/inc -I../config -I../protocol/inc

OBJDIR	:= bin
CC = cc

$(OBJDIR)/mqtt : main.o mqtt_api.o network_api.o
		cc -o $@ $^		 

%.o: ../network/src/%.c
			$(CC) -c $(INC) $(CFLAGS) $<

%.o: ../protocol/src/%.c
			$(CC) -c $(INC) $(CFLAGS) $<

%.o: ../app/%.c
		 	$(CC) -c $(INC) $(CFLAGS) $<		 	
		 
%.o: ../api/src/%.c
		 	$(CC) -c $(INC) $(CFLAGS) $<		 
		
clean :
		rm -rf bin/* *.o