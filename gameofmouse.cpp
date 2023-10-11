#include "datavalidation.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int roll() {
    return (rand() % 6 + 1);
}

int main(int argc, char *argv[]) {
    if (argc == 1) srand(time(NULL));

    int mScore = 0, uScore = 0, mTurn = 0, uTurn = 0;
    int dice = 1;
    bool pTurn = true;
    int winner = 0; //1 for player, 2 for computer
    string name;
    int holdOn = 0;
    int round = 1;
    string choices[] = {"h", "r"};

    cout << "Welcome to the Dice Game Mouse\nEnter game information:\nWhat is your name? ";
    getline(cin, name);
    holdOn = int_input("Computer Strategy, hold on X points? ", 0, 100);
    cout << "\n-----------------------------------" << endl;

    while (mScore < 100 && uScore < 100) {
        cout << "Round " << round << endl;
        if (pTurn == true) cout << name << setw(20) << "Current Score: " << uScore << endl << endl;

        dice = roll();
        if (dice == 1) {
            pTurn = false;
            uTurn = 0;
            cout << "Roll -> " << dice << " Turn Total: " << uTurn << endl;
            cout << "Player loses turn and points\n" << endl;
        } else {
            uTurn += dice;
            cout << "Roll -> " << dice << " Turn Total: " << uTurn;
        }

        while (pTurn) {
            cout << setw(3) << "";
            string choice = string_input("Play (h = hold, r = roll)? ", choices, 2);
            if(choice == "r") {
                dice = roll();
                if (dice == 1) {
                    pTurn = false;
                    uTurn = 0;
                    cout << "Roll -> " << dice << " Turn Total: " << uTurn << endl;
                    cout << "Player loses turn and points\n" << endl;
                } else {
                    uTurn += dice;
                    cout << "Roll -> " << dice << " Turn Total: " << uTurn;
                    if ((uScore + uTurn) >= 100) {
                        uScore += uTurn;
                        winner = 1;
                        break;
                    }
                }
            } else {
                cout << endl;
                uScore += uTurn;
                pTurn = false;
                uTurn = 0;
            }
        }

        if (winner == 1) {
            cout << "\n\nGame Over\n" << endl;
            cout << "***********************************" << endl;
            cout << "Scores" << endl;
            cout << "Computer: " << setw(3) << mScore << endl;
            cout << name << ": " << setw(3) << uScore << endl << endl;
            cout << name << " wins!" << endl;
            break;
        }

        if (pTurn == false) {
            cout << "-----------------------------------" << endl;
            cout << "Computer" << setw(20) << "Current Score: " << mScore << endl << endl;
        }

        while (!pTurn) {
            if (mTurn < holdOn) {
                dice = roll();
                if (dice == 1) {
                    pTurn = true;
                    mTurn = 0;
                    cout << "Roll -> " << dice << " Turn Total: " << mTurn << endl;
                } else {
                    mTurn += dice;
                    //cout << "considering" << endl;
                    cout << "Roll -> " << dice << " Turn Total: " << mTurn << endl;
                    if ((mScore + mTurn) >= 100) {
                        mScore += mTurn;
                        winner = 2;
                        break;
                    }
                }
            } else {
                //cout << "holding" << endl;
                mScore += mTurn;
                pTurn = true;
                mTurn = 0;
            }
        }

        if (winner == 2) {
            cout << "\n\nGame Over\n" << endl;
            cout << "***********************************" << endl;
            cout << "Scores" << endl;
            cout << "Computer: " << setw(3) << mScore << endl;
            cout << name << ": " << setw(3) << uScore << endl << endl;
            cout << "Computer wins!" << endl;
            break;
        }

        cout << "\n<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << "Current Standings" << endl;
        cout << "Computer: " << setw(3) << mScore << setw(15) << name << ": " << setw(3) << uScore << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n" << endl;

        round++;
    }

    return 0;
}