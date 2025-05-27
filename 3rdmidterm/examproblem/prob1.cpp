#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    int n, x, value, aux;

    cin>> n;
    cin >>x;
    cin>> value;

    for(int i = 1; i <= n; i++){
        cin >> aux;
        mp[aux]++;
    }

    int count = 0;
    for(int i = 1; i <= x; i++){
        if(i==1){
            count = mp[i];
        }else if(count > mp[i]){
            count = mp[i];
        }
    }

    cout << count * value << endl;
}