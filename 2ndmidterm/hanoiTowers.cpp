#include <iostream>
using namespace std;
#define height 5

int place[3][height];
int rock[height];
int floor
int heights[3];


void move(int size, int from, int to){

}

void printFloor(int floor){

}





int main(){
    
    for (int i=0; i<3; i++){
        for(int j=0; j<height; j++){
            place[i][j]= -1;
        }
    }

    rock[4] = 1;
    rock[3] = 1;
    rock[2] = 1;
    rock[1] = 1;
    rock[0] = 1;

    //draw towers

    cout << "\t" << place[0][4] << "\t" << place[1][4] << "\t"<< place[2][4] << endl;

    cout << "\t" << place[0][3] << "\t" << place[1][3] << "\t"<< place[2][3] << endl;

    cout << "\t" << place[0][2] << "\t" << place[1][2] << "\t"<< place[2][2] << endl;

    cout << "\t" << place[0][1] << "\t" << place[1][1] << "\t"<< place[2][1] << endl;

    cout << "\t" << place[0][0] << "\t" << place[1][0] << "\t"<< place[2][0] << endl;

    cout << "------------------------" << endl;


}

