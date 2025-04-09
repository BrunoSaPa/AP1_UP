#include <iostream>
using namespace std;


double getNumber() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    return n;
}


char getOperation() {
    char o;
    while(true){
        cout << "Enter an operation (+, -, C, R, E): ";
        cin >> o;
        if (o == '+' || o == '-' || o == 'C' || o == 'R' || o == 'E') {
            return o;
        } else {
            cout << "Invalid operation. Please try again." << endl;
        }
    }

}

void displayResult(double result) {
    cout << "The result is: " << result << endl;
    return;
}