#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v={1,2,3};
    cout << *v.begin() << endl; 
    cout << *(v.end()-1) << endl;
}
