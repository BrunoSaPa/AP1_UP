#include <iostream>
using namespace std;

void solution(){
    int x,y;

    while(true){
        cin>>x;
        cin>>y;
        if(x == 0 && y == 0){
            break;
        }
        if((x + y) == 13){
            cout << "Never speak again.\n";
        } else if(x > y){
            cout << "To the convention.\n";
        }
        else if(x<y){
            cout << "Left beehind.\n";
        }
        else if((x == y) && x>0){
            cout << "Undecided.\n";
        }
    }
}

int main(){
    solution();
}