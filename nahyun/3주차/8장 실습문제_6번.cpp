#include <iostream>
#include <string>
using namespace std;
class BaseArray {
private:
	int Capacity; //동적 할당된 메모리 용량
	int* mem; //동적 할당된 메모리 용량으로 만들 동적할당배열
protected:
	BaseArray(int capacity) { //생성자
		this->Capacity = capacity;
		mem = new int[Capacity]; //동적 배열 선언
	}
	~BaseArray() { delete[] mem; } //소멸자

	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return Capacity; }

};

class MyStack : public BaseArray {
	int index = 0;
public:
	MyStack(int capacity) : BaseArray(capacity){};
	void push(int val) { put(index++, val); }
	int pop() { return get(--index); }
	int capacity() { return getCapacity(); } //스택 용량
	int length() { return index; } //스택 크기
};
int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택용량 : " << mStack.capacity() << ", 스택 크기 : " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>>";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';//스택에서 팝
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}
