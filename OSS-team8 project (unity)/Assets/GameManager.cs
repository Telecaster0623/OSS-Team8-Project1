using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    // --- 1. UI 연결 변수 (Inspector에서 다시 연결해야 함!) ---
    [Header("UI Elements")]
    public Text questionText;
    public Text statsText;
    public Button[] choiceButtons;
    public Text[] buttonTexts;

    // --- 2. 플레이어 스탯 ---
    int gpa = 30;       // 학점
    int devSkill = 10;  // 개발력
    int stamina = 80;   // 체력
    int social = 30;    // 인싸력
    int stress = 0;     // 스트레스
    int money = 50;     // 돈
    bool girlfriend = false; // 부자 여친 플래그

    // --- 3. 게임 상태 관리 ---
    int currentStage = 0; // 0:프롤로그, 1:1학년, 2:2학년 ...

    void Start()
    {
        Stats();
        Chapter(0); // 게임 시작 시 프롤로그 실행
    }

    // 스탯 화면 갱신
    void Stats()
    {
        statsText.text = $"학점: {gpa} | 코딩력: {devSkill} | 체력: {stamina}\n" +
                         $"인맥: {social} | 스트레스: {stress} | 자금: {money}만원";

        if (girlfriend) statsText.text += "\n★ [부자 여친] 보유 중";
    }

    // --- 4. 스테이지별 화면 보여주기 ---
    void Chapter(int stage)
    {
        currentStage = stage;

        // 모든 버튼 활성화 (일단 켜두고 필요 없으면 끔)
        foreach (var btn in choiceButtons) btn.gameObject.SetActive(true);

        switch (stage)
        {
            case 0: // 프롤로그
                questionText.text = "[프롤로그] 수능 시험장이다.\n1교시 국어 영역 시작 직전, 긴장감이 감돈다.";
                SetButtonText(0, "시험에 집중한다. (게임 시작)");
                SetButtonText(1, "도망친다. (게임 오버)");
                choiceButtons[2].gameObject.SetActive(false); // 버튼 3은 필요 없음
                break;

            case 1: // 1학년
                questionText.text = "[1학년] 컴공과에 입학했다.\n동아리를 정해야 한다.";
                SetButtonText(0, "개발 동아리 (실력↑ 인맥↓)");
                SetButtonText(1, "술자리 동아리 (인맥↑ 학점↓)");
                SetButtonText(2, "도서관 유령 (학점↑ 인맥↓)");
                break;

            case 2: // 2학년
                questionText.text = "[2학년] 군대 영장이 나왔다.\n국방의 의무를 수행해야 한다.";
                SetButtonText(0, "현역 입대 후 복학");
                SetButtonText(1, "전문하사 지원 (말뚝)");
                choiceButtons[2].gameObject.SetActive(false);
                break;

            case 3: // 3학년
                questionText.text = "[3학년] 축제 기간이다.\n친구가 '엄청난 부자집 딸'과 미팅을 잡아왔다.";
                SetButtonText(0, "미팅 나간다 (인싸력 필요)");
                SetButtonText(1, "팀 프로젝트나 한다");
                SetButtonText(2, "집에서 잔다");
                break;

            case 4: // 4학년
                questionText.text = "[4학년] 졸업 시즌이다.\n당신의 미래를 선택하라.";
                SetButtonText(0, "대기업 공채 지원 (스펙 필요)");
                SetButtonText(1, "대학원 진학 (노예 계약)");
                string option3 = girlfriend ? "여자친구와 결혼 (취집)" : "창업 도전 (자금 필요)";
                SetButtonText(2, option3);
                break;

            case 99: // 엔딩 상태
                foreach (var btn in choiceButtons) btn.gameObject.SetActive(false);
                break;
        }
    }

    // 버튼 텍스트 설정 헬퍼 함수
    void SetButtonText(int index, string text)
    {
        buttonTexts[index].text = text;
    }

    // --- 5. 버튼 클릭 처리 ---
    public void OnOptionSelected(int buttonIndex)
    {
        switch (currentStage)
        {
            case 0: // 프롤로그 결과
                if (buttonIndex == 0)
                { // 시험 집중
                    money += 100; // 입학 축하금
                    Chapter(1); // 1학년으로
                }
                else
                { // 도망
                    ShowEnding("수능 포기 엔딩", "시험장을 뛰쳐나왔다... 재수학원으로 향한다.");
                }
                break;

            case 1: // 1학년 결과
                if (buttonIndex == 0) { devSkill += 30; social -= 10; }
                else if (buttonIndex == 1) { social += 30; gpa -= 10; money -= 30; }
                else { gpa += 30; social -= 20; }
                Stats();
                Chapter(2); // 2학년으로
                break;

            case 2: // 2학년 결과
                if (buttonIndex == 0)
                { // 현역
                    stamina += 30; devSkill -= 10; gpa -= 10; // 복학 패널티
                    Stats();
                    Chapter(3); // 3학년으로
                }
                else
                { // 말뚝
                    ShowEnding("직업 군인 엔딩", "행보관님의 사랑을 받으며 중사 진급을 앞두고 있다.");
                }
                break;

            case 3: // 3학년 결과
                if (buttonIndex == 0)
                { // 미팅
                    if (social >= 40)
                    {
                        girlfriend = true; money += 100;
                        statsText.text += "\n[이벤트] 부자 여친 획득!";
                    }
                    else
                    {
                        stress += 20; // 실패
                    }
                }
                else if (buttonIndex == 1) { devSkill += 20; stress += 10; }
                else { stamina += 10; }
                Stats();
                Chapter(4); // 4학년으로
                break;

            case 4: // 4학년 결과 (최종 엔딩 분기)
                if (buttonIndex == 0)
                { // 대기업
                    if (gpa >= 50 && devSkill >= 50) ShowEnding("대기업 합격 엔딩", "삼성/네이버 동시 합격! 판교의 등불이 되었다.");
                    else ShowEnding("백수 엔딩", "서류 광탈... 자취방에서 롤만 하고 있다.");
                }
                else if (buttonIndex == 1)
                { // 대학원
                    ShowEnding("대학원생 엔딩", "교수님: '자네는 대학원생이 딱이야.' 연구실에 갇혔다.");
                }
                else
                { // 결혼 or 창업
                    if (girlfriend) ShowEnding("셔터맨 엔딩", "부자 여친과 결혼하여 카페 사장님이 되었다.");
                    else
                    {
                        if (money >= 100 && devSkill >= 80) ShowEnding("창업 대박 엔딩", "제2의 스티브 잡스가 되었다!");
                        else ShowEnding("창업 폭망 엔딩", "사업이 망했다. 빚쟁이를 피해 도망다닌다.");
                    }
                }
                break;
        }
    }

    void ShowEnding(string title, string desc)
    {
        currentStage = 99;
        questionText.text = $"[ENDING: {title}]\n\n{desc}";
        Stats();
        Chapter(99);
    }
}