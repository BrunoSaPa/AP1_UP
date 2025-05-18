#include <iostream>
#include <string>

using namespace std;

int main(){
    string x;
    //read a string that is a phrase with spaces
    getline(cin, x);

    int n = x.length();
    char *c;

    //all lower cases in the phrase
    string result = "";
    c = &x[0];
    for (int i = 0; i < x.length(); i++) {
        if (c[i] == ' ') {
            result += c[i];
        } else {
            result += tolower(c[i]);
        }
    }
    cout << result << endl;
    
    //all upper cases in the phrase
    result = ""; 
        c = &x[0];
    for (int i = 0; i < x.length(); i++) {
        if (c[i] == ' ') {
            result += c[i];
        } else {
            result += toupper(c[i]);
        }
    }
    cout << result << endl;

    result = ""; 
    c = &x[0];
    for (int i = 0; i < x.length(); i++) {
        if (c[i] == ' ') {
            result += c[i];
        } else {
            result += tolower(c[i]);
        }
    }
    result[0] = toupper(result[0]);
    cout << result << endl;

    result = ""; 
        c = &x[0];

    for (int i = 0; i < x.length(); i++) {
        if (c[i] == ' ') {
            result += c[i];
        } else {
            if (result.empty() || result.back() == ' ') {
                result += toupper(c[i]);
            } else {
                result += tolower(c[i]);
            }
        }
    }
    cout << result << endl;

    result = "";
        c = &x[0];

    //interchange upper to lower 
    for (int i = 0; i < x.length(); i++) {
        if( c[i] == ' '){
            result += c[i];
        } else {
            if (isupper(c[i])) {
                result += tolower(c[i]);
            } else {
                result += toupper(c[i]);
            }
        }


    }
    cout << result << endl;

    return 0;
}