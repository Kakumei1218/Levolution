#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shuffle(int yamafuda[]);
void printHand(int player[], char *mark[], char *kazu[]);
void changeHand(int yamafuda[], int player[], int *top);
void clear();
void sort(int tmp[]);
int royalFlush(int player[], int yakuhantei[]);
int straighFlush(int player[], int yakuhantei[]);
int four(int player[], int yakuhantei[]);
int fullHouse(int player[], int yakuhantei[]);
int flush(int player[], int yakuhantei[]);
int straigh(int player[], int yakuhantei[]);
int three(int player[], int yakuhantei[]);
int two(int player[], int yakuhantei[]);
int one(int player[], int yakuhantei[]);

int main(void){

    srand((unsigned)time(NULL));

    int top = 0;

    int yamafuda[52];
    int player1[5];
    int player2[5];

    // [0]役
    // [1]強い数字
    // [2]弱い数字
    // [3]残り札
    int yakuhantei1[4] = {0};
    int yakuhantei2[4] = {0};

    char *mark[] = {"♥","♦","♣","♠"};
    char *kazu[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

    system("clear");

    //山札
    for(int i=0;i<52;i++){
        yamafuda[i] = i;
    }

    shuffle(yamafuda);

    //配る
    for(int i=0;i<5;i++){
        player1[i] = yamafuda[top];
        top++;
    }

    for(int i=0;i<5;i++){
        player2[i] = yamafuda[top];
        top++;
    }

    //player1
    printf("player1 の手札\n");
    printHand(player1, mark, kazu);

    changeHand(yamafuda, player1, &top);
    system("clear");


    printf("\nplayer2はEnterを押してください\n");
    clear();

    //player2
    printf("player2 の手札\n");
    printHand(player2, mark, kazu);

    changeHand(yamafuda, player2, &top);

    system("clear");

    printf("両方の手札を表示します\n");
    printf("Enterを押してください\n");

    clear();

    //player1
    printf("player1 : ");
    printHand(player1, mark, kazu);

    if(royalFlush(player1, yakuhantei1)){
        printf("ロイヤルフラッシュ\n");
    }
    else if(straighFlush(player1, yakuhantei1)){
        printf("ストレートフラッシュ\n");
    }
    else if(four(player1, yakuhantei1)){
        printf("フォーカード\n");
    }
    else if(fullHouse(player1, yakuhantei1)){
        printf("フルハウス\n");
    }
    else if(flush(player1, yakuhantei1)){
        printf("フラッシュ\n");
    }
    else if(straigh(player1, yakuhantei1)){
        printf("ストレート\n");
    }
    else if(three(player1, yakuhantei1)){
        printf("スリーカード\n");
    }
    else if(two(player1, yakuhantei1)){
        printf("ツーペア\n");
    }
    else if(one(player1, yakuhantei1)){
        printf("ワンペア\n");
    }
    else{

        printf("ハイカード\n");

        yakuhantei1[0] = 1;

        int max = 0;

        for(int i=0;i<5;i++){

            int num = player1[i] % 13;

            if(num > max){
                max = num;
            }
        }

        yakuhantei1[1] = max;
    }

    printf("\n");

    //player2
    printf("player2 : ");
    printHand(player2, mark, kazu);

    if(royalFlush(player2, yakuhantei2)){
        printf("ロイヤルフラッシュ\n");
    }
    else if(straighFlush(player2, yakuhantei2)){
        printf("ストレートフラッシュ\n");
    }
    else if(four(player2, yakuhantei2)){
        printf("フォーカード\n");
    }
    else if(fullHouse(player2, yakuhantei2)){
        printf("フルハウス\n");
    }
    else if(flush(player2, yakuhantei2)){
        printf("フラッシュ\n");
    }
    else if(straigh(player2, yakuhantei2)){
        printf("ストレート\n");
    }
    else if(three(player2, yakuhantei2)){
        printf("スリーカード\n");
    }
    else if(two(player2, yakuhantei2)){
        printf("ツーペア\n");
    }
    else if(one(player2, yakuhantei2)){
        printf("ワンペア\n");
    }
    else{

        printf("ハイカード\n");

        yakuhantei2[0] = 1;

        int max = 0;

        for(int i=0;i<5;i++){

            int num = player2[i] % 13;

            if(num > max){
                max = num;
            }
        }

        yakuhantei2[1] = max;
    }

    printf("\n");

    //勝敗
    if(yakuhantei1[0] > yakuhantei2[0]){
        printf("player1 の勝ち\n");
    }
    else if(yakuhantei2[0] > yakuhantei1[0]){
        printf("player2 の勝ち\n");
    }
    else{

        if(yakuhantei1[1] > yakuhantei2[1]){
            printf("player1 の勝ち\n");
        }
        else if(yakuhantei2[1] > yakuhantei1[1]){
            printf("player2 の勝ち\n");
        }

        else{

            if(yakuhantei1[2] > yakuhantei2[2]){
                printf("player1 の勝ち\n");
            }
            else if(yakuhantei2[2] > yakuhantei1[2]){
                printf("player2 の勝ち\n");
            }

            else{

                if(yakuhantei1[3] > yakuhantei2[3]){
                    printf("player1 の勝ち\n");
                }
                else if(yakuhantei2[3] > yakuhantei1[3]){
                    printf("player2 の勝ち\n");
                }
                else{
                    printf("引き分け\n");
                }
            }
        }
    }

    return 0;
}


//シャッフル
void shuffle(int yamafuda[]){

    for(int i=51;i>0;i--){

        int a = rand() % (i + 1);

        int cp = yamafuda[i];
        yamafuda[i] = yamafuda[a];
        yamafuda[a] = cp;
    }
}


//手札表示
void printHand(int player[], char *mark[], char *kazu[]){

    for(int i=0;i<5;i++){

        int gara = player[i] / 13;
        int suuji = player[i] % 13;

        printf("%s%s ",mark[gara],kazu[suuji]);
    }

    printf("\n");
}


//交換
void changeHand(int yamafuda[], int player[], int *top){

    int sentaku;

    printf("カードを交換しますか？ はい(1) / いいえ(2) : ");
    scanf("%d",&sentaku);

    if(sentaku == 1){

        int n,k;

        printf("何枚交換しますか？ : ");
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            printf("何枚目を交換しますか？(1〜5) : ");
            scanf("%d",&k);

            player[k-1] = yamafuda[*top];

            (*top)++;
        }
    }
}


//clear
void clear(){

    while(getchar() != '\n');

    getchar();

    system("clear");
}


//sort
void sort(int tmp[]){

    for(int i=0;i<4;i++){

        for(int j=i+1;j<5;j++){

            if(tmp[i] > tmp[j]){

                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }
}


//ロイヤル
int royalFlush(int player[], int yakuhantei[]){

    int tmp[5];
    int gara = player[0] / 13;

    for(int i=0;i<5;i++){

        tmp[i] = player[i] % 13 + 2;

        if(player[i] / 13 != gara){
            return 0;
        }
    }

    sort(tmp);

    if(tmp[0]==10 && tmp[1]==11 && tmp[2]==12
    && tmp[3]==13 && tmp[4]==14){

        yakuhantei[0] = 10;
        yakuhantei[1] = 14;

        return 1;
    }

    return 0;
}


//ストレートフラッシュ
int straighFlush(int player[], int yakuhantei[]){

    int tmp[5];
    int gara = player[0] / 13;

    for(int i=0;i<5;i++){

        tmp[i] = player[i] % 13;

        if(player[i] / 13 != gara){
            return 0;
        }
    }

    sort(tmp);

    for(int i=0;i<4;i++){

        if(tmp[i+1] != tmp[i] + 1){
            return 0;
        }
    }

    yakuhantei[0] = 9;
    yakuhantei[1] = tmp[4];

    return 1;
}


//フォーカード
int four(int player[], int yakuhantei[]){

    int cnt[13] = {0};

    for(int i=0;i<5;i++){
        cnt[player[i] % 13]++;
    }

    for(int i=12;i>=0;i--){

        if(cnt[i] == 4){

            yakuhantei[0] = 8;
            yakuhantei[1] = i;

            return 1;
        }
    }

    return 0;
}


//フルハウス
int fullHouse(int player[], int yakuhantei[]){

    int cnt[13] = {0};

    int san = -1;

    for(int i=0;i<5;i++){
        cnt[player[i] % 13]++;
    }

    for(int i=12;i>=0;i--){

        if(cnt[i] == 3){
            san = i;
        }
    }

    if(san != -1){

        yakuhantei[0] = 7;
        yakuhantei[1] = san;

        return 1;
    }

    return 0;
}


//フラッシュ
int flush(int player[], int yakuhantei[]){

    int gara = player[0] / 13;

    for(int i=1;i<5;i++){

        if(player[i] / 13 != gara){
            return 0;
        }
    }

    int max = 0;

    for(int i=0;i<5;i++){

        int num = player[i] % 13;

        if(num > max){
            max = num;
        }
    }

    yakuhantei[0] = 6;
    yakuhantei[1] = max;

    return 1;
}


//ストレート
int straigh(int player[], int yakuhantei[]){

    int tmp[5];

    for(int i=0;i<5;i++){
        tmp[i] = player[i] % 13;
    }

    sort(tmp);

    for(int i=0;i<4;i++){

        if(tmp[i+1] != tmp[i] + 1){
            return 0;
        }
    }

    yakuhantei[0] = 5;
    yakuhantei[1] = tmp[4];

    return 1;
}


//スリーカード
int three(int player[], int yakuhantei[]){

    int cnt[13] = {0};

    for(int i=0;i<5;i++){
        cnt[player[i] % 13]++;
    }

    for(int i=12;i>=0;i--){

        if(cnt[i] == 3){

            yakuhantei[0] = 4;
            yakuhantei[1] = i;

            return 1;
        }
    }

    return 0;
}


//ツーペア
int two(int player[], int yakuhantei[]){

    int cnt[13] = {0};

    for(int i=0;i<5;i++){
        cnt[player[i] % 13]++;
    }

    int pair1 = -1;
    int pair2 = -1;
    int nokori = -1;
    int pair = 0;

    for(int i=12;i>=0;i--){

        if(cnt[i] == 2){

            if(pair1 == -1){
                pair1 = i;
            }
            else{
                pair2 = i;
            }

            pair++;
        }

        else if(cnt[i] == 1){
            nokori = i;
        }
    }

    if(pair == 2){

        yakuhantei[0] = 3;
        yakuhantei[1] = pair1;
        yakuhantei[2] = pair2;
        yakuhantei[3] = nokori;

        return 1;
    }

    return 0;
}


//ワンペア
int one(int player[], int yakuhantei[]){

    int cnt[13] = {0};

    for(int i=0;i<5;i++){
        cnt[player[i] % 13]++;
    }

    for(int i=12;i>=0;i--){

        if(cnt[i] == 2){

            yakuhantei[0] = 2;
            yakuhantei[1] = i;

            return 1;
        }
    }

    return 0;
}