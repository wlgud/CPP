#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour, min, sec, msec;

public:
    // 생성자
    MyTime();
    MyTime(int h, int m, int s, int ms);

    // 출력 함수
    void print();
};

#endif