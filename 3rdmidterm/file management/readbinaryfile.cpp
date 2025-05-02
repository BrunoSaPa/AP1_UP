#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string name;
    int month, day, year;
    ifstream inFile("example.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    
}