#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student {
public:
    string name;
    double grade_POO, grade_AP;

    Student(string n, double a, double g) : name(n), grade_AP(a), grade_POO(g) {}
};


int main() {
    vector<string> names = {"Mateo", "Gallo", "Regina", "Viza", "Santi", "Peru"};
    vector<Student> students;
    srand(50771708); 

    for(auto name : names) {
        students.push_back(Student(name, rand()%100, rand()%100));
    }

    for(auto s: students){
        cout << s.name << " " << s.grade_POO << " " << s.grade_AP <<" " << endl;
    }
}