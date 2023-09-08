#include <stdio.h>
#include "point.h"
#include "garis.h"

int main(){
    int b, n, count= 0;
    scanf("%d", &b);
    GARIS L;
    BacaGARIS(&L);
    POINT P;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        BacaPOINT(&P);
        if (JarakGARIS(L, P) <= b){
            count ++;
        }
    }
    printf("%d\n", count);
    return 0;
}
