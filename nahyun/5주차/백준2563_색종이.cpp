//2563 - 색종이
#include <iostream>
using namespace std;

int main() {
	int papercnt, cnt = 0;
	cin >>	papercnt;
	int arr[100][100] = { 0, };

	int x, y;
	for (int z = 0; z < papercnt; z++) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}

	cout << cnt;
	
}
