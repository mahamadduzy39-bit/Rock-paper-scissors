
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

int main() {
    srand(time(0));

    string choices[] = {"Rock", "Paper", "Scissors"};

    int wins = 0, losses = 0, draws = 0;

    cout << "============================\n";
    cout << "     ROCK PAPER SCISSORS\n";
    cout << "============================\n";

    while (true) {
        int player;

        cout << "\n1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";

        while (true) {
            cout << "Your choice: ";

            if (!(cin >> player)) {
                if (cin.eof()) return 0;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Please enter a number!\n";
                continue;
            }

            if (player >= 1 && player <= 3)
                break;

            cout << "Choose 1, 2, or 3!\n";
        }

        int computer = rand() % 3;

        cout << "\nYou chose: " << choices[player - 1];
        cout << "\nComputer chose: " << choices[computer];

        if (player - 1 == computer) {
            cout << "\nDraw!\n";
            draws++;
        }
        else if (
            (player == 1 && computer == 2) ||
            (player == 2 && computer == 0) ||
            (player == 3 && computer == 1)
        ) {
            cout << "\nYou win!\n";
            wins++;
        }
        else {
            cout << "\nComputer wins!\n";
            losses++;
        }

        cout << "\n--- SCOREBOARD ---\n";
        cout << "Wins: " << wins << "\n";
        cout << "Losses: " << losses << "\n";
        cout << "Draws: " << draws << "\n";

        char again;

        while (true) {
            cout << "\nPlay again? (y/n): ";
            cin >> again;

            if (again == 'y' || again == 'Y' ||
                again == 'n' || again == 'N')
                break;

            cout << "Enter y or n!\n";
        }

        if (again == 'n' || again == 'N')
            break;
    }

    cout << "\nThanks for playing!\n";
    cout << "Final wins: " << wins << "\n";
    cout << "Final losses: " << losses << "\n";
    cout << "Final draws: " << draws << "\n";

    return 0;
}
