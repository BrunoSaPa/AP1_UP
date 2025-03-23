#include <iostream>

using namespace std;

void hanoi(int n, int from, int aux, int to)
{
    //base case
    if (n == 1) {
        cout << "a Move rock " << n << " from place " << from << " to place " << to << endl;
        return;
    }
    
    hanoi(n - 1, from, to, aux);

    cout << "Move rock " << n << " from place " << from << " to place " << to << endl;

    hanoi(n - 1, aux, from ,to);
}

int main()
{
    //n of rocks
    int n = 5;
    hanoi(n, 1, 2, 3);
    return 0;
}
