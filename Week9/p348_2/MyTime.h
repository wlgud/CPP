#ifndef MYTIME_H
#define MYTIME_H

class MyTime 
{
private:
    int hour, min, sec, msec;

public:
    // 생성자
    MyTime();
    MyTime(int h, int m, int s, int ms);
    MyTime(double duration);  // ★ 추가된 부분

    void print();
};

#endif