#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    vector<int> v1, v2, v3, v4;
    int res;
    string line;

    // Read first die values
    for (int i = 0; i < 6; i++) {
        cin >> res;
        v1.push_back(res);
    }
    
    // Read second die values
    for (int i = 0; i < 6; i++) {
        cin >> res;
        v2.push_back(res);
    }

    // Read target sums
    getline(cin, line);  // Catch the newline after the second die values
    getline(cin, line);  // Read the line with target sums
    stringstream ss(line);
    int num;
    while (ss >> num) {
        v3.push_back(num);
    }

    // Find possible sums in the target list
    for (auto x : v1) {
        for (auto y : v2) {
            int sum = x + y;
            if (find(v3.begin(), v3.end(), sum) != v3.end() && 
                find(v4.begin(), v4.end(), sum) == v4.end()) {
                v4.push_back(sum);
            }
        }
    }

    // Sort possible sums
    sort(v4.begin(), v4.end());

    // Output the result
    if (v4.empty()) {
        cout << "0" << endl;
    } else {
        for (size_t i = 0; i < v4.size(); i++) {
            cout << v4[i];
            if (i < v4.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}