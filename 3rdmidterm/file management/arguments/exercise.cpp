#include <iostream>
using namespace std;

//this program prints the amount of times a key of an old cellphone has to be pressed to write a message
//the keys are as follows:
//1: 1
//2: 2, a, b, c
//3: 3, d, e, f
//4: 4, g, h, i
//5: 5, j, k, l
//6: 6, m, n, o
//7: 7, p, q, r, s
//8: 8, t, u, v
//9: 9, w, x, y, z

void printAmountOfChar(int word, int amount){
    for(int i=0; i < amount ; i++){
        cout << word;
    }
}

void convert(char* p){
    while(true){
        if(*p == '\0'){
            break;
        }
        if(*p == '1'){
            cout << "1" << endl;
        }
        //2 key
        else if(*p <= 99){    
            printAmountOfChar(2, (int(*p)-95));
        }
        //3 key
        else if(*p <= 102){
            printAmountOfChar(3, (int(*p)-98));
        }
        //4 key
        else if(*p <= 105){
            printAmountOfChar(4, (int(*p)-101));
        }
        //5 key
        else if(*p <= 108){
            printAmountOfChar(5, (int(*p)-104));
        }
        //6 key
        else if(*p <= 111){
            printAmountOfChar(6, (int(*p)-107));
        }
        //7 key
        else if(*p <= 115){
            printAmountOfChar(7, (int(*p)-110));
        }
        //8 key
        else if(*p <= 118){
            printAmountOfChar(8, (int(*p)-114));
        }
        //9 key
        else if(*p <= 122){
            printAmountOfChar(9, (int(*p)-117));
        }
        p++;
    }
}

int main(int argc, char** argv){
    for (int i = 1; i < argc; i++){
        cout << i << " word: " ;
        convert(argv[i]);
        cout << endl;
    }    
}