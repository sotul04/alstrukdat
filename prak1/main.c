#include <stdio.h>
#include "datetime.h"

int main(){
	DATETIME D1, D2;
	CreateDATETIME(&D1, 21, 2, 2003, 12, 0, 2);
	CreateDATETIME(&D2, 21, 2, 2004, 12, 0, 3);

	printf("durasi : %ld detik\n", DATETIMEDurasi(D1, D2));
	//BacaDATETIME(&D1);
	TulisDATETIME(D1);
	printf("\n");
	//BacaDATETIME(&D2);
	TulisDATETIME(D2);
	printf("\n");
	printf("%s\n", DEQ(D1, D2) ? "Sama" : "Tidak sama");
	printf("%s\n", DNEQ(D1, D2) ? "Tidak sama" : "Sama");
	printf("%s\n", DLT(D1, D2) ? "Lebih kecil" : "Tidak lebih kecil");
	printf("%s\n", DGT(D1, D2) ? "Lebih besar" : "Tidak lebih besar");
	TulisDATETIME(DATETIMENextNDetik(D1, 43198));
	printf("\n");
	TulisDATETIME(DATETIMEPrevNDetik(D1, 43203));
	printf("\n");
	return 0;
}
