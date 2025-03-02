#include <iostream>
#include <string>
using namespace std;

int solve_case(string S, string T) {
    int moves = 0;
    int n = S.length();

    //this first check is to check if it is possible
    int s_zeros = 0, s_ones = 0, s_question = 0;
    int t_zeros = 0, t_ones = 0;

    for (int i = 0; i < n; i++) {
        if (S[i] == '0') s_zeros++;
        else if (S[i] == '1') s_ones++;
        else s_question++;

        if (T[i] == '0') t_zeros++;
        else t_ones++;
    }

    //this is just to check if the transformation is possible
    if (s_zeros + s_question < t_zeros || s_ones + s_question < t_ones) 
        return -1;

    //count the amount of moves and missmatches
    int diff = 0, q_marks = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) {
            if (S[i] == '?') q_marks++;
            if (S[i] == '1') diff++;
            if (T[i] == '1') diff--;
        }
    }

    //check if convertion is not possible, when the difference is too great
    if (diff > 0) return -1;

    //count min moves
    moves = abs(diff);

    //at this point, we just have to swap differences
    int remaining_swaps = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) remaining_swaps++;
    }
    moves += remaining_swaps / 2;

    return moves;
}

void solution() {
    int size;
    cin >> size;
    
    for (int i = 0; i < size; i++) {
        string S, T;
        cin >> S >> T;
        int result = solve_case(S, T);
        cout << "Case " << i+1 << ": " << result << endl;
    }
}

int main() {
    solution();
    return 0;
}