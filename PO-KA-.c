#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand((unsigned)time(NULL));
    int yamafuda[52];
    int player1[5];
    int player2[5];
    int toranpu,gara1,gara2,suuji1,suuji2,sentaku,rank1,rank2;
    char *mark[] = {"♥","♦","♣","♠"};
    for(int i=0;i<52;i++){
            yamafuda[i] = i + 1;
        }
        for(int i=0;i<5;i++){
        toranpu = rand() % 52;
        if(yamafuda[toranpu] == 100)
    {
        while(yamafuda[toranpu] == 100){
             toranpu = rand() % 52;
        }
         
    }
        player1[i] = yamafuda[toranpu];
        yamafuda[toranpu] = 100;
    }
    for(int i=0;i<5;i++){
        toranpu = rand() % 52;
        if(yamafuda[toranpu] == 100)
    {
        while(yamafuda[toranpu] == 100){
             toranpu = rand() % 52;
        }
         
    }
        player2[i] = yamafuda[toranpu];
        yamafuda[toranpu] = 100;
    }
    printf("player1の手札 ");
    for(int i=0;i<5;i++){
        gara1 = player1[i] / 13;
        suuji1 = player1[i] % 13 + 2;
            if(suuji1 == 14){
                suuji1=1;
            }
            printf("%s%d ",mark[gara1],suuji1);
    }

    printf("\n");
    printf("カードを入れ替えますか？ はい（１）/ いいえ （２）");
    scanf("%d",&sentaku);
    if(sentaku == 1){
    int n, k;

    printf("何枚交換しますか？(0〜5) ");
    scanf("%d",&k);

    for(int i=0;i<k;i++){
        printf("何枚目のカードを交換しますか？(1〜5) ");
        scanf("%d",&n);
        int t = rand() % 52;
        while(yamafuda[t] == 100){
            t = rand() % 52;
        }

        player1[n-1] = yamafuda[t];
        yamafuda[t] = 100;
    }
    }
    printf("player2の手札 ");
    for(int i=0;i<5;i++){
        gara2 = player2[i] / 13;
        suuji2 = player2[i] % 13 + 2;
        if(suuji2 == 14){
                suuji2=1;
            }
        printf("%s%d ",mark[gara2],suuji2);
    }
    printf("\n");
    printf("カードを入れ替えますか？ はい（１）/ いいえ （２）");
    scanf("%d",&sentaku);
    if(sentaku == 1){
    int n, k;

    printf("何枚交換しますか？(0〜5) ");
    scanf("%d",&k);

    for(int i=0;i<k;i++){
        printf("何枚目のカードを交換しますか？(1〜5) ");
        scanf("%d",&n);
        int t = rand() % 52;
        while(yamafuda[t] == 100){
            t = rand() % 52;
        }

        player2[n-1] = yamafuda[t];
        yamafuda[t] = 100;
    }
    }
    printf("player1の手札 ");
    for(int i=0;i<5;i++){
        gara1 = player1[i] / 13;
        suuji1 = player1[i] % 13 + 2;
            if(suuji1 == 14){
                suuji1=1;
            }
            printf("%s%d ",mark[gara1],suuji1);
    }
    printf("\n");
    printf("player2の手札 ");
    for(int i=0;i<5;i++){
        gara2 = player2[i] / 13;
        suuji2 = player2[i] % 13 + 2;
        if(suuji2 == 14){
                suuji2=1;
            }
        printf("%s%d ",mark[gara2],suuji2);
    }
    printf("\n");
    // ===== player1 役判定 =====
int count1[14] = {0};
int pair1=0, three1=0, four1=0;

// 数字カウント
for(int i=0;i<5;i++){
    int s = player1[i] % 13 + 1;
    count1[s]++;
}

// ペア系
for(int i=1;i<=13;i++){
    if(count1[i] == 2) pair1++;
    if(count1[i] == 3) three1++;
    if(count1[i] == 4) four1++;
}

// フラッシュ
int flush1 = 1;
int suit1 = player1[0] / 13;
for(int i=1;i<5;i++){
    if(player1[i] / 13 != suit1){
        flush1 = 0;
    }
}

// コピー
int tmp1[5];
for(int i=0;i<5;i++){
    tmp1[i] = player1[i] %13 +2;
}
//並び替え
for(int i=0;i<4;i++){
    for(int j=i+1;j<5;j++){
        if(tmp1[i] > tmp1[j]){
            int t = tmp1[i];
            tmp1[i] = tmp1[j];
            tmp1[j] = t;
        }
    }
}

// ストレート
int straight1 = 1;
if(tmp1[4] == 14 && tmp1[0] == 2){
    tmp1[4] = 1;
    for(int i=0;i<4;i++){
    for(int j=i+1;j<5;j++){
        if(tmp1[i] > tmp1[j]){
            int t = tmp1[i];
            tmp1[i] = tmp1[j];
            tmp1[j] = t;
        }
    }
}
}
for(int i=0;i<4;i++){
    if((tmp1[i+1]) != (tmp1[i])+1){
        straight1 = 0;
    }
}
printf("player1の役：");

if(straight1 && flush1){
    printf("ストレートフラッシュ\n");
    rank1 = 9 ;
}
else if(four1 == 1){
    printf("フォーカード\n");
    rank1 = 8;
}
else if(three1 && pair1){
    printf("フルハウス\n");
    rank1 = 7;
}
else if(flush1 == 1){
    printf("フラッシュ\n");
    rank1 = 6;
}
else if(straight1 == 1){
    printf("ストレート\n");
    rank1 = 5;
}
else if(three1 == 1){
    printf("スリーカード\n");
    rank1 = 4;
}
else if(pair1 == 2){
    printf("ツーペア\n");
    rank1 = 3;
}
else if(pair1 == 1){
    printf("ワンペア\n");
    rank1 = 2;
}
else{
    printf("役なし\n");
    rank1 = 1;
}
// player2 役判定 
int count2[14] = {0};
int pair2=0, three2=0, four2=0;

// 数字カウント
for(int i=0;i<5;i++){
    int s = player2[i] % 13 + 2;
    count2[s]++;
}

// ペア系
for(int i=1;i<=13;i++){
    if(count2[i] == 2) pair2++;
    if(count2[i] == 3) three2++;
    if(count2[i] == 4) four2++;
}

// フラッシュ
int flush2 = 1;
int suit2 = player2[0] / 13;
for(int i=1;i<5;i++){
    if(player2[i] / 13 != suit2){
        flush2 = 0;
    }
}

// ===== ストレート =====

// コピー
int tmp2[5];
for(int i=0;i<5;i++){
    tmp2[i] = player2[i] % 13 + 2;
}
//並び替え
for(int i=0;i<4;i++){
    for(int j=i+1;j<5;j++){
        if(tmp2[i] > tmp2[j]){
            int t = tmp2[i];
            tmp2[i] = tmp2[j];
            tmp2[j] = t;
        }
    }
}

// A2345での判定
if(tmp2[4] == 14 && tmp2[0] == 2){
    tmp2[4] = 1;

    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(tmp2[i] > tmp2[j]){
                int t = tmp2[i];
                tmp2[i] = tmp2[j];
                tmp2[j] = t;
            }
        }
    }
}

// ストレート判定
int straight2 = 1;
for(int i=0;i<4;i++){
    if(tmp2[i+1] != tmp2[i] + 1){
        straight2 = 0;
        break;
    }
}

//結果
printf("player2の役：");

if(straight2 && flush2){
    printf("ストレートフラッシュ\n");
    rank2 = 9;
}
else if(four2 == 1){
    printf("フォーカード\n");
    rank2 = 8;
}
else if(three2 && pair2){
    printf("フルハウス\n");
    rank2 = 7;
}
else if(flush2){
    printf("フラッシュ\n");
    rank2 = 6;
}
else if(straight2){
    printf("ストレート\n");
    rank2 = 5;
}
else if(three2){
    printf("スリーカード\n");
    rank2 = 4;
}
else if(pair2 == 2){
    printf("ツーペア\n");
    rank2 = 3;
}
else if(pair2 == 1){
    printf("ワンペア\n");
    rank2 = 2;
}
else{
    printf("役なし\n");
    rank2 = 1;
}
// ===== 勝敗判定 =====
if(rank1 > rank2){
    printf("player1の勝ち\n");
}
else if(rank1 < rank2){
    printf("player2の勝ち\n");
}
else{
    // ===== 同じ役の場合 =====

    // フォーカード
    if(rank1 == 8){
        int f1=0,f2=0;
        for(int i=1;i<=13;i++){
            if(count1[i]==4) f1=i;
            if(count2[i]==4) f2=i;
        }
        if(f1 > f2) printf("player1の勝ち\n");
        else if(f1 < f2) printf("player2の勝ち\n");
        else printf("引き分け\n");
    }

    // フルハウス
    else if(rank1 == 7){
        int t1=0,t2=0;
        for(int i=1;i<=13;i++){
            if(count1[i]==3) t1=i;
            if(count2[i]==3) t2=i;
        }
        if(t1 > t2) printf("player1の勝ち\n");
        else if(t1 < t2) printf("player2の勝ち\n");
        else printf("引き分け\n");
    }

    // スリーカード
    else if(rank1 == 4){
        int t1=0,t2=0;
        for(int i=1;i<=13;i++){
            if(count1[i]==3) t1=i;
            if(count2[i]==3) t2=i;
        }
        if(t1 > t2) printf("player1の勝ち\n");
        else if(t1 < t2) printf("player2の勝ち\n");
        else printf("引き分け\n");
    }

    // ツーペア
    else if(rank1 == 3){
        int high1=0,low1=0;
        int high2=0,low2=0;

        for(int i=1;i<=13;i++){
            if(count1[i]==2){
                if(low1==0) low1=i;
                else high1=i;
            }
            if(count2[i]==2){
                if(low2==0) low2=i;
                else high2=i;
            }
        }

        if(high1 < low1){ int t=high1; high1=low1; low1=t; }
        if(high2 < low2){ int t=high2; high2=low2; low2=t; }

        if(high1 > high2) printf("player1の勝ち\n");
        else if(high1 < high2) printf("player2の勝ち\n");
        else if(low1 > low2) printf("player1の勝ち\n");
        else if(low1 < low2) printf("player2の勝ち\n");
        else printf("引き分け\n");
    }

    // ワンペア
    else if(rank1 == 2){
        int p1=0,p2=0;

        for(int i=1;i<=13;i++){
            if(count1[i]==2) p1=i;
            if(count2[i]==2) p2=i;
        }

        if(p1 > p2) printf("player1の勝ち\n");
        else if(p1 < p2) printf("player2の勝ち\n");
        else printf("引き分け\n");
    }


    // それ以外
else{
    if(tmp1[4] == 1){
    tmp1[4] = 14;
    for(int i=0;i<4;i++){
    for(int j=i+1;j<5;j++){
        if(tmp1[i] > tmp1[j]){
            int t = tmp1[i];
            tmp1[i] = tmp1[j];
            tmp1[j] = t;
        }
    }
}
}
if(tmp2[4] == 1){
    tmp2[4] = 14;
    for(int i=0;i<4;i++){
    for(int j=i+1;j<5;j++){
        if(tmp2[i] > tmp2[j]){
            int t = tmp2[i];
            tmp2[i] = tmp2[j];
            tmp2[j] = t;
        }
    }
}
}
    for(int i=4;i>=0;i--){
        if(tmp1[i] > tmp2[i]){
            printf("player1の勝ち\n");
            break;
        }
        else if(tmp1[i] < tmp2[i]){
            printf("player2の勝ち\n");
            break;
        }
        if(i==0){
            printf("引き分け\n");
        }
    }
}
}
    return 0;
}
