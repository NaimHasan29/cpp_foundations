#include <iostream>
#include <ctime>   
#include <cstdlib> 

using namespace std;

int main() {
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    cout << "--- [Project 01: Number Guessing Game] ---" << endl;

    while (guess != secretNumber) {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You found the number!" << endl;
        }
    }

    return 0; 
}