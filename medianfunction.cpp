#include "datavalidation.h"

using namespace std;

double median(int *arr, int size) {
    if (size % 2 == 0) {
        double med = (*(arr + (size/2 - 1)) + *(arr + (size/2))) / 2.0;
        cout << "if med: " << med << endl;
        return med;
    } else {
        double med = *(arr + size/2);
        cout << "else med: " << med << endl;
        return med;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {1, 2, 3, 4, 5, 7, 8};

    double arrMed = median(&arr[0], 8);
    double arr2Med = median(&arr2[0], 7);
    
    cout << arrMed << endl << arr2Med << endl;

    return 0;
}