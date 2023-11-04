#include "datavalidation.h"

using namespace std;

int* shift(int arr[], int size) {
    //array = pointer to array first element
    int* newArr = new int[size + 1];

    newArr[0] = 0;

    for (int i = 0; i < size + 1; i++) {
        newArr[i + 1] = arr[i];
    }

    arr = newArr;
    //cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    return arr;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* newArr = shift(arr, 5);

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < 6; i++ ) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] newArr;

    return 0;
}