#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void question(char question[10000], int num, char choice_statement[5][10000]){
    system("cls");
    printf("___________________________\n");
    printf("%s\n",question);
    printf("___________________________\n");
    for(int i = 0; i < num; i++){
        printf("%d. %s\n", i + 1 , choice_statement[i]);
    }
    printf("___________________________\n");
    printf("--->\n");
}