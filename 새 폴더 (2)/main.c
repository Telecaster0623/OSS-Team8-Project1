#include <stdio.h>
#include "gamefunc.h"
#include "militaryEvent.h"

int main() {
    State st = { 0, 0, 0, 0, 0 };  // stress, skill, gf, badFlag, proFlag
    int current = 100;  // 군대 스토리 시작

    while (current >= 0) {
        current = runEvent(&eventList[current], &st);
    }

    printEnding(&st);

    return 0;
}