#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  string result = "no existe";

  do{
    int num[t];
    for(int i = 0; i < t; i++){
        cin>>num[i];
        //cout << "num i" << num[i];
    }
    
    for (int reference = t-1; reference >=3; reference--)
    {
        for (int p = reference -1; p >1; p--){
            for (int q = reference-2; q>0; q--){
                for (int r = reference -3; r >=0;r--){

                    if (num[reference]==(num[p]+num[q]+num[r])){
                        result = to_string(num[reference]);
                        goto end;
                    }

                }
            }
        }
    }
    end:
    cout << result << endl;
    result= "no existe";
    cin>> t;
  }while(t!=0);
  return 0;
}
