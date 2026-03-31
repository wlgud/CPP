#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void randomMap(int m[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            m[i][j] = rand() % 2;
        }
    }
}

void printMap(int m[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        cout << m[i][j] << " ";
        cout << endl;
    }
}

void checkMap(int m[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        int sum = 0;
        for(int j = 0; j < 5; j++)
        sum += m[i][j];
        if(sum == 0 || sum == 5)
            cout << "가로 " << i << " OK\n";
    }

    for(int j = 0; j < 5; j++)
    {
        int sum = 0;
        for(int i = 0; i < 5; i++)
        sum += m[i][j];
        if(sum == 0 || sum == 5)
            cout << "세로 " << j << " Ok\n";
    }

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 5; i++)
    {
        sum1 += m[i][i];
        sum2 += m[i][4-i];
    }
    if(sum1 == 0 || sum1 == 5)
        cout << "주대각선 OK\n";
    if(sum2 == 0 || sum2 == 5)
        cout << "부대각선 Ok\n";
}

int main()
{
    int map[5][5];
    srand(time(0));

    randomMap(map);
    printMap(map);
    checkMap(map);

    return 0;
}