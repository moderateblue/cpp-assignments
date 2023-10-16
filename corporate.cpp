#include "datavalidation.h"
#include <map>
#include <iomanip>

using namespace std;

struct Data {
    string divisionName;
    map<int, double> quarterSales;
};

void write(Data division) {
    ofstream outfile;
    outfile.open("corporate.txt", ios::app);

    outfile << "Division Name: " << division.divisionName << endl;
    for(map<int, double>::iterator it = division.quarterSales.begin(); it != division.quarterSales.end(); ++it) {
        outfile << "Quarter " << it->first << ": $" << setprecision(2) << fixed << it->second << endl;
    }
    outfile << endl;
}

int main() {
    string divisions[] = {"n", "s", "w", "e"};

    Data divisionN = {"North"};
    Data divisionS = {"South"};
    Data divisionW = {"West"};
    Data divisionE = {"East"};

    for (int d = 0; d < 4; d++) {
        switch(d) {
            case 0:
                cout << "Division Name: North" << endl;
                break;
            case 1:
                cout << "Division Name: South" << endl;
                break;
            case 2:
                cout << "Division Name: West" << endl;
                break;
            case 3:
                cout << "Division Name: East" << endl;
                break;
        }

        for (int q = 1; q <= 4; q++) {
            string prompt = "Enter Quarter Sales for Quarter " + to_string(q) + ": ";
            double sales = double_input(prompt, 0);
            switch(d) {
                case 0:
                    divisionN.quarterSales[q] = sales;
                    break;
                case 1:
                    divisionS.quarterSales[q] = sales;
                    break;
                case 2:
                    divisionW.quarterSales[q] = sales;
                    break;
                case 3:
                    divisionE.quarterSales[q] = sales;
                    break;
            }
        }
    }

    write(divisionN);
    write(divisionS);
    write(divisionW);
    write(divisionE);

    return 0;
}