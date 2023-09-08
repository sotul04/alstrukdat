#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(){
	POINT p1, p2, p3;
	BacaPOINT(&p3);
	BacaPOINT(&p1);
	BacaPOINT(&p2);
	int a, b, c, p, q, r, s;
	p = Absis(p1) - Absis(p2);
	q = Absis(p2) - Absis(p3);
	r = Absis(p1) + Absis(p2);
	s = Absis(p2) + Absis(p3);
	c = (q*(Ordinat(p1)-Ordinat(p2))-p*(Ordinat(p2)-Ordinat(p3)))/(p*q*(r-s));
	b = (Ordinat(p1)-Ordinat(p2)-c*p*r)/p;
	a = Ordinat(p1) - b*Absis(p1) - c*Absis(p1)*Absis(p1);
	printf("%d\n", a);
	return 0;
}	
