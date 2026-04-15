#include "MyTime.h"

int main()
{
    MyTime t1, t2, t3, t4;

    // 입력
    cout << "첫 번째 시간 입력\n";
    t1.read();

    cout << "\n두 번째 시간 입력\n";
    t2.read();

    // 출력
    cout << "\nt1: ";
    t1.print();

    cout << "t2: ";
    t2.print();

    // 더하기
    t3 = t1.add(t2);
    cout << "\n합(t1 + t2): ";
    t3.print();

    // 초기화
    t3.reset();
    cout << "초기화 후 t3: ";
    t3.print();

    // convert 테스트
    t4.convert(3661.567);
    cout << "\nconvert 결과 (3661.567초): ";
    t4.print();

    return 0;
}