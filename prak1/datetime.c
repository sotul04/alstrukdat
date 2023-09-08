#include "datetime.h"
#include <stdio.h>


int GetMaxDay(int M, int Y){
    if (M == 2){
        if (((Y%4==0)&&(Y%100!=0))||(Y%400==0)){
            return 29;
        } else {
            return 28;
        }
    } else if (M == 2 || M == 4|| M == 6 || M == 9|| M == 11){
        return 30;
    } return 31;
}
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
    int day = GetMaxDay(M, Y);
    return (IsTIMEValid(h, m, s))&&(Y > 0)&&(M > 0)&&(M <= 12)&&(D > 0)&&(D <= day);
}
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    TIME temp;
    CreateTime(&temp, hh, mm, ss);
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Time(*D) = temp;
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D){
    int d, m, y, hh, mm, ss;
    do {
        scanf("%d %d %d %d %d %d", &d, &m, &y, &hh, &mm, &ss);
        if (!IsDATETIMEValid(d, m, y, hh, mm, ss)){
            printf("DATETIME tidak valid\n");
        }
    }while (!IsDATETIMEValid(d, m, y, hh, mm, ss));
    CreateDATETIME(D, d,m,y,hh,mm,ss);
}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */

void TulisDATETIME(DATETIME D){
    printf("%d/%d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2){
    return (Day(D1) == Day(D2))&&(Month(D1)==Month(D2))&&(Year(D1)==Year(D2))&&(TEQ(Time(D1), Time(D2)));
}
/* Mengirimkan true jika D1=D2, false jika tidak */
boolean DNEQ(DATETIME D1, DATETIME D2){
    return !DEQ(D1, D2);
}
/* Mengirimkan true jika D1 tidak sama dengan D2 */
boolean DLT(DATETIME D1, DATETIME D2){
    if (Year(D1) > Year(D2)){
        return 0;
    } else if (Year(D1) == Year(D2)){
        if (Month(D1) > Month(D2)){
            return 0;
        } else if (Month(D1) == Month(D2)){
            if (Day(D1) > Day(D2)){
                return 0;
            } else if (Day(D1) == Day(D2)){
                return TLT(Time(D1), Time(D2));
            }
        }
    }
    return 1;
}
/* Mengirimkan true jika D1<D2, false jika tidak */
boolean DGT(DATETIME D1, DATETIME D2){
    return DNEQ(D1, D2)&&!DLT(D1, D2);
}
/* Mengirimkan true jika D1>D2, false jika tidak */
DATETIME DATETIMENextNDetik(DATETIME D, int N){
    int time = TIMEToDetik(Time(D)) + N;
    if (time < 0){
        int i = time;
        while (i < 0){
            i += 86400;
            Day(D)--;
            if (Day(D) == 0){
                Month(D)--;
                if (Month(D) == 0){
                    Month(D) = 12;
                    Year(D)--;
                    if (Year(D) == 0){
                        Year(D) = 1;
                    }
                }
                Day(D) = GetMaxDay(Month(D), Year(D));
            }
        }
        Time(D) = DetikToTIME(i);
    } else {
        while (time >= 86400){
            time -= 86400;
            Day(D) ++;
            if (Day(D) > GetMaxDay(Month(D), Year(D))){
                Day(D) = 1;
                Month(D)++;
                if (Month(D) > 12){
                    Month(D) = 1;
                    Year(D)++;
                }
            }
        }
        Time(D) = DetikToTIME(time);
    }
    return D;
}
/* Mengirim salinan D dengan detik ditambah N */
DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    return DATETIMENextNDetik(D, -N);
}
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    int nDay = 0;
    while ((DLT(DAw, DAkh))){
        nDay++;
        if (Day(DAw)==Day(DAkh)&&Month(DAw)==Month(DAkh)&&Year(DAw)==Year(DAkh)){
            nDay--;
        }
        DAw = DATETIMENextNDetik(DAw, 86400);
    }
    return nDay*86400-TIMEToDetik(Time(DAw))+TIMEToDetik(Time(DAkh));
}
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
