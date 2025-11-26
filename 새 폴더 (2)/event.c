#define _CRT_SECURE_NO_WARNINGS
#include "gamefunc.h"
#include <stdio.h>

void printStatus(const State* st) {
    printf("\n[현재 상태]\n");
    printf("스트레스 : %d\n", st->stress);
    printf("실력     : %d\n", st->skill);
    printf("여친     : %s\n\n", st->gf ? "있음" : "없음");
}

int runEvent(const Event* ev, State* st) {
    int choice;

    printf("\n====================================\n");
    printf("%s\n", ev->question);
    printf("1) %s\n", ev->choice1);
    printf("2) %s\n", ev->choice2);
    printf("3) %s\n", ev->choice3);
    printf("====================================\n");

    printStatus(st);

    printf("선택>> ");
    scanf("%d", &choice);

    int* chg = NULL;

    if (choice == 1) chg = ev->stateChange1, st->badFlag += (ev->stateChange1[0] >= 2);
    else if (choice == 2) chg = ev->stateChange2;
    else if (choice == 3) chg = ev->stateChange3;
    else return -1;

    st->stress += chg[0];
    st->skill += chg[1];
    if (chg[2] == 1) st->gf = 1;

    // 말뚝 엔딩 플래그
    if (choice == 2 && ev->next2 == -1) st->proFlag++;

    // 다음 이벤트 반환
    if (choice == 1) return ev->next1;
    if (choice == 2) return ev->next2;
    return ev->next3;
}

void printEnding(const State* st) {
    printf("\n======= 엔딩 =======\n");

    if (st->proFlag >= 1) {
        printf("전문하사 엔딩\n");
        return;
    }

    if (st->badFlag >= 3) {
        printf("마음의 편지 엔딩\n");
        return;
    }

    printf("전역\n");
}   