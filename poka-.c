#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shuffle(int yamafuda[]);
void deal(int yamafuda[], int player[], int *top);
void printHand(int player[], char *mark[], char *kazu[]);
void changeHand(int yamafuda[], int player[], int *top);
int judge(int player[]);
void clear();

int main(void){
    srand((unsigned)time(NULL));

    int top = 0;
    char ana;
    int yamafuda[52];
    int player1[5];
    int player2[5];
    int rank1, rank2;
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
    rank1 = judge(player1);
    rank2 = judge(player2);

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

//手札配る
void deal(int yamafuda[], int player[], int *top){
    for(int i = 0;i<5;i++){
        player[i] = yamafuda[*top];
        (*top)++;
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

//手札入れ替え
void changeHand(int yamafuda[], int player[],int *top){
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

// === 役判定関数 (ユーザー定義) ===
int judge(int player[]) {
    int count[13] = {0}; // 各数字の枚数
    int suits[4] = {0};  // 各マークの枚数
    int sorted[5];       // 並び替え用

    for(int i = 0; i < 5; i++){
        int n = player[i] % 13;
        int s = player[i] / 13;
        count[n]++;
        suits[s]++;
        sorted[i] = n;
    }

    // ストレート判定用に数字をソート
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 5; j++){
            if(sorted[i] > sorted[j]){
                int t = sorted[i]; sorted[i] = sorted[j]; sorted[j] = t;
            }
        }
    }

    // フラッシュ判定
    int is_flush = 0;
    for(int i = 0; i < 4; i++) if(suits[i] == 5) is_flush = 1;

    // ストレート判定
    int is_straight = 0;
    if(sorted[0]+1==sorted[1] && sorted[1]+1==sorted[2] && sorted[2]+1==sorted[3] && sorted[3]+1==sorted[4]) is_straight = 1;
    // A2345の特殊ストレート
    if(sorted[0]==0 && sorted[1]==1 && sorted[2]==2 && sorted[3]==3 && sorted[4]==12) is_straight = 1;

    // ペア・スリー・フォーの集計
    int pairs = 0, three = 0, four = 0;
    for(int i = 0; i < 13; i++){
        if(count[i] == 2) pairs++;
        else if(count[i] == 3) three++;
        else if(count[i] == 4) four++;
    }

    // 強い役から順に数値を返して判定
    if(is_straight && is_flush) { printf("役：ストレートフラッシュ\n"); return 9; }
    if(four)                    { printf("役：フォーカード\n");       return 8; }
    if(three && pairs == 1)     { printf("役：フルハウス\n");       return 7; }
    if(is_flush)                { printf("役：フラッシュ\n");         return 6; }
    if(is_straight)             { printf("役：ストレート\n");         return 5; }
    if(three)                   { printf("役：スリーカード\n");       return 4; }
    if(pairs == 2)              { printf("役：ツーペア\n");           return 3; }
    if(pairs == 1)              { printf("役：ワンペア\n");           return 2; }

    printf("役：ハイカード（なし）\n");
    return 1;
}
