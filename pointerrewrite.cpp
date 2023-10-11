#include "datavalidation.h"

using namespace std;

/*
int doSomething(int &x, int &y)
{
    int temp = x;
    x = y * 10;
    y = temp * 10;
    return x + y;
}
*/

int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

int median(int *arr, int size) {
    //thing
}

int main() {
    int num1, num2;
    num1 = int_input("First Number: ");
    num2 = int_input("Second Number: ");
    int *num3, *num4;
    num3 = &num1;
    num4 = &num2;
    cout << doSomething(num3, num4) << endl;

    return 0;
}