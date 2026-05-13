#include <iostream>
#include <cstring>

using namespace std;

class Sample
{
private:
    char* name;

public:
    // 정적 변수
    static int count;

    // 기본 생성자
    Sample() 
    {
        name = nullptr;
        count++;
    }

    // 생성자
    Sample(const char* name) 
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        count++;
    }

    // 복사 생성자
    Sample(const Sample& s) 
    {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);

        count++;
    }

    // 소멸자
    ~Sample() 
    {
        delete[] name;
        count--;
    }

    // 객체 개수 출력 함수
    static void printCount() 
    {
        cout << "객체 수 : " << count << endl;
    }

    void print() 
    {
        cout << name << endl;
    }
};

// 정적 변수 초기화
int Sample::count = 0;

int main() 
{
    Sample a("sample");
    Sample b(a);

    a.print();
    b.print();

    Sample::printCount();

    return 0;
}