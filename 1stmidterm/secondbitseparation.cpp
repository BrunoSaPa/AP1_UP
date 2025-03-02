#include <iostream>

using namespace std;

int main() {
    int t;

    while (cin >> t && t != 0) {
        int a = 0, b = 0;  
        int mask = 1;      
        //now we start at 0 since we start counting from 0
        int count = 0;     

        while (t > 0) {
            if (t & 1) { 
                if (count % 2 == 0) {
                    a |= mask;  
                } else {
                    b |= mask; 
                }
                count++;  
            }
            t >>= 1;  
            mask <<= 1;  
        }

        cout << a << " " << b << endl;
    }

    return 0;
}
