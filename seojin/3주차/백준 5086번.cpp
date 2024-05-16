#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    while(x!=0&&y!=0){
        if (y%x == 0)
            cout << "factor" << endl;
        else if (x%y == 0 )
            cout << "multiple" << endl;
        else
            cout << "neither" << endl;
        cin >> x >> y;    
    }  
        }
