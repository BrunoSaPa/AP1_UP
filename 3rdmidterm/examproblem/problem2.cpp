#include <iostream>
using namespace std;

int main(){

    string n;       
    cin >> n;
    unsigned long long a,b,c;
    unsigned long long min=1000000000000;

    for (int i = 1; i < 10; ++i) {           
        for (int j = i + 1; j < 11; ++j) {   
            a = stoi(n.substr(0, i));
            b = stoi(n.substr(i, j - i));
            c = stoi(n.substr(j));
            if(min > (a+b+c)) min = (a+b+c);
            //cout << "a: " << a<< " b:" << b<< " c:" << c <<  " min:"<< min<< endl;
        }
    }
    cout << min;

}