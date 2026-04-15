#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class MyTime
{
private:
    int hour;
    int min;
    int sec;
    int msec;

public:
    // 초 → 시간 변환 (inline)
    void convert(double duration)
    {
        int total_msec = (int)(duration * 1000);

        hour = total_msec / (1000 * 60 * 60);
        total_msec %= (1000 * 60 * 60);

        min = total_msec / (1000 * 60);
        total_msec %= (1000 * 60);

        sec = total_msec / 1000;
        msec = total_msec % 1000;
    }

    // 출력 (inline)
    void print()
    {
        cout << setfill('0')
             << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << ":"
             << setw(3) << msec << endl;
    }

    // 시간 더하기 (inline)
    MyTime add(MyTime t)
    {
        MyTime result;

        result.msec = msec + t.msec;
        result.sec = sec + t.sec + result.msec / 1000;
        result.msec %= 1000;

        result.min = min + t.min + result.sec / 60;
        result.sec %= 60;

        result.hour = hour + t.hour + result.min / 60;
        result.min %= 60;

        return result;
    }

    // 초기화 (inline)
    void reset()
    {
        hour = min = sec = msec = 0;
    }

    // 입력 (inline)
    void read()
    {
        cout << "시 입력: ";
        cin >> hour;
        cout << "분 입력: ";
        cin >> min;
        cout << "초 입력: ";
        cin >> sec;
        cout << "밀리초 입력: ";
        cin >> msec;
    }
};

#endif