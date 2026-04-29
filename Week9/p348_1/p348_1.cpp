#include <iostream>
#include "MyTime.h"

using namespace std;

// 기본 생성자
MyTime::MyTime() : hour(0), min(0), sec(0), msec(0) {}

// 매개변수 생성자
MyTime::MyTime(int h, int m, int s, int ms)
    : hour(h), min(m), sec(s), msec(ms) {}

void MyTime::print() 
{
    cout << hour << "h "
         << min << "m "
         << sec << "s "
         << msec << "ms" << endl;
}

int main() 
{
    MyTime t1;
    MyTime t2(1, 2, 3, 400);

    t1.print();
    t2.print();

    return 0;
}