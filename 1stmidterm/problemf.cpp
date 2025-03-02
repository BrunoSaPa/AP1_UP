#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    uintmax_t s=0,r=0,n=0,o=0;
  cin >> n;


    
    r = (n*(n+1)/2);
  r = pow(r,2);
  cout << "first r: "<< r<< endl;

  for( uintmax_t i =1; i < n+1; i++){
    s += pow(i,2);
    }
  cout << "first s: "<< s<< endl;

    cout << r-s;
/*
    for(unsigned long long int i =1; i<=n; i++){
        o += 2*n*((n*(n-1))/2);
    }

    cout << o;*/
    return 0;
}