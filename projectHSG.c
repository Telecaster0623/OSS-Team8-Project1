#include <stdio.h>
#include <stdlib.h>

struct PlayerStats{
    int study; int stress; int money;
};

void printStats(struct PlayerStats* p) {
    printf("\n--- [현재 상태] ---\n");
    printf("성적: %d | 스트레스: %d | 돈: %d\n",
        p->study, p->stress, p->money);
    printf("--------------------\n");
}

int main()
{
    struct PlayerStats player1;
    player1.study = 0;
    player1.stress = 0;
    player1.money = 0;

    int girlfriend = 0;
    int GameOver = 0;

}