#include <iostream>
using namespace std;

int main() {
	float data[6] = { 0, };
	cout << "6개의 실수를 입력하세요 : ";
	for (int i = 0; i < 6; i++) {
		cin >> data[i];
	}
	float Maxdata = data[0];
	float Mindata = data[0];

	for (int i = 1; i < 6; i++) {
		if (data[i] > Maxdata)
			Maxdata = data[i];
		if (data[i] < Mindata)
			Mindata = data[i];
	}

	cout << "가장 큰 수 : " << Maxdata << '\n' << "가장 작은 수 : " << Mindata;
}
