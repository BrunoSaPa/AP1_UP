#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> amountX;
    string n;

    while (getline(cin, n)) {
        if (n == "0") {
            int res = 0;
            sort(amountX.begin(), amountX.end());
            for(int i = 0; i < amountX.size(); i++) {
                res += (amountX.back() - amountX[i]);
            }
            cout << res;
            break;
        }
        if (n == "1") {
            int res = 0;
            sort(amountX.begin(), amountX.end());
            for(int i = 0; i < amountX.size(); i++) {
                res += (amountX.back() - amountX[i]);
            }
            cout << res << endl;
            amountX.clear();
            continue;
        }
        int count = 0;
        for (char c : n) {
            if (c == 'X') {
                count++;
            }
        }
        amountX.push_back(count);
    }
}