#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    int yamafuda[3][13];
    for(int i=0;i<3;i++){
        for(int j=0;j<13;j++){
            yamafuda[i][j] = 0;//山札の値全部ゼロ
        }
    }
    
    return 0;
}
