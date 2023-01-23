#include <iostream>
#include <cstdlib>
#include <ctime>

const int NUM_REELS = 3;
const int NUM_SYMBOLS = 5;

std::string symbols[NUM_SYMBOLS] = { "cherry", "lemon", "orange", "plum", "bell" };

void spinReels(int reels[NUM_REELS]) {
    srand(time(0));
    for (int i = 0; i < NUM_REELS; i++) {
        reels[i] = rand() % NUM_SYMBOLS;
    }
}

void printReels(int reels[NUM_REELS]) {
    std::cout << "Spinning..." << std::endl;
    for (int i = 0; i < NUM_REELS; i++) {
        std::cout << symbols[reels[i]] << " ";
    }
    std::cout << std::endl;
}

bool checkWin(int reels[NUM_REELS]) {
    if (reels[0] == reels[1] && reels[1] == reels[2]) {
        return true;
    }
    return false;
}

int main() {
    int balance = 10;
    int bet = 0;
    int reels[NUM_REELS];

    std::cout << "Welcome to the Slot Machine!" << std::endl;
    std::cout << "You have $" << balance << std::endl;

    while (balance > 0) {
        std::cout << "How much would you like to bet? (Enter 0 to quit) ";
        std::cin >> bet;

        if (bet == 0) {
            break;
        }
        if (bet > balance) {
            std::cout << "You do not have enough money. Please enter a lower amount." << std::endl;
            continue;
        }

        balance -= bet;

        spinReels(reels);
        printReels(reels);

        if (checkWin(reels)) {
            std::cout << "Congratulations! You won $" << bet * 2 << "!" << std::endl;
            balance += bet * 2;
        } else {
            std::cout << "Sorry, try again." << std::endl;
        }

        std::cout << "You have $" << balance << std::endl;
    }

    std::cout << "Thanks for playing!" << std::endl
