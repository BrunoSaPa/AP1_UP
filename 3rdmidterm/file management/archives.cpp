#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream inFile("data.in");
    string food;
    inFile >> food;
    cout << "Favorite food " << food;
    inFile >> food;
    cout << " and my second favorite is " << food << endl;

    
}
