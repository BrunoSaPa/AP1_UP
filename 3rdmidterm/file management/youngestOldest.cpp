//solamente como nota, el programa no tiene en cuenta los años bisiestos y fue hecho en mac, por si algun problema pasara con los archivos al momento de revisión, tener eso en consideración :)

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int normalizeYear(int yy);
bool isYounger(int d1, int m1, int y1, int d2, int m2, int y2);
bool isOlder(int d1, int m1, int y1, int d2, int m2, int y2);
bool isNextBirthday(int d1, int m1, int y1, int d2, int m2, int y2, int currentDay, int currentMonth);



int main() {
    int fileCount = 100;

    string youngestName, oldestName, nextName;
    int youngestDay = 0, youngestMonth = 0, youngestYear = 0;
    int oldestDay = 0, oldestMonth = 0, oldestYear = 0;
    int nextYear = 0, nextMonth = 0, nextDay = 0;
    int currentYear = 0, currentMonth = 0, currentDay = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    currentMonth = 1 + ltm->tm_mon;
    currentDay = ltm->tm_mday;
    bool first = true;
    int monthSelected = 0;

    cout << "In which month are you looking for birthdays? (1-12): ";
    cin >> monthSelected;


    for (int i = 1; i <= fileCount; ++i) {
        ifstream file;
        if(i<=9) {
            file.open("0" + to_string(i) + ".txt");
        } else {
            file.open(to_string(i) + ".txt");
        }


        if (!file) {
            continue;
        }

        string name;
        getline(file, name);        

        int d, m, y;
        file >> d >> m >> y;
        y = normalizeYear(y);


        //check if the birthday is this month
        if (monthSelected == m) {
            cout << "Birthday in the month number " << monthSelected << ": ";
            cout << name;
            cout << endl;
        }

        if (first) {
            youngestName = oldestName = nextName = name;
            youngestDay = oldestDay = nextDay = d;
            youngestMonth = oldestMonth = nextMonth = m;
            youngestYear = oldestYear = nextYear = y;
            first = false;
        } else {
            if (isYounger(d, m, y, youngestDay, youngestMonth, youngestYear)) {
                youngestName = name;
                youngestDay = d; youngestMonth = m; youngestYear = y;
            }
            if (isOlder(d, m, y, oldestDay, oldestMonth, oldestYear)) {
                oldestName = name;
                oldestDay = d; oldestMonth = m; oldestYear = y;
            }
            if (isNextBirthday(d, m, y, nextDay, nextMonth, nextYear, currentDay, currentMonth)) {
                nextName = name;
                nextDay = d; nextMonth = m; nextYear = y;
            }
        }
    }

    cout << "Oldest: " << oldestName << " (" << oldestDay << "/" << oldestMonth << "/" << oldestYear << ")\n";
    cout << "Youngest: " << youngestName << " (" << youngestDay << "/" << youngestMonth << "/" << youngestYear << ")\n";
    cout << "Next birthday: " << nextName << " (" << nextDay << "/" << nextMonth << "/" << nextYear << ")\n";
              

    return 0;
}

int normalizeYear(int yy) {
    return (yy <= 24) ? (2000 + yy) : (1900 + yy);
}

bool isYounger(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 != y2) return y1 > y2;
    if (m1 != m2) return m1 > m2;
    return d1 > d2;
}

bool isOlder(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 != y2) return y1 < y2;
    if (m1 != m2) return m1 < m2;
    return d1 < d2;
}

//count for amount of days in each month
int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int dayOfYear(int day, int month) {
    int total = 0;
    for (int i = 0; i < month - 1; ++i) {
        total += daysInMonth[i];
    }
    return total + day;
}


//it wss needed to check if the next birthday went to the next year
bool isNextBirthday(int d1, int m1, int y1, int d2, int m2, int y2, int currentDay, int currentMonth) {
    int currDOY = dayOfYear(currentDay, currentMonth);
    int b1DOY = dayOfYear(d1, m1);
    int b2DOY = dayOfYear(d2, m2);

    int daysUntilB1 = (b1DOY >= currDOY) ? (b1DOY - currDOY) : (365 - currDOY + b1DOY);
    int daysUntilB2 = (b2DOY >= currDOY) ? (b2DOY - currDOY) : (365 - currDOY + b2DOY);

    return daysUntilB1 < daysUntilB2;
}
