#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shuffle(int yamafuda[]);
void deal(int yamafuda[], int player[], int *top);
void printHand(int player[], char *mark[], char *kazu[]);
void changeHand(int yamafuda[], int player[], int *top);
void clearWait();
void clear();
void sort(int tmp[]);
int royalFlush(int player[], int yakuhantei[]);
int straightFlush(int player[], int yakuhantei[]);
int four(int player[], int yakuhantei[]);
int fullHouse(int player[], int yakuhantei[]);
int flush(int player[], int yakuhantei[]);
int straight(int player[], int yakuhantei[]);
int three(int player[], int yakuhantei[]);
int two(int player[], int yakuhantei[]);
int one(int player[], int yakuhantei[]);
int highCard(int player[], int yakuhantei[]);
void judge(int player[], int yakuhantei[]);
void syouhai(int yakuhantei1[], int yakuhantei2[]);
int main(void){
    srand((unsigned)time(NULL));

    int top = 0;
    char ana;
    int yamafuda[52];
    int player1[5];
    int player2[5];
    // [0]役
    // [1]強い数字
    // [2]~[5]順番に強い順
    int yakuhantei1[6] = {0};
    int yakuhantei2[6] = {0};
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
    printf("player1はEnterを押してください\n");
    clearWait();
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
    printHand(player1, mark, kazu);
    judge(player1, yakuhantei1);   
    printHand(player2, mark, kazu);
    judge(player2, yakuhantei2);
    syouhai(yakuhantei1, yakuhantei2);

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
    for(int i = 0;i<5;i++){
        player[i] = yamafuda[*top];
        (*top)++;
    }
}

//手札交換
void changeHand(int yamafuda[], int player[], int *top){
    int sentaku;
    printf("カードを入れ替えますか？ はい（１）/ いいえ （２）");
    scanf("%d",&sentaku);
    if(sentaku == 1){
        int n, k;

        while (1) {
            printf("何枚交換しますか？(0〜5) ");
//scanf が数字を読めなかった場合
            if (scanf("%d", &n) != 1) {
                printf("数字を入力してください\n");
                clear();
                continue;
            }
 //範囲外
            if (n < 0 || n > 5) {
                printf("不正な入力です\n");
                printf("0〜5の数字を入力してください\n");
                continue;
            }

            break; 
        }

        int used[5] = {0};

        for(int i=0;i<n;i++){
            printf("何枚目のカードを交換しますか？(1〜5) ");
            scanf("%d",&k);

// 入力チェック
            if(k < 1 || k > 5){
                printf("不正な入力です\n");
                printf("1〜5の数字を入力してください\n");
                i--;        // 交換回数を消費しない
                continue;
            }

// 交換済みチェック
            if(used[k-1] == 1){
                printf("そのカードは交換済みです\n");
                i--;        // 交換回数を消費しない
                continue;
            }

// 交換済みにする
            used[k-1] = 1;

// 山札からカードを引く
            player[k-1] = yamafuda[*top];
            (*top)++;
        }
    }
}

//最初の表示時クリア
void clearWait(){
    getchar();  // Enter を1回だけ待つ
    system("clear");
}

//表示クリア
void clear(){
    while(getchar() != '\n'); 
    getchar();                
    system("clear");
}

//訳判定
void judge(int player[], int yakuhantei[]){

    if(royalFlush(player, yakuhantei)){
        printf("ロイヤルフラッシュ\n");
    }

    else if(straightFlush(player, yakuhantei)){
        printf("ストレートフラッシュ\n");
    }

    else if(four(player, yakuhantei)){
        printf("フォーカード\n");
    }

    else if(fullHouse(player, yakuhantei)){
        printf("フルハウス\n");
    }

    else if(flush(player, yakuhantei)){
        printf("フラッシュ\n");
    }

    else if(straight(player, yakuhantei)){
        printf("ストレート\n");
    }

    else if(three(player, yakuhantei)){
        printf("スリーカード\n");
    }

    else if(two(player, yakuhantei)){
        printf("ツーペア\n");
    }

    else if(one(player, yakuhantei)){
        printf("ワンペア\n");
    }

    else{
        printf("ハイカード\n");
        highCard(player, yakuhantei);
    }
}

//並び替え
void sort(int tmp[]){

    for(int i = 0;i<4;i++){

        for(int j = i+1;j<5;j++){

            if(tmp[i] > tmp[j]){

                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }
}

//ロイヤルフラッシュ
int royalFlush(int player[], int yakuhantei[]){

    int tmp[5];
    int gara = player[0] / 13;

    //フラッシュ部分
    for(int i = 0;i<5;i++){

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
int straightFlush(int player[], int yakuhantei[]){
    int tmp[5];
    int gara = player[0] / 13;

    //フラッシュ部分
    for(int i = 0;i<5;i++){

        tmp[i] = player[i] % 13;

        if(player[i] / 13 != gara){
            return 0;
        }
    }
    
   sort(tmp);

   if(tmp[0]==0 && tmp[1]==1 && tmp[2]==2
        && tmp[3]==3 && tmp[4]==12){
            yakuhantei[0] = 9;
            yakuhantei[1] = 5;

            return 1;
        }
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

    //かぶりカウント
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

    //スリーカード
    int san = -1;

    //ペアー
    int pair = -1;

    for(int i=0;i<5;i++){
        cnt[player[i] % 13]++;
    }

    for(int i=12;i>=0;i--){

        if(cnt[i] == 3){
            san = i;
        }
        else if(cnt[i] == 2){
            pair = i;
        }
    }

    if(san != -1 && pair != -1){

        yakuhantei[0] = 7;
        yakuhantei[1] = san;
        yakuhantei[2] = pair;

        return 1;
    }

    return 0;
}

//フラッシュ
int flush(int player[], int yakuhantei[]){
    int tmp[5];
    int gara = player[0] / 13;

    for(int i = 0;i<5;i++){

        tmp[i] = player[i] % 13 + 2;

        if(player[i] / 13 != gara){
            return 0;
        }
    }

    sort(tmp);
    //強い順に入れる
    yakuhantei[0] = 6;
    for(int i = 1;i<6;i++){
        yakuhantei[i] = tmp[6-i];
    }

    return 1;
}

//ストレート
int straight(int player[], int yakuhantei[]){
    int tmp[5];

    for(int i=0;i<5;i++){
        tmp[i] = player[i] % 13;
    }

    sort(tmp);
    
    if(tmp[0]==0 && tmp[1]==1 && tmp[2]==2
        && tmp[3]==3 && tmp[4]==12){
            yakuhantei[0] = 5;
            yakuhantei[1] = 5;

            return 1;
        }        
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

//ペア
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

//ハイカード
int highCard(int player[], int yakuhantei[]){
    int tmp[5];

    for(int i=0;i<5;i++){
        tmp[i] = player[i] % 13;
    }

    sort(tmp);

    yakuhantei[0] = 1;
    yakuhantei[1] = tmp[4];

    return 1;
}

//勝ち負けんぬ
void syouhai(int yakuhantei1[], int yakuhantei2[]){
    if(yakuhantei1[0] > yakuhantei2[0]) printf("player1の勝ち\n");
    else if(yakuhantei1[0] < yakuhantei2[0]) printf("player2の勝ち\n");
    else{
        for(int i = 1;i<7;i++){
            if(yakuhantei1[i] > yakuhantei2[i]){
                printf("player1の勝ち\n");
                return;
            }
            else if(yakuhantei1[i] < yakuhantei2[i]){
                printf("player2の勝ち\n");
                return;
            }
        }
        printf("引き分け\n");
    }
}