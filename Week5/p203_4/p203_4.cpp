#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> board, startBoard;
vector<char> moves;

struct Score
{
    int moveCount;
};

void print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //숫자
            if(board[i][j] == 0)
            cout << "   ";
            else
            cout << board[i][j] << " ";

            //문자
            if(board[i][j] == 0)
            cout << "   ";
            else
            cout << char('A' + board[i][j] - 1) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void init()
{
    board.assign(N, vector<int>(N));
    int num = 1;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = num++;

    board[N-1][N-1] = 0;
    startBoard = board;
}

void move(char d)
{
    int x, y;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(board[i][j] == 0)
            {
                x = i;
                y = j;
            }
    
    int nx = x, ny = y;
    if(d == 'w')
        nx++;
    if(d == 's')
        nx--;
    if(d == 'a')
        ny++;
    if(d == 'd')
        ny--;

    if(nx >= 0 && nx < N && ny >= 0 && ny < N)
    {
        swap(board[x][y], board[nx][ny]);
        moves.push_back(d);
    }
}

void save()
{
    ofstream out("/home/sws/CPP/Week5/p203_4/save.txt");
    out << N << "\n";
    for(auto &r : board)
    {
        for(int v : r)
            cout << v << " ";
            out << "\n";
    }
    out << moves.size() << "\n";
    for(char m:moves)
        out << m << " ";
}

void load()
{
    ifstream in("/home/sws/CPP/Week5/p203_4/save.txt");
    if(!in)
    {
        cout << "파일 없음\n";
        return;
    }

    in >> N;
    board.assign(N, vector<int>(N));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            in >> board[i][j];

    int k;
    in >> k;
    moves.clear();

    for(int i = 0; i < k; i++)
    {
        char c;
        in >> c;
        moves.push_back(c);
    }
    startBoard = board;
}

void replay()
{
    board = startBoard;
    print();
    for(char m:moves)
    {
        move(m);
        print();
    }
}

void saveRank()
{
    vector<Score> ranks;
    Score s;

    while (cin >> s.moveCount)
    {
        ranks.push_back(s);
    }

    sort(ranks.begin(), ranks.end(),
         [](Score a, Score b)
         {
             return a.moveCount < b.moveCount;
         });

    for (int i = 0; i < ranks.size() && i < 10; i++)
    {
        cout << ranks[i].moveCount << "\n";
    }
}

void showRank()
{
    ifstream in("/home/sws/CPP/Week5/p203_4/rank.txt");
    int x, i = 1;
    while(in >> x)
    {
        cout << i++ << "둥: " << x << "회\n";
    }
}

int main()
{
    cout << "크기(3/4/5): ";
    cin >> N;

    init();

    char cmd;
    while(true)
    {
        print();
        cout << "w/a/s/d 이동 | r:리플레이 | s:저장 | l:불러오기 | t:랭킹 | q:멈추기\n";
        cin >> cmd;

        if(cmd == 'q')
        break;
        else if(cmd == 'r')
        replay();
        else if(cmd == 's')
        save();
        else if(cmd == 'l')
        load();
        else if(cmd == 't')
        showRank();
        else move(cmd);
    }
}