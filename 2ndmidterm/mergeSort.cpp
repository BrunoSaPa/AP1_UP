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


void sort(int* arr, int* temp, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    sort(arr, temp, left, mid);
    sort(arr, temp, mid + 1, right);
    merge(arr, temp, left, right);
}

int main() {
    int size = 10;
    int arr[10] = {33, 12, 67, 23, 645, 2, 788, 344, 99, 1};
    int result[10];

    sort(arr, result, 0, size - 1);

    //print
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    

    return 0;
}
