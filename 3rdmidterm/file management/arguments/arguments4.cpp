#include <iostream>
using namespace std;


int main(int argc, char** argv){

    char* p = argv[1];

    while(true){
        if(*p == '\0'){
            break;
        }
        cout << *p << endl;
        p++;
    }
    
}