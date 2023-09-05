#include "liststatik.h"
#include <stdio.h>

int main(){
	ListStatik l;
	CreateListStatik(&l);
	printList(l);
	printf("\n");
	readList(&l);
	printList(l);
	printf("\nlength: %d\n", listLength(l));
	insertFirst(&l, 6);
	printList(l);
	printf("\n");
	insertLast(&l, 3);
	printList(l);
	printf("\n");
	ElType out;
	deleteFirst(&l, &out);
	printList(l);
	printf(" out = %d\n", out);
	deleteAt(&l, &out, 2);
	printList(l);
	printf(" out = %d\n", out);
	deleteLast(&l, &out);
	printList(l);
	printf(" out = %d\n", out);
	//sortList(&l, 1);
	//printList(l);
	//printf("\n");
	//sortList(&l, 0);
	//printList(l);
	//printf("\n");
	
	return 0;
}