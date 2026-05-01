#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void){
    int a[5];
     int *p=NULL;
     p=a;
    srand((unsigned) time(NULL));
    printf("発生した乱数：");
    for(int i=0;i<5;i++){
        *p=rand() % 100 + 0;
        printf("%d  ",*p);
        p++;
    }
    p=a;
    printf("\n");
    printf("2倍した値");
   for(int i=0;i<5;i++){
    *p = *p*2;
    printf("%d ",*p);
    p++;
   }
   printf("\n");
    return 0;

}

