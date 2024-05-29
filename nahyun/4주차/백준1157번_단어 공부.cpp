//1157번
#include <iostream>
#include <string>
using namespace std;

int main() {
	string Word;
	int Wordcnt[26] = { 0 }; //Wordcnt 초기화
	cin >> Word;

	//대문자로 바꿔줌
	for (int i = 0; i < Word.length(); i++) {
		Word[i] = toupper(Word[i]);
	}

	//입력된 문자가 나온 횟수를 Wordcnt에 저장
	for (int i = 0; i < Word.length(); i++) {
		int num = Word[i] - 'A';
		Wordcnt[num] += 1;
	}

	int Max = Wordcnt[0];
	int cnt = 1, maxindex = 0;
	//가장 많이 나온 문자의 인덱스를 Max에 저장
	for (int i = 1; i < 26; i++) {
		if (Wordcnt[i] > Max) {
			Max = Wordcnt[i];
			maxindex = i;
			cnt = 1;
		}
		else if (Wordcnt[i] == Max)
			cnt++;
	}


	//Max를 이용해서 가장 많이 사용된 알파벳 출력
	int Alpha = 'A' + maxindex;
	if (cnt == 1)
		cout << (char)Alpha;
	else
		cout << "?";
}
