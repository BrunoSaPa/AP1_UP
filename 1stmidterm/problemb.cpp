#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t, tall=0, low=0,n;
  cin >> t;
  for (int i=0; i<t; i++){
    cin >> n;
    //cout << "n: " << n << endl;
    int aux[n];
    for(int j=0; j<n; j++){
        //cout << "n: " << n << " j: " << j << endl;
        if (j==0){
            cin >> aux[j];
            //cout << "value: " << aux[j];
        }else{
        cin >> aux[j];
        if(aux[j-1] > aux[j]){
            low++;
        }
        else if(aux[j-1] < aux[j]){
            tall++;
        }
        }
    }
    cout << "Escenario " << i+1 << ": " << tall << " "<< low<<endl;
    tall =0;
    low =0;
  }




  return 0;
}