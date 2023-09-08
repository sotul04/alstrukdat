#include <stdio.h>
#include "time.h"

int main(){
    int n;
    scanf("%d", &n);
    TIME i, f, first, last, temp;
    CreateTime(&first, 23, 59, 59);
    CreateTime(&last, 0, 0, 0);
    int x;
    for (x = 1; x <= n; x++){
        printf("[%d]\n",x);
        BacaTIME(&i);
        BacaTIME(&f);
        if (TGT(i, f)){
            temp = i;
            i = f;
            f = temp;
        }
        if (TGT(first, i)){
            first = i;
        }
        if (TLT(last, f)){
            last = f;
        }
        printf("%ld\n", Durasi(i, f));
    }
    printf("%d:%d:%d\n", Hour(first), Minute(first), Second(first));
    printf("%d:%d:%d\n", Hour(last), Minute(last), Second(last));
    return 0;

}
