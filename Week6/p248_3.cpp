#include <iostream>

using namespace std;;

struct MyTime
{
    int hour;
    int min;
};

MyTime addTime(MyTime t1, MyTime t2)   //값 반환
{
    MyTime result;
    result.hour = t1.hour + t2.hour;
    result.min = t1.min + t2.min;

    if(result.min >= 60)
    {
        result.min -= 60;
        result.hour++;
    }

    return result;
}

void addTime(MyTime t1, MyTime t2, MyTime& t3)   //참조 전달
{
    t3.hour = t1.hour + t2.hour;
    t3.min = t1.min + t2.min;

    if(t3.min >= 60)
    {
        t3.min -= 60;
        t3.hour++;
    }
}

void addTime(MyTime t1, MyTime t2, MyTime* pt)   //포인터 전달
{
    pt -> hour = t1.hour + t2.hour;
    pt -> min = t1.min + t2.min;

    if(pt -> min >= 60)
    {
        pt -> min -= 60;
        pt -> hour++;
    }
}

int main()
{
    MyTime t1 = {1, 50};
    MyTime t2 = {2, 30};

    MyTime r1 = addTime(t1, t2);
    cout << "Return: " << r1.hour << "h " << r1.min << "m\n";

    MyTime r2;
    addTime(t1, t2, r2);
    cout << "Reference: " << r2.hour << "h " << r2.min << "m\n";

    MyTime r3;
    addTime(t1, t2, &r3);
    cout << "Pointer: " << r3.hour << "h " << r3.min << "m\n";

    return 0;
}