#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shuffle(int yamafuda[]);
void deal(int yamafuda[], int player[], int *top);
void printHand(int player[], char *mark[], char *kazu[]);
void changeHand(int yamafuda[], int player[], int *top);
int judge(int player[]);
void clear();
void sort(int tmp[], int player[]);
void royalFlush(int player[], int yakuhantei[]);
void straighFlush(int player[], int yakuhantei[]);
void four(int player[], int yakuhantei[]);
void fullHouse(int player[], int yakuhantei[]);
void flush(int player[], int yakuhantei[]);
void straigh(int player[], int yakuhantei[]);
void three(int player[], int yakuhantei[]);
void two(int player[], int yakuhantei[]);
void one(int player[], int yakuhantei[]);

int main(void){
    srand((unsigned)time(NULL));

    int top = 0;
    char ana;
    int yamafuda[52];
    int player1[5];
    int player2[5];
    int yakuhantei1[6];
    int yakuhantei2[6];
    int tmp1[5];
    int tmp2[5];
    //数字表示の素
    char *mark[] = {"♥","♦","♣","♠"};
    char *kazu[] = {"2","3","4","5","6","7","8","9","10","J","Q","k","A"};
    system("clear");
    //山札形成
    for(int i = 0;i<52;i++){
            yamafuda[i] = i;
    }
    //シャッフル
    shuffle(yamafuda);
    //手札配る
    deal(yamafuda, player1, &top);
    deal(yamafuda, player2, &top);
    printHand(player1, mark, kazu);
    changeHand(yamafuda, player1, &top);
    system("clear");
    printf("player2はEnterを押してください\n");
    clear();
    printHand(player2, mark, kazu);
    changeHand(yamafuda,player2, &top);
    system("clear");
    printf("両方の手札を表示します\nEnterを押してください\n");
    clear();

    //手札表示
    printHand(player1, mark, kazu);
    printHand(player2, mark, kazu);
    //役判定
    while(yakuhantei1 == 0){
        void royalFlush(player1, yakuhantei1);
        void straighFlush(player1, yakuhantei1);
        void four(player1, yakuhantei1);
        void fullHouse(player1, yakuhantei1);
        void flush(player1, yakuhantei1);
        void straigh(player1, yakuhantei1);
        void three(player1, yakuhantei1);
        void two(player1, yakuhantei1);
        void one(player1, yakuhantei1);
    }
    
    while(yakuhantei2 == 0){
        void royalFlush(player2, yakuhantei2);
        void straighFlush(player2, yakuhantei2);
        void four(player2, yakuhantei2);
        void fullHouse(player2, yakuhantei2);
        void flush(player2, yakuhantei2);
        void straigh(player2, yakuhantei2);
        void three(player2, yakuhantei2);
        void two(player2, yakuhantei2);
        void one(player2, yakuhantei2);
    }
    sort(tmp1, player1);
    sort(tmp2, player2);


    return 0;
}


//シャッフル
void shuffle(int yamafuda[]){
    for(int i = 51;i>0;i--){

        int cp,a;
        a = rand() % (i + 1);
        cp = yamafuda[i];
        yamafuda[i] = yamafuda[a];
        yamafuda[a] = cp;
    }
}
//手札表示
void printHand(int player[], char *mark[], char *kazu[]){
    for(int i=0;i<5;i++){
        int gara,suuji;
        gara = player[i] / 13;
        suuji = player[i] % 13;
        printf("%s%s ",mark[gara],kazu[suuji]);
    }
    printf("\n");
}

//手札配る
void deal(int yamafuda[], int player[], int *top){
    int sentaku;
    printf("カードを入れ替えますか？ はい（１）/ いいえ （２）");
    scanf("%d",&sentaku);
    if(sentaku == 1){
        int n, k;

        printf("何枚交換しますか？");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("何枚目のカードを交換しますか？(1〜5) ");
            scanf("%d",&k);
            player[k-1] = yamafuda[*top];
            (*top)++;

        }
    }
}

//表示クリア
void clear(){
    while(getchar() != '\n'); 
    getchar();                
    system("clear");
}


void royalFlush(int player[], int yakuhantei[]){}