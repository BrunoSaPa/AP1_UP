#include <iostream>
using namespace std;

void solution(){
    double x, ans;
    cin >> x;
    double num = 5280.0 / 4854.0 * 1000.0;
    cout << int((x * num)+.5);
}

int main(){
    solution();
}