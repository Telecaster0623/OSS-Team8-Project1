#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void){
    char question[10000]="choihobin", choice_statement[5][10000] = {"A","B","C"}; int num = 3;
    printf("___________________________\n");
    printf("%s\n",question);
    printf("___________________________\n");
    for(int i = 0; i < num; i++){
        printf("%d. %s", i + 1 , choice_statement[i]);
    }
    printf("___________________________\n");

    return 0;
}