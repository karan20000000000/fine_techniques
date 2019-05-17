a.out : state.o client.o
	gcc state.o client.o
state.o : state.c state.h
	gcc -c state.c
client.o : client.c state.h
	gcc -c client.c

