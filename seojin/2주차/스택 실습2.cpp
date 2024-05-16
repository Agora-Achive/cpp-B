//main.cpp
#include <iostream>
#include "MyIntStack.h"
using namespace std;

int main() {
  MyIntStack a;
  for (int i = 0; i < 11; i++) { // 11개를 푸시한다. | 0~10 : 총 11개
    if (a.push(i))
      cout << i << ' '; // 푸시된 값 출력
    else
      cout << endl << i + 1 << " 번째 stack full" << endl;
  } // tos = 10
  int n; // for룹에서 스택에 값을 팝할 때 마다 해당값을 n에 저장하고 출력하기위해 생성
  for (int i = 0; i < 11; i++) { // 11개를 팝한다.
    if (a.pop(n))
      cout << n << ' '; // 팝 한 값 출력
    else
      cout << endl << i + 1 << " 번째 stack empty";
  }
  cout << endl;
}

//MyIntStack.h
#ifndef MYINTSTACK_H
#define MYINTSTACK_H
#include <iostream>
using namespace std;

class MyIntStack {
  int p[10];
  int tos; // top of stack
public:
  MyIntStack();
  bool push(int n);
  bool pop(int &n);
};

#endif

//MyIntStack.cpp
#include "MyIntStack.h"

MyIntStack::MyIntStack() {
  tos = 0; 
  //tos = 0; 푸시할 위치를 tos가 가리킴
  //tos = -1; 팝할 위치를 tos가 가리킴
}
bool MyIntStack::push(int n) {
  if (tos == 10){
    //stack full 가득 차서 더 이상 push할 수 없음
    return false;
  }
  
  p[tos++] = n; //후위 연산자 | p[tos] = n; tos++;
  return true;

}
bool MyIntStack::pop(int &n) { 
 
  if (tos == 0){
    return false; //뽑아낼 스택이 없다는 뜻
  }
  n = p[--tos]; //전위 연산자 | n = p[tos]; tos--;
  return true;

}
