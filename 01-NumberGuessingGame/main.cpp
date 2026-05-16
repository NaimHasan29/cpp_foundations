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
    int bestSessionScore = loadHighScore();
    
    cout << "--- Number Guessing Game ---" << endl;
    if (bestSessionScore != 999) {
        cout << "All-time Personal Best: " << bestSessionScore << " tries" << endl;
    } else {
        cout << "No record found. Set your personal best this round!" << endl;
    }
    
    do {
        srand(time(0)); 
        int secretNumber = rand() % 100 + 1;
        int guess = 0;
        int attempts = 0;
        const int MAX_ATTEMPTS = 7; 
        
        cout << "\nNew Game! You have " << MAX_ATTEMPTS << " tries." << endl;

        while (guess != secretNumber && attempts < MAX_ATTEMPTS) {
            cout << "Attempt " << attempts + 1 << ": Enter your guess (1-100): ";
            
            if (!(cin >> guess)) {
                cout << "Invalid input! Enter a number." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; 
            }
            
            attempts++;
            
            if (guess == secretNumber) {
                cout << "Correct! You win!" << endl;
                
                if (attempts < bestSessionScore) {
                    cout << "New Record! You beat the old high score!" << endl;
                    bestSessionScore = attempts;
                    saveHighScore(bestSessionScore);
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
    
    cout << "Thanks for playing!" << endl;
    return 0;
}