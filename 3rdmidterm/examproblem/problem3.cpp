#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // consume the newline after n
    string s;

    for (int t = 0; t < n; t++) {
        getline(cin, s);
        int len = s.size();
        int maxHeight = 0;

        vector<int> alturas(len, 0);
        for (int i = 0; i < len; i++) {
            if (s[i] == 'O') {
                int h = 1;
                for (int j = i - 1; j >= 0 && s[j] == 'O'; j--) {
                    h++;
                }
                alturas[i] = h;
                if (h > maxHeight) maxHeight = h;
            }
        }

        for (int fila = maxHeight - 1; fila >= 0; fila--) {
            for (int i = 0; i < len; i++) {
                if (alturas[i] > fila) cout << 'O';
                else cout << ' ';
            }
            cout << "\n";
        }

        for (int i = 0; i < len; i++) cout << 'X';
        if (t < n - 1) cout << "\n\n";
    }
    return 0;
}