a.out : 1_list.o 1_client.o
	gcc 1_list.o 1_client.o
1_list.o : 1_list.c 1_list.h
	gcc 1_list.c -c
1_client.o : 1_client.c 1_list.h
	gcc 1_client.c -c

