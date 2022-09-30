INC=-I../api/inc -I../app/inc -I../util/inc

OBJDIR	:= bin
CC = cc

$(OBJDIR)/mqtt : main.o mqtt_api.o
		cc -o $@ $^

#$(ODIR)/%.o : %.c
#		 $(CC) -c $(INC) $(CFLAGS) $<
  
main.o: ../app/main.c
		 	$(CC) -c $(INC) $(CFLAGS) $<		 	
		 
mqtt_api.o: ../api/src/mqtt_api.c
		 	$(CC) -c $(INC) $(CFLAGS) $<		 
		
clean :
		rm -rf build/bin/* build/obj/* build/*.* *.o