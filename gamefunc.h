#ifndef GAMEFUNC_H
#define GAMEFUNC_H

typedef struct {
    const char *question;
    const char *choice1;
    const char *choice2;
    const char *choice3;
    int stateChange1[3];
    int stateChange2[3];
    int stateChange3[3];
    int next1;
    int next2;
    int next3;
} Event;

// 이벤트 목록
static const Event eventList[] = {
    {
        "당신은 컴퓨터공학과 입학을 앞두고 있습니다.\n어떻게 하시겠습니까?",
        "강의실에 간다",
        "카페에서 커피를 마신다",
        "집에 간다",
        {0, 0, 5},
        {4, -3, 45},
        {40, 53, 4},
        1, 2, -1   // 다음 이벤트 번호 예시
    }
};

#endif
