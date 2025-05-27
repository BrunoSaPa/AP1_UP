#include <iostream>
using namespace std;

int main() {
    int cases, num1, num2, diff, col;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        cin >> col;
        bool flag = true;
        for (int j = 1; j <= col; j++) {
            cin >> num1 >> num2;
            if (j == 1) {
                diff = num1 - num2;
            } else if (diff != (num1 - num2)) {
                flag = false;
            }
        }
        if (flag)
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}