#include <iostream>
using namespace std;

void merge(int* arr, int* temp, int left, int right) {
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int* arr, int* temp, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, right);
}


int average(int* arr, int size) {
    if (size == 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int nOfTest, ncs, ne;
    int cs[100], e[100], aux[100];
    int count = 0;
    
    cin >> nOfTest;


    for(int i=0; i<nOfTest; i++){
    count = 0;
    cin >> ncs >> ne;

    for (int i = 0; i < ncs; i++) {
        cin >> cs[i];
    }
    for (int i = 0; i < ne; i++) {
        cin >> e[i];
    }

    mergeSort(cs, aux, 0, ncs - 1);
    mergeSort(e, aux, 0, ne - 1);

    for (int i = 0; i < ncs; i++) {
            if ((cs[i] > e[0]) && (cs[i] <= cs[0])) {
                count++;
            }
        }
        cout << count;
    }

    return 0;
}
