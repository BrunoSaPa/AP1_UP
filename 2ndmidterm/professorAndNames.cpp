#include <iostream>
#include <sstream>
using namespace std;

int main() {
    const int SIZE = 100;
    int countRight, countLeft;
    int numOfQuestions, numOfStudents;
    string names[SIZE];

    cin >> numOfStudents;
    cin.ignore(); 

    string temp, input;
    getline(cin, input);
    stringstream ss(input);

    int ind = 0;
    while (ss >> temp && ind < SIZE) {
        names[ind++] = temp;
    }

    string* ptr = names;
    cin >> numOfQuestions;
    cin.ignore();
    int index;
    bool isLeft = false;
    bool isRight = false;
    string leftWord, rightWord;

    for (int i = 0; i < numOfQuestions; i++) {
        countLeft = 0;
        countRight = 0;
        cin >> index;
        isLeft = false;
        isRight = false;
        index--;
        leftWord = "";
        rightWord = "";

        //Count Right
        for (int j = 0; j <= index; j++) {
            if((*(ptr+j)) != "?"){
                countRight=0;
                isRight = true;
                rightWord = *(ptr+j);
            }else{
                countRight++;
            }
        }
        //Count Left
        for (int j = numOfStudents-1; j >= index; j--) {
            if((*(ptr+j)) != "?"){
                countLeft=0;
                isLeft = true;
                leftWord = *(ptr+j);
            }else{
                countLeft++;
            }
        }

        //we know how many ? there are and if there was at least one name in the way

        if(isLeft && isRight){
            if(countLeft < countRight){
                while(countLeft > 0){
                    cout << "izquierda ";
                    countLeft--;
                }
                cout << "de "<<leftWord << endl;
            }else if(countRight < countLeft){
                while(countRight > 0){
                    cout << "derecha ";
                    countRight--;
                }
                cout << "de "<<rightWord << endl;

            }else if((countLeft > 0 && countRight > 0) && (countLeft == countRight)){
                cout << "justo enmedio de "<<rightWord<<" y "<<leftWord<<endl;
            }else{
                cout << leftWord<<endl;
            }
        }else if(isLeft){
            while(countLeft > 0){
                cout << "izquierda ";
                countLeft--;
            }
            cout << "de "<<leftWord << endl;
        }else if(isRight){
            while(countRight > 0){
                cout << "derecha ";
                countRight--;
            }
            cout << "de "<<rightWord << endl;
        }

    }

    return 0;
}
