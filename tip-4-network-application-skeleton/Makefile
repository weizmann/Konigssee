INCLUDES = -I../include

server : tcp_server.o etip.o
	gcc ${INCLUDES} -o server etip.o tcp_server.o 


tcp_server.o : tcp_server.c ../include/inc.h 
	gcc ${INCLUDES} -c tcp_server.c 

etip.o : ../include/etip.c ../include/etip.h
	gcc ${INCLUDES} -c ../include/etip.c

clean:
	rm *.o *.d
