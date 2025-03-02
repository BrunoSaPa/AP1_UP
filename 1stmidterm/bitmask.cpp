#include <iostream>
using namespace std;

int turnBitOn(int x, int i) {
    return x | (1 << (i - 1));
}

int turnBitOff(int x, int i) {
    return x & ~(1 << (i - 1));
}

int toggleBit(int x, int i) {
    return x ^ (1 << (i - 1));
}

bool isBitOn(int x, int i) {
    return (x & (1 << (i - 1))) != 0;
}

int turnBitsOn2468(int x) {
    return x | 0b101010100;
}


int toggleBits357(int x) {
    return x ^ 0b10101000;
}

int turnEvenOff(int x){
    return x & 0b10101010101010101010101010101010;
    //10101010101010101010101010101010
    //2863311530
    //that number in binary will help us turn off the even bits with the and operation for a 32 bit int
}

int main() {
    int x= 31,i=3;

    cout << "original num " << x << endl;
    cout << "turn bit " << i << " on: " << turnBitOn(x, i) << endl;
    cout << "change bit " << i << ": " << toggleBit(x, i) << endl;
    cout << "turn off bit " << i << ": " << turnBitOff(x, i) << endl;
    cout << "is " << i << " bit on? " << (isBitOn(x, i) ? "ye" : "no") << endl;
    cout << "turn on bits 2, 4, 6 y 8: " << turnBitsOn2468(x) << endl;
    cout << "change bits 3, 5 y 7: " << toggleBits357(x) << endl;
    cout << "turn off bits on even positions: " << turnEvenOff(x) << endl;
    return 0;
}
