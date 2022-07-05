//Program 10.7 Traversing a Linked List (Adaptado)
// Program to traverse a linked list

#include <stdio.h>

int main(void) 
{
	struct entry {
		int value;
		struct entry *next;
		};

	struct entry node[3];
	struct entry *list_pointer = &node[0];
	int i = 0;

	node[0].next  = &node[1];
	node[1].next  = &node[2];
	node[2].next  = (struct entry *) 0;    /* mark list end with null pointer */
	
	while (list_pointer != (struct entry *) 0) {
		scanf("%i", &node[i].value);
		printf("%i\n", list_pointer->value * (2<<i));
		list_pointer = list_pointer->next;
		i++;
		}

	return 0;
}