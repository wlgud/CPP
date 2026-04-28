#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXWORDS 100

struct WordPair 
{
    string eng;  // 영어 단어
    string kor;  // 한글 설명
};

class MyDic 
{
    WordPair words[MAXWORDS];  // 단어 배열
    int nWords;                // 현재 단어 수

public:
    // 생성자
    MyDic() 
    {
        nWords = 0;
    }

    // 단어 추가
    void add(string eng, string kor) 
    {
        if (nWords < MAXWORDS) 
        {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    // 파일에서 읽기
    void load(string filename) 
    {
        ifstream fin(filename);

        string eng, kor;
        while (fin >> eng >> kor) 
        {
            add(eng, kor);
        }

        fin.close();
    }

    // 파일에 저장
    void store(string filename) 
    {
        ofstream fout(filename);

        for (int i = 0; i < nWords; i++) 
        {
            fout << words[i].eng << " " << words[i].kor << endl;
        }

        fout.close();
    }

    // 출력
    void print() 
    {
        for (int i = 0; i < nWords; i++) 
        {
            cout << i << ": " << words[i].eng
                 << " - " << words[i].kor << endl;
        }
    }

    // 영어 단어 반환
    string getEng(int id) 
    {
        if (id >= 0 && id < nWords)
            return words[id].eng;
        return "";
    }

    // 한글 뜻 반환
    string getKor(int id) 
    {
        if (id >= 0 && id < nWords)
            return words[id].kor;
        return "";
    }
};

int main() 
{
    MyDic dic;

    // 단어 추가
    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("cat", "고양이");

    cout << "현재 단어장:" << endl;
    dic.print();

    // 파일 저장
    dic.store("dic.txt");

    // 새로운 객체로 파일 읽기
    MyDic dic2;
    dic2.load("dic.txt");

    cout << "\n파일에서 읽은 단어장:" << endl;
    dic2.print();

    return 0;
}