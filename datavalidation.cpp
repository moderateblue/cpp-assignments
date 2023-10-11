#include "datavalidation.h"

using namespace std;

int int_input(string prompt, int lower, int upper) {
    cout << prompt;
    
    string response;
    getline(cin, response);

    int num = 0;

    try {
        int value = stoi(response);
        if (value < lower || value > upper) {
            throw runtime_error("invalid");
        } else {
            return value;
        }
    } catch (...) {
        cout << "invalid input, try again" << endl;
        num = int_input(prompt, lower, upper);
    }
    return num;
}

double double_input(string prompt, double lower, double upper) {
    cout << prompt;

    string response;
    getline(cin, response);

    double num = 0;

    try {
        double value = stod(response);
        if (value < lower || value > upper) {
            throw runtime_error("invalid");
        } else {
            return value;
        }
    } catch (...) {
        cout << "invalid input, try again" << endl;
        num = double_input(prompt, lower, upper);
    }
    return num;
}

string string_input(string prompt, string *options, int numOptions) {
    cout << prompt;

    string response;
    getline(cin, response);

    for (int i = 0; i < numOptions; i++) {
        if (response == options[i]) {
            return response;
        }
    }

    cout << "invalid response" << endl;
    response = string_input(prompt, options, numOptions);
    return response;
}

