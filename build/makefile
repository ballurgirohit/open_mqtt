INC=-I../api/inc -I../app/inc -I../util/inc

OBJDIR	:= bin
CC = cc

$(OBJDIR)/mqtt : main.o mqtt_api.o
		cc -o $@ $^

#$(ODIR)/%.o : %.c
#		 $(CC) -c $(INC) $(CFLAGS) $<
  
%.o: ../app/%.c
		 	$(CC) -c $(INC) $(CFLAGS) $<		 	
		 
%.o: ../api/src/%.c
		 	$(CC) -c $(INC) $(CFLAGS) $<		 
		
clean :
		rm -rf bin/* build/*.* 