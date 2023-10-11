#include <iostream>

using namespace std;

int main() {
    int num;

    cout << "Input a number: ";
    cin >> num;
    
    cin.fail() ? num = -1 : 0;

    (num >= 0) && (num <= 100) ? cout << "The number is valid" : cout << "The number is not valid";

    return 0;
}