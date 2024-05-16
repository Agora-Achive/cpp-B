#include <iostream>
using namespace std;

class MyIntStack {
	int p[10]; //최대 10개의 정수 저장
	int tos; //스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() { tos = -1; }
	bool push(int n); //정수 n 푸시
	bool pop(int& n); // 팝하여 n에 저장
};

bool MyIntStack::push(int n)
{
	if (tos >= 9) return false;

	p[++tos] = n;
	return true;
}

bool MyIntStack::pop(int& n)
{
	if(tos == -1) return false;

	n = p[tos--];
	return true;
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << "  번째 stak full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << "  번째 stak empty";
	}
	cout << endl;
}
