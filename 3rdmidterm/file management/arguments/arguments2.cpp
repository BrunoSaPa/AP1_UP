#include <iostream>
using namespace std;

int main(int argc, char** argv){
    cout << "Recieved " << argc << " arguments" << endl;
    for (int i = 0; i < argc; i++){
        cout << "Argument " << i << ": " << argv[i] << endl;
    }
    
}