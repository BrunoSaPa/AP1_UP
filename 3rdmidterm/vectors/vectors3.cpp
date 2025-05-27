#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v={1,2,3,4,6,675,66};
    reverse(v.begin(), v.end());
    for (auto x : v){
        cout << x;
    }
}
