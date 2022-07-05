//Program 10.6 Using Linked Lists (Adaptado)
//Function to use linked lists

#include <stdio.h>

struct entry {
		int value;
		struct entry *next;
	};

int main(void) {
	struct entry *n, n1, n2, n3;
	int i;

	n1.value = 100;
	n2.value = 200;
	n3.value = 300;

	n = &n1;
	n1.next = &n2;
	n2.next = &n3;

	i = n->value;

	printf("%i\t", i);
	printf("%i\t", n1.next->value);
	printf("%i\n", n2.next->value);

	return 0;
	}