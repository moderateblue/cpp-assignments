#include <iomanip>
#include "datavalidation.h"

using namespace std;

int main() {
    int speed, hours;

    speed = int_input("speed of vehicle in mph: ", 0);

    hours = int_input("hours the vehicle traveled: ", 1);

    cout << left << setw(20) << "Hour" << "Distance Traveled" << endl;
    cout << "---------------------------------------" << endl;

    if (hours == 0) {
        cout << left << setw(20) << 0 << 0 << endl;
    }

    for (int i = 1; i <= hours; i++) {
        cout << left << setw(20) << i << i * speed << endl;
    }

    return 0;
}