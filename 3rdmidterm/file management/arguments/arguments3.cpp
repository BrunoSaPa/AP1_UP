#include <iostream>
using namespace std;

void instructions(){
    cout << "Usage: ./arguments3 <int1> <int2>" << endl;
    cout << "This program will add the two integers and print the result." << endl;
}

int main(int argc, char** argv){
    if(argc != 3){
        instructions();
        exit(1);
    }

    int x,y;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    cout << "Sum: " << x + y << endl;
    
}