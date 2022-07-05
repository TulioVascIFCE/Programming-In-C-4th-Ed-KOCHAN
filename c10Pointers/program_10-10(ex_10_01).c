//Program 10.10 Returning a Pointer from a Function

#include <stdio.h>
#include <stdlib.h>

struct entry{
	int value;
	struct entry *next;
	};

struct entry *findEntry(struct entry *, int);

int main (int argc, char *argv[]) {
	
	struct entry n1, n2, n3;
	struct entry *nHead, *listPtr;
	int search;

	nHead = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = (struct entry *) 0;

	n1.value = 100;
	n2.value = 200;
	n3.value = 300;

	if (argc != 2){
		printf("Use: ./exe.e inteiro\n");
		exit(1);
	}
	search = atoi(*(argv + 1));

	listPtr = findEntry(nHead, search);

	if (listPtr != (struct entry *)0) printf("Found, %i.\n", listPtr->value);
	else printf("Not Found.\n");

	return 0;
	}

struct entry *findEntry(struct entry *lista, int match){
	while (lista != (struct entry *) 0){
		if (lista->value == match) return lista;
		else lista = lista->next;
		}
	return (struct entry *) 0;
	}