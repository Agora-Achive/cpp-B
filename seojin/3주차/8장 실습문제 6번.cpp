//main.cpp
#include "MyStack.h"
#include <iostream>
using namespace std;

int main() {
  MyStack mStack(100);
  int n;
  cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
  for (int i = 0; i < 5; i++) {
    cin >> n;
    mStack.push(n); // 총 5개 스택에 푸시
  }
  cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length()<< endl;
  cout << "스택의 모든 원소를 팝하여 출력한다>> ";

  // 스택이 비어있지 않으면 계속 팝
  while (mStack.length() != 0) {
    cout << mStack.pop() << ' '; // 스택에서 팝
  }
  cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}

//BaseArray.h
#ifndef BASEARRAY_H
#define BASEARRAY_H
//빼오려는 것 tail
// 마지막 input은 head 다끝나면 0번 index로 return
class BaseArray {
private:
 int capacity; // 동적 할당된 메모리 용량
 int *mem; 
protected:
 BaseArray(int capacity=100) {
 this->capacity = capacity; mem = new int [capacity];
 }
 ~BaseArray() { delete [] mem; }
 void put(int index, int val) { mem[index] = val; }
 int get(int index) { return mem[index]; }
 int getCapacity() { return capacity; }
};

#endif

//MyStack.h
#ifndef MYSTACK_H
#define MYSTACK_H
#include "BaseArray.h"

class MyStack : public BaseArray{ //상속받음
   int tos;   
public:
  MyStack(int capacity);
  void push(int n);
  int pop();
  int capacity();
  int length();
};

#endif

//MyStack.cpp
  #include "MyStack.h"
// 생성자 -BaseArray 생성자 호출->스택 용량 설정
  MyStack::MyStack(int capacity) : 
  BaseArray(capacity){ 
    tos = 0; //초기화(스택 empty)

  }
  void MyStack::push(int n){
    //stack full?
    if(tos == capacity()) return; //full일시 함수 종료
    put(tos++,n); // 현재 tos위치에 n저장 후 tos +1
  }

  int MyStack::pop(){
    //stack empty?
    if(tos == 0) return -1;
    return get(--tos);
  }
 // 최대 용량 반환
int MyStack::capacity() {
    return getCapacity();
}

// 스택의 현재 크기 반환
  int MyStack::length(){
    return tos;
  }
