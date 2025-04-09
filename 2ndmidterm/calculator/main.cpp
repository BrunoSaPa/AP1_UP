#include <iostream>
#include "math.h"
#include "aux.h"
using namespace std;

int main() {

    char choice;
    cout << "Choose an option:" << endl;
    cout << "C Calculate Circle Area" << endl;
    cout << "R Calculate Rhombus Area" << endl;
    cout << "+ Sum" << endl;
    cout << "- Subtract" << endl;
    cout << "E Exit" << endl;

    while(true){
    choice = getOperation();
    switch (choice) {
        case 'C': {
            cout << "Enter the radius of the circle: ";
            double radius = getNumber();
            double area = calculateCircleArea(radius);
            displayResult(area);
            break;
        }
        case 'R': {
            double diagonals[2];
            cout << "Enter the lengths of the diagonals of the rhombus: ";
            diagonals[0] = getNumber();
            diagonals[1] = getNumber();
            double area = calculateRhombusArea(diagonals[0], diagonals[1]);
            displayResult(area);
            break;
        }
        case '+': {
            double numbers[2];
            cout << "Enter two numbers to sum: ";
            numbers[0] = getNumber();
            numbers[1] = getNumber();
            double result = sum(numbers[0], numbers[1]);
            displayResult(result);
            break;
        }
        case '-': {
            double numbers[2];
            cout << "Enter two numbers to subtract: ";
            numbers[0] = getNumber();
            numbers[1] = getNumber();
            double result = subtract(numbers[0], numbers[1]);
            displayResult(result);
            break;
        }
        case 'E':{
            cout << "Exiting the program." << endl;
            return 0;
        }
    }
}
    return 0;
}