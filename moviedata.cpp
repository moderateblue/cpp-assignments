#include "datavalidation.h"

using namespace std;

struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime;
};

void printStruct(MovieData movie) {
    cout << "Movie Name: " << movie.title << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Release Year: " << movie.yearReleased << endl;
    cout << "Running Time: " << movie.runningTime << endl << endl;
}

int main() {
    MovieData amongus = {"Among Us", "Innersloth Lastname", 2018, 1140};
    MovieData amongus2 = {"Among Us 2", "Innersloth Lastname", 2020, 1200};

    printStruct(amongus);
    printStruct(amongus2);

    return 0;
}