#include <iostream>
#include <sstream>
using namespace std;

int main() {
    const int SIZE = 100;
    int numOfStudents, numOfQuestions;
    string names[SIZE];

    // Leer número de estudiantes
    cin >> numOfStudents;
    cin.ignore();

    // Leer los nombres
    string temp, input;
    getline(cin, input);
    stringstream ss(input);
    int ind = 0;
    while (ss >> temp && ind < SIZE) {
        names[ind++] = temp;
    }

    // Leer número de preguntas
    cin >> numOfQuestions;
    cin.ignore();
    
    int index;
    
    // Procesar cada consulta
    for (int i = 0; i < numOfQuestions; i++) {
        cin >> index;
        index--; // Convertir a índice basado en 0
        
        // Si ya conocemos el nombre en la posición index, lo imprimimos directamente
        if (names[index] != "?") {
            cout << names[index] << endl;
            continue;
        }

        // Buscar el nombre más cercano a la izquierda
        int leftDist = 0, rightDist = 0;
        string leftName = "", rightName = "";

        for (int j = index - 1; j >= 0; j--) {
            if (names[j] != "?") {
                leftName = names[j];
                break;
            }
            leftDist++;
        }

        // Buscar el nombre más cercano a la derecha
        for (int j = index + 1; j < numOfStudents; j++) {
            if (names[j] != "?") {
                rightName = names[j];
                break;
            }
            rightDist++;
        }

        // Determinar cómo referirse al estudiante en la posición index
        if (!leftName.empty() && !rightName.empty()) {
            if (leftDist < rightDist) {
                cout << "derecha " + " derecha de " << leftName << endl;
            } else if (rightDist < leftDist) {
                cout << string(rightDist, "izquierda ") + " izquierda de " << rightName << endl;
            } else {
                cout << "justo enmedio de " << leftName << " y " << rightName << endl;
            }
        } else if (!leftName.empty()) {
            cout << string(leftDist, "derecha ") + " derecha de " << leftName << endl;
        } else if (!rightName.empty()) {
            cout << string(rightDist, "izquierda ") + " izquierda de " << rightName << endl;
        }
    }

    return 0;
}
