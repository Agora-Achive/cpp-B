/*

- 백준 코딩테스트 
**2386번**
도비의 영어 공부
https://www.acmicpc.net/problem/2386

도비의 영어 공부를 위해 입력 안에 주어진 알파벳(소문자)의 개수를 문장에서 세어 출력하는 프로그램을 만들어야한다. 
각 줄에서 처음으로 입력한 알파벳(소문자)을 뒤에 입력된 문장 안에서 그 개수를 찾는 것이다. 
이때 주의할 점은 소문자만 세는 것이 아니라 대문자도 세야하는 것이다. 또한 '#'을 입력하면 종료가 된다.

풀면서 어려웠던 점
: 처음 문제를 볼 때 출력 예시를 잘못 해석하여 getline을 사용할 생각을 못했었습니다.
또, 대문자 알파벳의 소문자 변환하는 부분과 문자 하나하나를 비교해가며 카운트를 세는 부분을 for문으로 구현할 때 기준점 c를 정하는 것에
어려움이 있었습니다.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    char c;
    int count = 0;
    string sentence;

    while(1){

        cin >> c;
        getline(cin,sentence);

        if(c=='#'){
            break;
        }

        // 대문자->소문자 변환
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]>='A' && sentence[i]<='Z'){
                sentence[i] = sentence[i] - 'A' + 'a';
            }
        }
        
        // 첫 알파벳인 c와의 비교를 통한 수 세기
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==c){
                count ++;
            }
        }

        cout << c << ' ' << count;
        cout<<'\n';
        count = 0; // while문에 있으므로 한 번 돌고 count 초기화 필수

    }
}
