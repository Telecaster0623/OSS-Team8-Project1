#include "gamefunc.h"
#include <stdio.h>

typedef struct {
    int a;
    int b;
    int c;
} State;

int runEvent(const Event *ev, State *st) {
    int choice;

    printf("\n====================================\n");
    printf("%s\n", ev->question);
    printf("1) %s\n", ev->choice1);
    printf("2) %s\n", ev->choice2);
    printf("3) %s\n", ev->choice3);
    printf("====================================\n");

    printf("선택>> ");
    scanf("%d", &choice);

    if (choice == 1) {
        st->a += ev->stateChange1[0];
        st->b += ev->stateChange1[1];
        st->c += ev->stateChange1[2];
        return ev->next1;
    }
    else if (choice == 2) {
        st->a += ev->stateChange2[0];
        st->b += ev->stateChange2[1];
        st->c += ev->stateChange2[2];
        return ev->next2;
    }
    else if (choice == 3) {
        st->a += ev->stateChange3[0];
        st->b += ev->stateChange3[1];
        st->c += ev->stateChange3[2];
        return ev->next3;
    }
    else {
        printf("잘못된 입력입니다.\n");
        return -1;
    }
}

#include <stdio.h>
#include "gamefunc.h"

typedef struct {
    int a;
    int b;
    int c;
} State;

int runEvent(const Event *ev, State *st);

int main() {
    int current = 0;
    State st = {0, 0, 0};

    while (current >= 0) {
        current = runEvent(&eventList[current], &st);
    }

    printf("\n게임 종료!\n");
    printf("최종 상태: a=%d, b=%d, c=%d\n", st.a, st.b, st.c);

    return 0;
}
