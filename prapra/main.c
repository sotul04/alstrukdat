#include <stdio.h>
#include <math.h>
#include "point.h"

int main(){
	POINT P1, P2;
	BacaPOINT(&P1);
	TulisPOINT(P1);
	BacaPOINT(&P2);
	TulisPOINT(P2);
	printf("\n");
	//PersamaanLinearDuaVariabel(P1, P2);
	printf("\n");
	Mirror(&P2, TRUE);
	TulisPOINT(P2);
	printf("\n");
	Putar(&P1, -90);
	TulisPOINT(P1);
	printf("\n");
	Geser(&P2, 8, 9);
	TulisPOINT(P2);
	printf("\npanjang: %f", Panjang(P1, P2));
	return 0;
}