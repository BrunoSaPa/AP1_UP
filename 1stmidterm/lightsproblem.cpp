#include <iostream>

using namespace std;

int main() {
    int n;
    int long long m;

    cin >> n >> m;
    /*first we move one bit n amount of spaces left so we have the configuration in wich the light turns on.
    then, we substract a 1 in decimal, wich will left us with the amount of sockets needed for the light to turn on
    */
    if ((m & ((1 << n) - 1)) == ((1 << n) - 1)) {
        cout << "PRENDIDA" << endl;
    } else {
        cout << "APAGADA" << endl;
    }

    return 0;
}
