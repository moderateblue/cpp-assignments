#include <bits/stdc++.h>

int main() {
    std::random_device rd;     // Only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)

    std::cout << "Enter two numbers to be the bottom and top limit (including): ";
    int min, max;
    std::cin >> min >> max;

    std::uniform_int_distribution<int> uni(min,max); // Guaranteed unbiased

    auto random_integer = uni(rng);

    int guess, tries = 0;

    //std::cout << min << " " << max << std::endl;
    //std::cout << random_integer << std::endl;

    while(guess != random_integer) {
        std::cout << "guess number: ";
        std::cin >> guess;
        if (guess > random_integer) {
            std::cout << "too high\n";
        } else if (guess < random_integer) {
            std::cout << "too low\n";
        }
        tries++;
    }

    std::cout << "you win!!11!111\n";
    std::cout << "it took you " << tries << " tries!1111" << std::endl;

    //g++ C:\Users\theam\Desktop\C++\numberguesser.cpp

    system("pause");
    return 0;
}