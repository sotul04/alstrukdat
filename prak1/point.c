/* File: point.c */
/* Tanggal: 3 September 2022 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEKLARASI PROTOTIPE PRIMITIF *** */

/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
	Absis(*P) = X;
	Ordinat(*P) = Y;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
	float x, y;
	scanf("%f %f", &x, &y);
	CreatePoint(P, x, y);
}
void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
	printf("(%.02f,%.02f)", Absis(P), Ordinat(P));
}             

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	return (Absis(P1) == Absis(P2))&&(Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
	return (Absis(P1) != Absis(P2))||(Ordinat(P1) != Ordinat(P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
	return (Absis(P) == 0)&&(Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
	return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
	return (Absis(P) == 0);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
	if (Absis(P) > 0){
		if (Ordinat(P) > 0){
			return 1;
		} else {
			return 4;
		}
	} else if (Absis(P) < 0){
		if (Ordinat(P) > 0){
			return 2;
		} else {
			return 3;
		}
	}
	return 0;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */  
	POINT nextP;
	nextP = P;
	Absis(nextP)+=1;
	return nextP;
}            
POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
	POINT nextP;
	nextP = P;
	Ordinat(nextP)+=1;
	return nextP;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
	POINT next;
	next = P;
	Absis(next) += deltaX;
	Ordinat(next) += deltaY;
	return next;
}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
	POINT reflect;
	reflect = P;
	if (SbX){
		Ordinat(reflect) *= -1;
	} else {
		Absis(reflect) *= -1;
	}
	return reflect;
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
	float distance;
	distance = sqrt(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P));
	return distance;
}
float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
	float dx, dy, distance;
	dx = Absis(P1)-Absis(P2);
	dy = Ordinat(P1)-Ordinat(P2);
	distance = sqrt(dx*dx+dy*dy);
	return distance;
}
void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
	CreatePoint(P, Absis(*P)+deltaX, Ordinat(*P)+deltaY);
}
void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
	Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
	Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
	if (SbX){
		Ordinat(*P) *= -1;
	} else {
		Absis(*P) *= -1;
	}
}
void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
	Sudut = Sudut*M_PI/180;
	float xfinal, yfinal;
	xfinal = cos(Sudut)*Absis(*P)+sin(Sudut)*Ordinat(*P);
	yfinal = -sin(Sudut)*Absis(*P)+cos(Sudut)*Ordinat(*P);
	CreatePoint(P, xfinal, yfinal);
}
void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
/* I.S. P1 dan P2 terdefinisi */
/* Prekondisi: dijamin a dan b merupaka bilangan bertipe integer */
/* F.S. Dibentuk sebuah persamaan garis y = ax + b yang memenuhi untuk P1 dan P2 */
/* Keluarkan nilai a dan b */
/* Output a dan b tercetak di layar sebagai bilangan bertipe integer dengan format "(a,b)" */
	int a, b;
	a = (Ordinat(P2)-Ordinat(P1))/(Absis(P2)-Absis(P1));
	b = Ordinat(P1) - Absis(P1)*(Ordinat(P2)-Ordinat(P1))/(Absis(P2)-Absis(P1));
	printf("(%d,%d)", a, b);
}