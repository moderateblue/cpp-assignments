#include "datavalidation.h"
#include <map>
#include <vector>

using namespace std;

void sort(double *rain, string *months) {
    for (int i = 1; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (rain[i] < rain[j]) {
                double temp;
                string tempM;
                temp = rain[j];
                tempM = months[j];
                rain[j] = rain[i];
                months[j] = months[i];
                rain[i] = temp;
                months[i] = tempM;
            }
        }
    }
}

int main() {
    double rain[12];
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    map<string, int> monthsMap;
    
    int min, max;
    double total = 0;
    int minCount[12] = {}, maxCount[12] = {};

    for (int i = 0; i < 12; i++) {
        rain[i] = double_input("Enter the rainfall amount for " + months[i] + ": ", 0);
        monthsMap[months[i]] = rain[i];
        if (i == 0) {
            min = i;
            max = i;
        }

        if (rain[i] < rain[min]) {
            fill(minCount, minCount + 12, 0);
            min = i;
        }
        if (rain[i] == rain[min]) {
            minCount[i] = 1;
        }
        if (rain[i] > rain[max]) {
            fill(maxCount, maxCount + 12, 0);
            max = i;
        }
        if (rain[i] == rain[max]) {
            maxCount[i] = 1;
        }

        total += rain[i];
    }

    cout << endl;
    cout << "total rainfall for the year: " << total << endl;
    cout << "average rainfall for each month: " << (total/12) << endl;
    if (min == max && rain[max] == 0) {
        cout << "no month with highest or lowest rainfalls" << endl;
    } else {
        cout << "month(s) with the highest rainfall: ";
        for (int i = 0; i < 12; i++) {
            string month = (maxCount[i] > 0) ? (months[i] + " ") : ("");
            cout << month;
        }
        cout << endl;
        cout << "month(s) with the lowest rainfall: ";
        for (int i = 0; i < 12; i++) {
            string month = (minCount[i] > 0) ? (months[i] + " ") : ("");
            cout << month;
        }
    }

    cout << endl << endl;

    sort(rain, months);
    for (int i = 0; i < 12; i++) {
        cout << months[i] << ": " << rain[i] << endl;
    }

    return 0;
}