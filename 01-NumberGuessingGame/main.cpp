#include <iostream>
#include <ctime>   
#include <cstdlib> 
#include <limits>
#include <fstream>

using namespace std;

int loadHighScore() {
    ifstream infile("highscore.txt");
    int record = 999;
    if (infile >> record) {
        return record;
    }
    return 999; 
}

void saveHighScore(int newRecord) {
    ofstream outfile("highscore.txt");
    if (outfile.is_open()) {
        outfile << newRecord;
    }
}

int main() {
    char playAgain;
    
    cout << "--- Number Guessing Game ---" << endl;
    
    do {
        srand(time(0)); 
        int difficulty = 0;
        int maxNumber = 100;
        int maxAttempts = 7;

        cout << "\nSelect Difficulty:\n";
        cout << "1. Easy (1-50, 10 Tries)\n";
        cout << "2. Medium (1-100, 7 Tries)\n";
        cout << "3. Hard (1-500, 5 Tries)\n";
        cout << "Enter choice (1-3): ";
        
        while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3) {
            cout << "Invalid! Enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (difficulty == 1) {
            maxNumber = 50;
            maxAttempts = 10;
        } else if (difficulty == 2) {
            maxNumber = 100;
            maxAttempts = 7;
        } else {
            maxNumber = 500;
            maxAttempts = 5;
        }

        int bScore = loadHighScore();
        if (bScore != 999) {
            cout << "\nBest Score: " << bScore << " tries" << endl;
        } else {
            cout << "\nNo high score set yet!" << endl;
        }

        int secretNumber = rand() % maxNumber + 1;
        int guess = 0;
        int attempts = 0;
        
        cout << "Guess the number between 1 and " << maxNumber << " (" << maxAttempts << " tries left):" << endl;

        while (guess != secretNumber && attempts < maxAttempts) {
            cout << "Take a guess: ";
            
            if (!(cin >> guess)) {
                cout << "Invalid input. Enter a number." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; 
            }
            
            attempts++;
            
            if (guess == secretNumber) {
                cout << "Correct! You won in " << attempts << " tries." << endl;
                if (attempts < bScore) {
                    cout << "New High Score!" << endl;
                    saveHighScore(attempts);
                }
            } else if (guess > secretNumber) {
                cout << "Too high!" << endl;
            } else {
                cout << "Too low!" << endl;
            }
        }
        
        if (guess != secretNumber) {
            cout << "Game Over! The number was " << secretNumber << endl;
        }
        
        cout << "Play again? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Goodbye!" << endl;
    return 0;
}