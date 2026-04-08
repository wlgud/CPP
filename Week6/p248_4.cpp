#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX_H = 40;
const int MAX_W = 80;

int width, height;
int mineCount;

// 지뢰 위치
int MineMapMask[MAX_H][MAX_W];

// 화면 출력용
int MineMapLabel[MAX_H][MAX_W];

// 방향
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void init() 
{
    for(int i = 0; i < height; i++) 
    {
        for(int j = 0; j < width; j++) 
        {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = 0;
        }
    }
}

void placeMines() 
{
    int count = 0;

    while(count < mineCount) 
    {
        int x = rand() % width;
        int y = rand() % height;

        if(MineMapMask[y][x] == 0) 
        {
            MineMapMask[y][x] = 1;
            count++;
        }
    }
}

int countMines(int y, int x) 
{
    int cnt = 0;

    for(int i = 0; i < 8; i++) 
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < height && nx >= 0 && nx < width) 
        {
            if(MineMapMask[ny][nx] == 1)
                cnt++;
        }
    }
    return cnt;
}

void printMap() 
{

    // 열 번호 출력
    cout << "   ";
    for(int i = 0; i < width; i++)
        cout << i << " ";
    cout << endl;

    for(int i = 0; i < height; i++) 
    {

        // 행 번호 출력
        cout << i << " ";

        for(int j = 0; j < width; j++) 
        {

            if(MineMapLabel[i][j] == 0) 
            {
                cout << ". ";
            }
            else if(MineMapLabel[i][j] == 2) 
            {
                cout << "P ";
            }
            else 
            {
                int cnt = countMines(i, j);
                cout << cnt << " ";
            }
        }
        cout << endl;
    }
}

bool openCell(int y, int x) 
{
    if(MineMapMask[y][x] == 1) 
    {
        return false;
    }

    MineMapLabel[y][x] = 1;
    return true;
}

int main() 
{
    srand(time(0));

    //맵 크기 입력
    cout << "맵 크기 입력 (가로 세로): ";
    cin >> width >> height;

    //지뢰 개수 입력
    cout << "지뢰 개수 입력: ";
    cin >> mineCount;

    init();
    placeMines();

    while(true) 
    {
        printMap();

        string input;
        cin >> input;

        int x, y;

        if(input == "p") 
        {
            cin >> x >> y;
            MineMapLabel[y][x] = 2;
        }
        
        else 
        {
            x = stoi(input);
            cin >> y;

            if(!openCell(y, x)) 
            {
                cout << "게임 종료\n";
                break;
            }
        }
    }

    return 0;
}