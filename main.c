#include <stdio.h>
#include <stdlib.h>

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

    scanf_s("%d %d", &n, &m);

    eatDay = m / 2;             // 먹는날
    giveDay = eatDay + m % 2;   // 받는날

    int i;
    for (i = 0; i < giveDay; i ++) {
        scanf("%s", give[i]);
    }
    for (i = 0; i < eatDay; i ++) {
        scanf("%d", &eat[i]);
    }


    int day;
    for (day = 1; day <= m; day ++) {
        if (day % 2 == 1) {
            putCandy(give[(day - 1) / 2]);
        } else if (day % 2 == 0) {
            eatCandy(eat[(day - 1) / 2]);
        }
        showBox();
    }

    showBox();

    system("pause");

    return 0;
}

void putCandy(char* c) {
    int i;
    for (i = 0; *(c + i) != 0; i ++) {
        box[index] = *(c + i);
        index ++;

        if (index > n) {        // 여긴 안전성때문에 넣은곳
            index = n;          // 딱히 필요한 코드는 아니지만 혹시몰라 넣은코드.
        }                       //
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
    int i;
    for (i = index - 1; i >= 0; i --) {
        printf("%c", box[i]);
    }

    printf("\n");
}
