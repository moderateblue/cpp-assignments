#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159

double radian(double degree) {
    double radian = degree * PI / 180;
    return radian;
}

int main() {
    int beta, slant;
    cout << "Enter beta in degrees: ";
    cin >> beta;
    cout << "Enter the slant distance (feet): ";
    cin >> slant;

    double alpha, chordL, radius;
    alpha = 90.0 - 0.5 * beta;
    chordL = slant * sin(radian(beta))/sin(radian(alpha));
    radius = chordL * sin(radian(90 - alpha)) / sin(radian(alpha * 2));

    cout << "Sandworm calculations" << endl;
    cout << "Beta: " << beta << " degrees" << endl;
    cout << "Slant distance: " << slant << " feet"<< endl;
    cout << setprecision(4) << fixed;
    cout << "Radius: " << radius << " feet" << endl;

    system("pause");
    return 0;
}