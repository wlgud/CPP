#include <iostream>
#include "MyTime.h"

using namespace std;

// 기본 생성자
MyTime::MyTime() : hour(0), min(0), sec(0), msec(0) {}

// int 생성자
MyTime::MyTime(int h, int m, int s, int ms)
    : hour(h), min(m), sec(s), msec(ms) {}

// double 생성자
MyTime::MyTime(double duration) 
{
    hour = (int)(duration / 3600);
    duration -= hour * 3600;

    min = (int)(duration / 60);
    duration -= min * 60;

    sec = (int)duration;
    duration -= sec;

    msec = (int)(duration * 1000);
}

// 출력
void MyTime::print() 
{
    cout << hour << "h "
         << min << "m "
         << sec << "s "
         << msec << "ms" << endl;
}

int main() 
{
    // double 생성자 테스트
    MyTime t(3661.789);

    t.print();

    return 0;
}