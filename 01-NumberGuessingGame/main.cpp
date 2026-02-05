#include <iostream>
#include <ctime>   
#include <cstdlib> 

using namespace std;

int main() {
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1; 

    cout << "--- [Project 01: Number Guessing Game] ---" << endl;
    cout << "I have chosen a number. Try to guess it!" << endl;

    return 0;
}