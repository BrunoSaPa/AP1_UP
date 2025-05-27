#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int res;
    for (int i=0; i<5 ; i++){
        cin >> res;
        v.push_back(res);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (auto x : v){
        cout << x << " ";
    }
}
