#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGuguOnce()
{
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;
    int answer;

    cout << a << " x " << b << " = ";
    cin >> answer;

    if(answer == a * b)
        cout << "정답!\n";
    else
        cout << "오답! 정답은 " << a * b << endl;
}

void playMulOnce()
{
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;
    int answer;

    cout << a << " x " << b << " = ";
    cin >> answer;

    if(answer == a * b)
        cout << "정답\n";
    else
        cout << "오답 (정답: " << a * b << ")\n";
}

void playAddOnce()
{
    int a = rand() % 900 + 100;
    int b = rand() % 900 + 100;
    int answer;

    cout << a << " + " << b << " = ";
    cin >> answer;

    if(answer == a + b)
        cout << "정답\n";
    else
        cout << "오답 (정답: " << a + b << ")\n";
}

int main()
{
    srand(time(0));

    int menu;

    while (true)
    {
        cout << "\n[ 메뉴 ]\n";
        cout << "1. 구구단\n";
        cout << "2. 두 자리 곱셈\n";
        cout << "3. 여러 자리 덧셈\n";
        cout << "4. 종료\n";
        cout << "선택: ";
        cin >> menu;

        if(menu == 0)
            break;

        switch(menu)
        {
            case 1: playGuguOnce();
            break;
            case 2: playMulOnce();
            break;
            case 3: playAddOnce();
            break;
            default: cout << "잘못된 입력\n";
        }
    }

    return 0;
}