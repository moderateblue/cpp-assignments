#include "datavalidation.h"
#include <float.h>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

double totalCharges(int days, double rate, double services, double medication) {
    double total = days * rate + medication + services;
    return total;
}

double totalCharges(double services, double medication) {
    double total = medication + services;
    return total;
}

int main() {
    string options[] = {"in-patient", "out-patient"};
    string option = string_input("Is this patient an \"in-patient\" or \"out-patient\"? ", options, 2);

    if (option == "in-patient") {
        int days = int_input("The number of days spent in the hospital: ", 0);
        double rate = double_input("The daily rate: $", 0, DBL_MAX);
        double medication = double_input("Hospital medication charges: $", 0);
        double services = double_input("Charges for hospital services (lab tests, etc.): $", 0);
        double total = totalCharges(days, rate, services, medication);
        cout << setprecision(2) << fixed << "Total charges: $" << total << endl;

        ofstream outfile;
        outfile.open("report.txt", ios_base::app);

        outfile << "This patient is an " << option << endl;
        outfile << "The number of days spent in the hospital: " << days << endl;
        outfile << "The daily rate: $" << setprecision(2) << fixed << rate << endl;
        outfile << "Hospital medication charges: $" << setprecision(2) << fixed << medication << endl;
        outfile << "Charges for hospital services (lab tests, etc.): $" << setprecision(2) << fixed << services << endl;
        outfile << "Total charges: $" << setprecision(2) << fixed << total << endl;
        outfile << endl;
        outfile.close();
    } else if (option == "out-patient") {
        double services = double_input("Charges for hospital services (lab tests, etc.): $", 0);
        double medication = double_input("Hospital medication charges: $", 0);
        double total = totalCharges(services, medication);
        cout << setprecision(2) << fixed << "Total charges: $" << total << endl;

        ofstream outfile;
        outfile.open("report.txt", ios_base::app);

        outfile << "This patient is an " << option << endl;
        outfile << "Hospital medication charges: $" << setprecision(2) << fixed << medication << endl;
        outfile << "Charges for hospital services (lab tests, etc.): $" << setprecision(2) << fixed << services << endl;
        outfile << "Total charges: $" << setprecision(2) << fixed << total << endl;
        outfile << endl;
        outfile.close();
    }

    return 0;
}