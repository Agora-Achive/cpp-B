#include <iostream>
using namespace std;

class Stack {
	int* data;
	int Maxsize = 0; //스택 최대 크기
	int high = 0; //상위요소 인덱스
public:
	Stack(int size = 10) { //생성자
		if (size > 0) { //크기 양수 확인
			Maxsize = size;
			data = new int[Maxsize];
			high = -1; //-1이면 스택 비어있음
		}
	}

	~Stack() {
		delete[] data;
	}

	Stack& operator<<(int value); //push 연산자
	Stack& operator>>(int& value); // pop 연산자

	bool operator!() const{ //비어있는스택 검사
		if (high == -1) return true;
		else return false;
	}

};

Stack& Stack::operator<<(int value)
{
	if (high < Maxsize-1) {
		data[++high] = value;
	}
	return *this; //메서드 체이닝(하나의 객체에 대해 여러 메서드를 연속적으로 호출)
}

Stack& Stack::operator>>(int& value)
{
	if (high >= 0) 
		value = data[high--];
	return *this;
}


int main() {
	Stack stack;
	Stack stack2;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		stack2 << x;
	}
	while (true) {
		if (!stack2) break;
		int x;
		stack2 >> x;
		cout << x << ' ';
	}
	cout << endl;
}
