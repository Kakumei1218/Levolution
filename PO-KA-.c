#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void){
    int gara,suuzi;
    int tefuda[2][5];
    srand((unsigned) time(NULL));
    for(int i=0;i<5;i++){
    gara = rand() % 4 + 1;//1=♥,2=♠,3=♦,4=♣
    suuzi = rand() % 13 + 1;
    printf("%d,%d\n",gara,suuzi);

    return 0;
}
