#include <iostream>
#include <fstream>
using namespace std;
#include <string>


int main(){
    string fileName = "que_soy";
    ifstream file(fileName, ios::binary);
    string key;
    int width, height;

    
    if (!file) {
        cerr << "file not found" << fileName << endl;
        return 1;
    }

    getline(file, key);

    cout << "The key is: " << key << endl;

    file >> width >> height;

    cout << "The width is: " << width << " \n The height is: " << height << endl;

    //read bytes

    char test;
    file.get(test);
    bitset<8> bts(test);
    cout << "The test ∆ is:" << bts << endl;

    char c;
    int count=0;

    cout << "Printing image..." << endl;

    while((file.get(c), file.eof()) == false){
        bitset<8> bts2(c);
        cout << bts2;
        count++;

        if((count % 5) == 0){
            cout << endl;
        }
    }
    return 0;
}