#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

string s;
getline(cin, s);
stringstream ss(s);
string word;
int count = 0;

while (ss >> word) {
    count++;
    if(count == 2){
        for(int i=word.length()-1; i>=0; i--){
            cout << word[i];
        }
    } else {
        cout<<word;
    }
    cout<<" ";
}
return 0;
}