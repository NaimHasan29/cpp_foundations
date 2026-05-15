#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

int main() {
    char playAgain;
    do {
        srand(time(0));
        int secretNumber = rand() % 100 + 1;
        int guess = 0, attempts = 0;
        const int MAX_ATTEMPTS = 7; 
        
        cout << "\nNew Game! You have " << MAX_ATTEMPTS << " tries." << endl;

        while (guess != secretNumber && attempts < MAX_ATTEMPTS) {
            cout << "Attempt " << attempts + 1 << ": ";
            if (!(cin >> guess)) {
                cin.clear(); cin.ignore(1000, '\n');
                continue;
            }
            attempts++;
            if (guess == secretNumber) cout << "Correct! Amazing!" << endl;
            else if (guess > secretNumber) cout << "Too high!" << endl;
            else cout << "Too low!" << endl;
        }

        if (guess != secretNumber) cout << "Game Over! The number was " << secretNumber << endl;
        
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing, Md. Mubassirul Hasan Naim!" << endl;
    return 0;
}