#include <array>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int amount_of_changes(const array<int, 9> &ns, const array<int, 3> ans) {
    int sum = 0;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (j == ans[i])
            continue;
            
            sum += ns[i*3+j];
        }
    }
    return sum;
}

bool solve() {
    const array<array<int, 3>, 6> possible_answers{
        {
            {0, 2, 1}, 
            {0, 1, 2}, 
            {2, 1, 0},
            {2, 0, 1}, 
            {1, 0, 2},
            {1, 2, 0}, 
         }};
    unordered_map<int, string> names{
        {0, "AMBAR"},
        {1, "VERDE"},
        {2, "TRANSPARENTE"},
    };
    array<int, 9> ns;
    vector<int> correct_ans;
    for (auto &n : ns) {
        cin >> n;
        if (n==0 && cin.eof()) return false;
    }
    int min_i=-1;
    int mn = INT_MAX;
    for ( int i=0; i<6;i++) {
        int sum = amount_of_changes(ns, possible_answers[i]);
        if (sum < mn) {
            mn = sum;
            min_i = i;
        }
        mn = min(sum, mn);
    }
    correct_ans.push_back(min_i);

    for (int i = 0; i<6;i++) {
        if (i == min_i) continue;
        if (amount_of_changes(ns, possible_answers[min_i]) == amount_of_changes(ns, possible_answers[i]))
        {
            correct_ans.push_back(i);
        }
    }
    auto correct_it = min(correct_ans.begin(), correct_ans.end());
    for (auto el: possible_answers[*correct_it])
        cout << names[el] <<' ' ;

    cout << '\n';
    return true;
}

int main() {
    while(solve()) {
    }
}include <array>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int amount_of_changes(const array<int, 9> &ns, const array<int, 3> ans) {
    int sum = 0;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (j == ans[i])
            continue;
            
            sum += ns[i*3+j];
        }
    }
    return sum;
}

bool solve() {
    const array<array<int, 3>, 6> possible_answers{
        {
            {0, 2, 1}, 
            {0, 1, 2}, 
            {1, 0, 2},
            {1, 2, 0}, 
            {2, 0, 1}, 
            {2, 1, 0}
         }};
    unordered_map<int, string> names{
        {0, "AMBAR"},
        {1, "VERDE"},
        {2, "TRANSPARENTE"},
    };
    array<int, 9> ns;
    vector<int> correct_ans;
    for (auto &n : ns) {
        cin >> n;
        if (n==0) return false;
    }
    int min_i=-1;
    int mn = INT_MAX;
    for ( int i=0; i<6;i++) {
        int sum = amount_of_changes(ns, possible_answers[i]);
        if (sum < mn) {
            mn = sum;
            min_i = i;
        }
        mn = min(sum, mn);
    }
    correct_ans.push_back(min_i);

    for (int i = 0; i<6;i++) {
        if (i == min_i) continue;
        if (amount_of_changes(ns, possible_answers[min_i]) == amount_of_changes(ns, possible_answers[i]))
        {
            correct_ans.push_back(i);
        }
    }

    for (auto id: possible_answers[*min(correct_ans.begin(), correct_ans.end())])
        cout << names[id] << ' ';

    cout << '\n';
    return true;
}

int main() {
    while(solve()) {
    }
}