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
//count the number of words that start with uppercase
while (ss >> word) {
    if (isupper(word[0])) {
        count++;
    }
}
//reset the stringstream
cout <<count;
return 0;
}