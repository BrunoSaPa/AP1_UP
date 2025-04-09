#include <iostream>
using namespace std;

bool isGreater(int a, int b){
    if(a>b)return true;
    else return false;
}

void swap(int &a, int &b){
    int temp =b;
    b=a;
    a=temp;
}

int main()
{

    int size = 10;
    int arr[10]={33,12,67,23,645,2,788,344,99,1};

    for(int i=0; i<size; i++)
        for(int j=0; j<i; j++){
            int pos1 =j;
            int pos2 = j+1;
            if(isGreater(arr[pos1], arr[pos2]))
                swap(arr[pos1], arr[pos2]);
    }
    

    //print
    for(int i=0; i<size; i++){
        cout << arr[i]<< " ";
    }
}
