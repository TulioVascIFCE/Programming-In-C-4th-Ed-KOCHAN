#include <stdio.h>

struct entry {
	int value;
	struct entry *next;
};

void insertEntry(struct entry *, struct entry *);
void print_list(struct entry *);

void print_list(struct entry *p)
{
	int i;

	for (i = 1; p != NULL; ++i) {
		printf("n%i (%p)\n", i, (void *) p);
		printf(" value: %i\n", p->value);
		printf(" next: %p\n", (void *) p->next);
		p = p->next;
	}
}

void insertEntry(struct entry *newEntry, struct entry *listEntry)
{
	/* Copy previous element's pointer to the new entry */
	newEntry->next = listEntry->next;
	/* Link the new entry to list */
	listEntry->next = newEntry;
}

int main(void) 
{
	struct entry head, n1, n2, n3, n4, n5, n6;
	struct entry *list_pointer = &n1; /* pointer to the beginning of the list */

	head.value = 0;
	head.next = &n1;
	
	n1.value = 100;
	n1.next = &n2;

	n2.value = 200;
	n2.next = &n3;
	
	n3.value = 300;
	n3.next = &n4;

	n4.value = 400;	
	n4.next = &n5;
	
	n5.value = 500;
	n5.next = NULL;

	/* new entrey */
	n6.value = 600;
	n6.next = NULL;
	
	insertEntry(&n6, &head);

	list_pointer = head.next;
	print_list(list_pointer);

	return 0;
}