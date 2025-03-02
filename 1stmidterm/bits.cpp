#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int x;
    char c;
    using bin8 = bitset<8>;
    using bin16 = bitset<16>;
    using bin64 = bitset<64>;

    c='A';
    cout << (bin8)c << endl;

    x=0;
    cout << (bin16)x << endl;

    x=1025;
    cout << (bin16)x << endl;

    x=-1;
    cout << (bin16)x << endl;

    float z;
    z=1.5;
    cout << (bin64)z << endl;
}