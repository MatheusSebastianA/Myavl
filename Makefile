CFLAGS = -Wall -std=c90  # flags de compilacao

CC = gcc

# arquivos-objeto
	objects = myavl.o lib_arvore_avl.o
     
myavl: myavl.o lib_arvore_avl.o
	$(CC) -o myavl myavl.o lib_arvore_avl.o

lib_arvore_avl.o: lib_arvore_avl.c
	$(CC) -c $(CFLAGS) lib_arvore_avl.c

myavl.o: myavl.c
	$(CC) -c $(CFLAGS) myavl.c

clean:
	rm -f $(objects) 

purge:
	rm -f myavl
