#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outFile("example.txt");
    int x = 10;
    int y = 20;
    outFile << "The value of x is: " << x << endl;
    outFile << "The value of y is: " << y << endl;
    outFile << x+y << endl;
    outFile << x-y << endl;
    outFile.close();

}