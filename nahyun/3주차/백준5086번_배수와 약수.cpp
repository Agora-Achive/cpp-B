//5086번 배수와 약수
#include <iostream>
using namespace std;

int main() {
	int firstcase, secondcase;
	while (1) {
		cin >> firstcase >> secondcase;

		if (firstcase == 0 && secondcase == 0)
			break;
		//약수 구하는 식
		else if (secondcase % firstcase == 0)
			cout << "factor" << endl;
		//배수 구하는 식
		else if (firstcase % secondcase == 0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}

}
