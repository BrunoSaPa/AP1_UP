#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a1, a2, a3, v1, v2, v3, t1, t2, t3;

    while (true) {
        cin >> a1 >> a2 >> a3 >> v1 >> v2 >> v3 >> t1 >> t2 >> t3;
        if (a1 == 0) break;

        vector<int> bottles = {a1, a2, a3, v1, v2, v3, t1, t2, t3};
       
        vector<vector<int>> configs = {
            {0, 1, 2}, // AVT
            {0, 2, 1}, // ATV
            {1, 0, 2}, // VAT
            {1, 2, 0}, // VTA
            {2, 0, 1}, // TAV
            {2, 1, 0}  // TVA
        };
        vector<string> tags = {"AMBAR", "VERDE", "TRANSPARENTE"};
        
        int minMoves = 10000000;
        vector<int> bestConfig;
        
        for(auto& x : configs) {
    
            int moves = 0;
           
            for(int i = 0; i < 3; i++) {
                int type = x[i]; 
                
                for(int j = 0; j < 3; j++) {
                    if(j != type) {
                        moves += bottles[i * 3 + j];
                    }
                }
            }
            
            
            if (moves < minMoves) {
                minMoves = moves;
                bestConfig = x;
            } else if (moves == minMoves) {
              
                vector<string> actual = {
                    tags[x[0]],
                    tags[x[1]],
                    tags[x[2]]
                };
                vector<string> mejor = {
                    tags[bestConfig[0]],
                    tags[bestConfig[1]],
                    tags[bestConfig[2]]
                };
                if (actual < mejor) {
                    bestConfig = x;
                }
            }
        }
        
        vector<string> posToTag(3);
        for (int pos = 0; pos < 3; pos++) {
            posToTag[pos] = tags[bestConfig[pos]];
        }
        cout << posToTag[0] << " " << posToTag[1] << " " << posToTag[2] << endl;
    }
    
    return 0;
}