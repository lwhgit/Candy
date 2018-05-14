#include <stdio.h>

#define MAX 100

int n, m, giveDay, eatDay, index;
int eat[MAX];
char box[MAX];
char give[MAX][MAX];

void putCandy(char *c);
void eatCandy(int count);
void showBox();

int main() {

    index = 0;                  // 현재 상자 위치

    scanf("%d %d", &n, &m);

    eatDay = m / 2;             // 먹는날 총 날짜에서 짝수 갯수 구하면 됨.
    giveDay = eatDay + m % 2;   // 받는날 총 날짜에서 홀수 갯수.

    int i;
    for (i = 0; i < giveDay; i ++) {    // 두번째 줄에서 입력받는 코드.
        scanf("%s", give[i]);
    }
    for (i = 0; i < eatDay; i ++) {     // 세번째 줄에서 입력받는 코드
        scanf("%d", &eat[i]);
    }


    int day;
    for (day = 1; day <= m; day ++) {
        if (day % 2 == 1) {
            putCandy(give[(day - 1) / 2]);  // 홀수 일에는 사탕을 받음
        } else if (day % 2 == 0) {
            eatCandy(eat[(day - 2) / 2]);   // 짝수 일에는 사탕을 먹음
        }
    }

    showBox();                              // 현재 상태 출력

    return 0;
}

void putCandy(char* c) {
    int i;
    for (i = 0; *(c + i) != 0; i ++) {
        if (index < n) {
            box[index] = *(c + i);
            index ++;
        }
    }
}

void eatCandy(int count) {
    int i;
    for (i = 0; i < count; i ++) {
        box[index] = 0;
        index --;

        if (index < 0) {        // 여긴 안전성때문에 넣은곳
            index = 0;          // 딱히 필요한 코드는 아니지만 혹시몰라 넣은코드.
        }                       //
    }
}

void showBox() {
    if (index == 0) {
        printf("0");
    } else {
        int i;
        for (i = index - 1; i >= 0; i --) {
            printf("%c", box[i]);
        }
    }
}
