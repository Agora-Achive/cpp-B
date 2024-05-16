//main.cpp
#include <iostream>
#include <string>
#include "Word.h"

using namespace std;

int main() {
    cout << " 문장 입력 : ";
    string input;
    getline(cin, input);

    Word Counting;
    Counting.WordCounting(input);

    return 0;
}

//Word.h
#ifndef WORD_H
#define WORD_H

#include <iostream> 
#include <string>
#include <cstring>
using namespace std;
class Word {
   
public:
    void WordCounting(const string& str);
};

#endif

//Word.cpp
#include "Word.h"
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

void Word::WordCounting(const string& str){ // const 사용-> 문자열 수정 불가 +레퍼런스 사용
    istringstream iss(str); // 문자열 단어 단위로 분
    unordered_map<string, int> wordCounts; // <단어, 중복 개수>

    string word;
    while (iss >> word) {
        wordCounts[word]++; //이미 등록된 단어일시 중복 개수 +1
    }

    // 입력된 순서대로 출력하기 위하여 입력된 문자열을 다시 토큰화 후 순서대로 출력
    istringstream iss2(str); 
    while (iss2 >> word) {
        if (wordCounts.find(word) != wordCounts.end()) {
            cout << word << " : " << wordCounts[word] << endl;
            wordCounts.erase(word); // 중복 출력 방지를 위해 이미 출력한 단어는 맵에서 제거
        }
    }
}
