#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ending_1() {
    system("cls");
    printf("\n=====================================\n");
    printf("대기업 취업\n");
    printf("=====================================\n\n");
}
void ending_2() {
    system("cls");
    printf("\n=====================================\n");
    printf("대학원 진학\n");
    printf("=====================================\n\n");
}
void ending_3() {
    system("cls");
    printf("\n=====================================\n");
    printf("군대 말뚝\n");
    printf("=====================================\n\n");
}
void ending_4() {
    system("cls");
    printf("\n=====================================\n");
    printf("부자 여자친구 사귐\n");
    printf("=====================================\n\n");
}
void ending_5() {
    system("cls");
    printf("\n=====================================\n");
    printf("백수 인생\n");
    printf("=====================================\n\n");
}



int main() {
    int choice;

    if (scanf("%d", &choice) != 1) {
        return 1;
    }
    
    
    switch (choice) {
        case 1:
            ending_1();   
            break;

        case 2:
            ending_2();    
            break;

        case 3:
            ending_3();  
            break;

        case 4:
            ending_4();  
            break;

        case 5:
            ending_5();  
            break;

        default:
            break;
    }

    return 0;
}