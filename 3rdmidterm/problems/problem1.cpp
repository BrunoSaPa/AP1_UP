#include <iostream>
#include <string>
using namespace std;

int main(){
    string x;
    int count =0;
    char *p;

    getline(cin, x);
        p = &x[0];
        for (int i = 0; i < x.length(); i++) {
            if (islower(p[i])) {
                count++;
            }
        }

    

    cout << count << " minusculas";
}
