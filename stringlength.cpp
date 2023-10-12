#include "datavalidation.h"

using namespace std;

int func(string *input) {
    return (*input).length();
}

int main() {
    string in;
    cout << "input a string: ";
    getline(cin, in);

    cout << func(&in) << endl;

    return 0;
}