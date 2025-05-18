#include <iostream>
#include <string>
using namespace std;


int main(){
    string x;
    getline(cin, x);
    //check palindrome
    char *c;
    string lower = "";
    string result = "";
    c = &x[0];
    for (int i = 0; i < x.length(); i++) {
        if (c[i] == ' ') {
            lower += c[i];
        } else {
            lower += tolower(c[i]);
        }
    }

    //check if the string is a palindrome
    string reversed = "";
    for (int i = lower.length() - 1; i >= 0; i--) {
        reversed += lower[i];
    }
    if (lower == reversed) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
}
