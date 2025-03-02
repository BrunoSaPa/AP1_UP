#include <iostream>
using namespace std;
#include <string>

void solution(){
    int size;
    cin>> size;
    string S[size],T[size];
    int count[size];
    int diff,q;

    //evaluate
    for(int i =0; i<size; i++){
        cin >> S[i];
        cin >> T[i];
        count[i]=0;
        diff=0;
        q = 0;
        cout<<"New word\n";
        if(S[i]!= T[i]){
            //analize and count number of ? and 0/1 difference to know if its possible and to know what to swap ? for
            for(int j =0; j<S[i].length(); j++){
                if(S[i][j] != T[i][j]){
                    if(S[i][j]=='?'){
                        q++;
                    }
                    if(S[i][j]=='1')diff++;
                    if(T[i][j]=='1')diff--;
                    cout << "Group number: "<< i <<"     S: " << S[i][j] << "  T: " << T[i][j]<< "  Diff: " << diff << "  Q: " << q <<"  J:" << j <<endl;
                }else {
                    S[i].erase(S[i].begin() + j);
                    T[i].erase(T[i].begin() + j);
                    j--;
                }
            }
            if(diff > 0){
                cout<<"Entered diff\n";
                count[i] = -1;
                break;
            }else{
                //count/swap everything else :)
                for(int j =0; j<S[i].length(); j++){
                    //check if i can swap with the correct place for that ?
                    if(S[i][j]=='?'){
                        if(T[i][j]=='1'){
                            S[i].erase(S[i].begin() + j);
                            T[i].erase(T[i].begin() + j);
                            q--;
                            diff++;
                            count[i]++;
                        }
                    }
                    cout << "Round 2 Group number: "<< i <<"     S: " << S[i][j] << "  T: " << T[i][j]<< "  Diff: " << diff << "  Q: " << q <<"  J:" << j << "  Count: "<<count[i]<<endl;
                }
                //get rid of all the ? since we cannot optimize further
                if(q>0){
                for(int j =0; j<S[i].length(); j++){
                    if(S[i][j]=='?'){
                        if(diff<0){
                            S[i].erase(S[i].begin() + j);
                            T[i].erase(T[i].begin() + j);
                            q--;
                            diff++;
                            count[i]++;     
                        }
                        else{
                            if(T[i][j]=='1'){
                                S[i][j] ='0';
                            }else{
                                S[i].erase(S[i].begin() + j);
                                T[i].erase(T[i].begin() + j);
                                count[i]++;    
                            }  
                        }
                    }
                    cout << "Round 3 Group number: "<< i <<"     S: " << S[i][j] << "  T: " << T[i][j]<< "  Diff: " << diff << "  Q: " << q <<"  J:" << j << "  Count: "<<count[i]<<endl;
                }
                }
                //make the difference 0
                if(diff <0){
                    for(int j =0; j<S[i].length(); j++){
                    //check if i can swap with the correct place for that 0
                    if(S[i][j]=='0'){
                        if(T[i][j]=='1'){
                            S[i].erase(S[i].begin() + j);
                            T[i].erase(T[i].begin() + j);
                            q--;
                            j--;
                            diff++;
                            count[i]++;
                        }
                    }
                    cout << "Round 4 Group number: "<< i <<"     S: " << S[i][j] << "  T: " << T[i][j]<< "  Diff: " << diff << "  Q: " << q <<"  J:" << j << "  Count: "<<count[i]<<endl;
                }

                //get rid of all the 0 since we cannot optimize further
                if(diff<0){
                for(int j =0; j<S[i].length(); j++){
                    if(S[i][j]=='0'){
                        if(diff>0){
                            S[i].erase(S[i].begin() + j);
                            T[i].erase(T[i].begin() + j);
                            q--;
                            j--;
                            diff++;
                            count[i]++;     
                        }
                    }
                    cout << "Round 5 Group number: "<< i <<"     S: " << S[i][j] << "  T: " << T[i][j]<< "  Diff: " << diff << "  Q: " << q <<"  J:" << j << "  Count: "<<count[i]<<endl;
                }
                }   
                }
                //compare whats left to see if they are any matches
                for(int j =0; j<S[i].length(); j++){
                    if(S[i][j]== T[i][j]){
                        S[i].erase(S[i].begin() + j);
                        T[i].erase(T[i].begin() + j);
                        q--;
                        j--;
                        diff++;
                        count[i]++;     
                    }
                    cout << "Round 6 Group number: "<< i <<"     S: " << S[i][j] << "  T: " << T[i][j]<< "  Diff: " << diff << "  Q: " << q <<"  J:" << j << "  Count: "<<count[i]<<endl;
                }


                /*
                at this point, we just have to swap whats left,
                we can take another approach instead of literally swapping, if S[i] is even, then well just divide the 
                by 2 and add that result to count, if it is an odd number, we will sum 1 to that.
                We can do this because of the nature of the string that we have at this point, we have been cutting
                the matches till now, so whats left are just numbers that need to be swapped between them.
                */
               if(diff == 0){
                if(S[i].length()%2==0){
                count[i] += S[i].length()/2;
               }
               else count[i] += (S[i].length()/2) + 1;
               }


            }
        }
    }

    //print
    for(int i = 0; i < size; i++){
        cout<< "Case "<<i+1<<": "<<count[i]<<"\n";
    }

}

int main(){
    solution();
}