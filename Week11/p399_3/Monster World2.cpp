#include <iostream>
#include <string>

using namespace std;

class Monster 
{
private:
    string name;
    int energy;

public:
    // 정적 변수
    static int count;

    Monster(string n = "몬스터", int e = 100) 
    {
        name = n;
        energy = e;
        count++;
    }

    ~Monster() 
    {
        count--;
    }

    void eat(int food) 
    {
        energy += food;
    }

    void damage(int d) 
    {
        energy -= d;
    }

    int getEnergy() 
    {
        return energy;
    }

    void print() 
    {
        cout << name << " 에너지 : "
             << energy << endl;
    }

    static void printCount() 
    {
        cout << "현재 몬스터 수 : "
             << count << endl;
    }
};

int Monster::count = 0;

class MonsterWorld 
{
private:
    Monster* monsters[100];
    int nMon = 0;

public:
    void add(Monster* m) 
    {
        monsters[nMon++] = m;
    }

    void print() 
    {
        cout << "===== Monster World =====" << endl;

        for(int i = 0; i < nMon; i++) 
        {
            monsters[i]->print();
        }

        cout << endl;
    }

    // 에너지 0 이하 몬스터 제거
    void checkStarvation() 
    {
        for(int i = 0; i < nMon; i++) 
        {

            if(monsters[i]->getEnergy() <= 0) 
            {

                delete monsters[i];

                // 뒤 요소 앞으로 이동
                for(int j = i; j < nMon - 1; j++) 
                {
                    monsters[j] = monsters[j + 1];
                }

                nMon--;
                i--;
            }
        }
    }
};

int main() 
{

    MonsterWorld world;

    world.add(new Monster("슬라임", 50));
    world.add(new Monster("오크", 20));
    world.add(new Monster("드래곤", 200));

    world.print();

    Monster::printCount();

    // 데미지
    world.add(new Monster("고블린", 10));

    world.print();

    Monster::printCount();

    return 0;
}