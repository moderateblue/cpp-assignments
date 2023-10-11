#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string name;
    cout << "Name of Movie: ";
    getline(cin, name);

    int adult, child;
    cout << "How many adult tickets were sold? ";
    cin >> adult;
    cin.ignore();
    cout << "How many child tickets were sold? ";
    cin >> child;
    cin.ignore();
    cout << "\n";

    double total = adult * 6 + child * 3;
    double net = total * 0.2;

    cout << left << setprecision(2) << fixed;
    cout << setw(50) << "Movie Name:" << "\"" << name << "\"" << endl;
    cout << setw(50) << "Adult Tickets Sold: " << adult << endl;
    cout << setw(50) << "Child Tickets Sold: " << child << endl;
    cout << setw(50) << "Gross Box Office Profit: " << "$" << total << endl;
    cout << setw(50) << "Net Box Office Profit: " << "$" << net << endl;
    cout << setw(50) << "Amount Paid to Distributor: " << "$" << total - net << endl;

    return 0;
}
