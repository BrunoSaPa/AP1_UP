#include <iostream>

using namespace std;

int main() {
    int t;
    
    while (cin >> t && t != 0) {
        int a = 0, b = 0;
        int mask = 1; 
        //we start at 1, not 0
        int position = 1;
        
        while (t > 0) {
            if (t & 1) {
                if (position % 2 != 0) {
                    a |= mask; 
                } else {
                    b |= mask; 
                }
            }
            t >>= 1;  
            mask <<= 1; 
            position++; 
        }
        
        cout << a << " " << b << endl;
    }
    
    return 0;
}
