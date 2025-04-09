#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}


int main() {

    int x=5; 
    int y=10;
    int result = sum(x, y);
    cout << "The sum of " << x << " and " << y << " is: " << result << endl;

    // Declare a variable to hold the file name
    string fileName;

    // Prompt the user for the file name
    cout << "Enter the file name: ";
    cin >> fileName;

    // Open the file
    ifstream inputFile(fileName);

    // Check if the file opened successfully
    if (!inputFile) {
        cerr << "Error opening file: " << fileName << endl;
        return 1;
    }

    // Read and process the file contents
    string line;
    while (getline(inputFile, line)) {
        cout << line << endl; // Print each line to the console
    }

    // Close the file
    inputFile.close();

    return 0;
}