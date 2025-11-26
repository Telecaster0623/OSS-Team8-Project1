#ifndef GAMEFUNC_H
#define GAMEFUNC_H

typedef struct {
    const char* question;
    const char* choice1;
    const char* choice2;
    const char* choice3;
    int stateChange1[3];   // stress, skill, gf
    int stateChange2[3];
    int stateChange3[3];
    int next1;
    int next2;
    int next3;
} Event;

typedef struct {
    int stress;
    int skill;
    int gf;
    int badFlag;
    int proFlag;
} State;

// 함수 선언
int runEvent(const Event* ev, State* st);
void printStatus(const State* st);
void printEnding(const State* st);

#endif