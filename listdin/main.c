#include <stdio.h>
#include "listdin.h"
#include <stdlib.h>

int main(){
	ListDin l;
	CreateListDin(&l, 10);
	readList(&l);
	printList(l);
	dealocateList(&l);
	//ListDin l1, l2, l;
	//CreateListDin(&l, 0);
	/*CreateListDin(&l1, 10);
	//CreateListDin(&l2, 10);
	ElType a1[5] = {1,4,5,2,5};
	//ElType a2[5] = {3,2,5,1,6};
	int i;
	for (i = 0; i < 5; i++){
		ELMT(l1, i) = a1[i];
		//ELMT(l2, i) = a2[i];
	}
	NEFF(l1) = 5;
	//NEFF(l2) = 5;
	printList(l1);
	printf("\n");
	copyList(l1, &l);
	ELMT(l, 0) = 33999;
	printf("\nChange l, then:\n\n");
	sort(&l, 0);
	printList(l1);
	printf("\n");
	printList(l);
	printf("\npanjang b: %d\n", CAPACITY(l));
	printf("\ndi expand mazzeh\n");
	expandList(&l, 10);
	printf("panjang a: %d\n", CAPACITY(l));
	printList(l);
	printf("\npanjang b: %d\n", CAPACITY(l));
	printf("\ndi expand mazzeh\n");
	shrinkList(&l, 9);
	printf("panjang a: %d\n", CAPACITY(l));
	printList(l);
	printf("idx of 5: %d\n", indexOf(l, 5));
	printf("idx full : %s", isFull(l) ? "yes" : "no");
	printf("idx empty : %s", isEmpty(l) ? "yes" : "no");
	printf("\n%d\n", getFirstIdx(l));


	//printList(l2);
	//printf("\n");
	//l = plusMinusList(l1, l2, 1);
	//printf("Setelah plusMinusList\n\n");
	//printList(l1);
	//printf("\n");
	//printList(l2);
	//printf("\n");
	//printList(l);
	//printf("\n");*/
	//dealocateList(&l);
	//dealocateList(&l1);
	//dealocateList(&l2);
}