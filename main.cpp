
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(0));

    string choices[] = {"Rock", "Paper", "Scissors"};

    int player, computer;
    char again;

    cout << "============================\n";
    cout << "   ROCK PAPER SCISSORS\n";
    cout << "============================\n";

    do {
        cout << "\nChoose your move:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Your choice: ";

        cin >> player;

        if (player < 1 || player > 3) {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        computer = rand() % 3;

        cout << "\nYou chose: " << choices[player - 1];
        cout << "\nComputer chose: " << choices[computer];

        if (player - 1 == computer) {
            cout << "\nResult: Draw!";
        }
        else if (
            (player == 1 && computer == 2) ||
            (player == 2 && computer == 0) ||
            (player == 3 && computer == 1)
        ) {
            cout << "\nResult: You win!";
        }
        else {
            cout << "\nResult: Computer wins!";
        }

        cout << "\n\nPlay again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for playing!\n";

    return 0;
}
