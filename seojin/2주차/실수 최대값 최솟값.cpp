#include <iostream>
using namespace std;

int main() {
  
  double input, max, min;
//solution 1 
  cout << "6개의 실수를 입력하세요 : ";
  cin >> input;                 //실수 한 개 받아옴
  max = min = input;            //현재 하나의 값만 받아을 경우
  for (int i = 0; i < 5; i++) { //남은 실수 다섯 개를 받아옴
    cin >> input;
    // 값을 받아올 때마다 max와 min을 바로 비교해서 바꿈
    if (input > max)
      max = input;
    if (input < min)
      min = input;
  }
  cout << "가장 큰 수 :" << max << endl;
  cout << "가장 작은 수 :" << min << endl;

  return 0;
}

//solution 2 - 배열 이용
/*
cout << "6개의 실수를 입력하세요 : ";
double a[6]; //double 배열 생성
cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]; // a[0]~a[5]까지 값 입력 받음

double max = a[0]; //최대값 기준점 설정 
for(int i=1; i<6; i++)      {
  if (max<a[i])
    max=a[i];
    }

double min = a[0]; //최소값 기준점 설정
for (int i=1; i<6; i++)      {
  if (min>a[i])
    min=a[i];
    }

    */
