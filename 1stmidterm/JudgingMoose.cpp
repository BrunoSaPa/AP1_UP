#include <iostream>
using namespace std;

void judge(int a, int b);

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    judge(a,b);
}


void judge(int a, int b){
    if ((a==0) && (b == 0)){
        cout << "Not a moose";
    } else if(a == b){
        cout << "Even " << 2*a;    
    }
    else {
        if(a > b){
            cout << "Odd " << 2*a;
        }
        else{
            cout << "Odd " << 2*b;
        }
    }
}