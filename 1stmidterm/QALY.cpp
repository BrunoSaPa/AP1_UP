#include <iostream>
using namespace std;

void solution(){
    int size;
    double x,y,z=0;
    cin>> size;
    for(int i=0; i <size; i++){
        cin>>x;
        cin>>y;
        z += x * y;
    }
    cout<<z;

}

int main(){
    solution();
}