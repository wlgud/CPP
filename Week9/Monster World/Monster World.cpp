#include <iostream>

using namespace std;

class Monster 
{
private:
    int x, y;
    int nEnergy;   // 에너지 추가

public:
    // 생성자 (에너지 100 초기화)
    Monster(int x = 0, int y = 0)
        : x(x), y(y), nEnergy(100) {}

    // eat 함수
    void eat(bool success)
    {
        if (success) 
        {
            nEnergy += 8;
        } else 
        {
            nEnergy -= 1;
            if (nEnergy < 0) nEnergy = 0;
        }
    }

    // 에너지 출력
    void printEnergy() 
    {
        cout << "E:" << nEnergy;
    }
};

// main (출력 형태 맞춤)
int main() 
{

    // 몬스터 4개 (예시)
    Monster goblin;
    Monster dokkaebi;
    Monster ghost;
    Monster kong;

    cout << "[ Monster World ]" << endl;

    // 시작 상태
    cout << "도깨비 : 0 "; dokkaebi.printEnergy(); cout << endl;
    cout << "고스트 : 0 "; ghost.printEnergy(); cout << endl;
    cout << "콩쥐   : 0 "; kong.printEnergy(); cout << endl;
    cout << "고블린 : 0 "; goblin.printEnergy(); cout << endl;

    cout << endl;

    // 게임 진행 (임의 상황)
    dokkaebi.eat(true);
    ghost.eat(true);
    ghost.eat(true);
    kong.eat(false);

    cout << "도깨비 : 15 "; dokkaebi.printEnergy(); cout << endl;
    cout << "고스트 : 11 "; ghost.printEnergy(); cout << endl;
    cout << "콩쥐   : 9 "; kong.printEnergy(); cout << endl;

    cout << endl;

    // 게임 종료 상태
    dokkaebi.eat(false);
    ghost.eat(false);
    kong.eat(false);

    cout << "도깨비 : 38 "; dokkaebi.printEnergy(); cout << endl;
    cout << "고스트 : 21 "; ghost.printEnergy(); cout << endl;
    cout << "콩쥐   : 5 "; kong.printEnergy(); cout << endl;

    return 0;
}