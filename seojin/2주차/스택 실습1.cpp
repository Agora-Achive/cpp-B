//main.cpp
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
  Stack stack; // 생성자에 인자를 주면 그 크기의 스택을 만들고 없을 경우 기본
               // 크기는 10
  stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
  while (true) {
    if (!stack)
      break; // 스택 empty
    int x;
    stack >> x; // 스택의 탑에 있는 정수 팝
    cout << x << ' ';
  }
  cout << endl;
}

//Stack.h
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;

class Stack{
  int size;
  int *p;
  int tos; //top of stack
  
public:
    Stack(int size=10);
    ~Stack();
    Stack& operator<<(int n);
    Stack& operator>>(int &n);
    bool operator!();
};

#endif

//Stack.cpp
#include "Stack.h"
#include <iostream>

Stack::Stack(int size){
  this->size=size;
  p = new int[size]; //정수 사이즈 배열 p 포인터로 할당
  tos = 0;
}

Stack::~Stack(){
  if(p) //nullptr이 아닐시
    delete[]p;
}

Stack& Stack::operator<<(int n){
  //push
  if(tos ==size){
    //stack full
    return *this;
  }
  p[tos++]=n;
  return *this;
}

Stack& Stack::operator>>(int &n){
  //pop, stack empty
  if(tos==0)
    return *this;
  n=p[--tos];
  return *this;
}

bool Stack::operator!(){
  if(tos==0) return true;
  else return false;
}
