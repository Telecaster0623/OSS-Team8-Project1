#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int question(const char* questionText, int choiceCount, char choice_statement[5][10000]) {
    int choice = -1;

    system("cls");
    printf("___________________________\n");
    printf("%s\n", questionText);
    printf("___________________________\n");

    for (int i = 0; i < choiceCount; i++) {
        printf("%d. %s\n", i + 1, choice_statement[i]);
    }

    printf("___________________________\n");

    while (1) {
        printf("---> ");
        if (scanf_s("%d", &choice) != 1) {
            // 숫자가 아닐 때 처리
            printf("숫자를 입력하세요.\n");
            // 버퍼 비우기
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (choice >= 1 && choice <= choiceCount) {
            break;
        } else {
            printf("1~%d 사이의 번호를 입력하세요.\n", choiceCount);
        }
    }

    return choice;
}