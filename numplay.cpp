//numplay-memory-game
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void wait(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

string generateRandomString(int length, int difficulty) {
    string digits = "0123456789";
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string special = "!@#$%^&*()-_=+<>?";

    string pool = digits;
    if (difficulty >= 2) pool += letters;
    if (difficulty >= 3) pool += special;

    string result = "";
    for (int i = 0; i < length; i++) {
        result += pool[rand() % pool.size()];
    }
    return result;
}

struct Player {
    string name;
    int score = 0;
    int attempts = 0;
    int correct = 0;
    int remainingChances = 3;
};

int main() {
    srand(time(0));

    cout << "===================================" << endl;
    cout << "   Welcome to NUMPLAY - A Memory Game" << endl;
    cout << "===================================" << endl;

    char mode;
    cout << "Play in Single (S) or Group (G) mode? ";
    cin >> mode;
    cin.ignore();

    vector<Player> players;
    if (mode == 'S' || mode == 's') {
        string name;
        cout << "Enter your name: ";
        getline(cin, name);
        players.push_back({name});
    } else if (mode == 'G' || mode == 'g') {
        int numPlayers;
        cout << "Enter number of players: ";
        cin >> numPlayers;
        cin.ignore();
        for (int i = 0; i < numPlayers; i++) {
            string pname;
            cout << "Enter name of player " << (i + 1) << ": ";
            getline(cin, pname);
            players.push_back({pname});
        }
    } else {
        cout << "Invalid choice. Exiting..." << endl;
        return 0;
    }

    int level = 1, difficulty = 1;
    bool playAgain = true;

    while (playAgain) {
        for (auto &p : players) {
            p.score = 0;
            p.attempts = 0;
            p.correct = 0;
            p.remainingChances = 3;
        }

        bool gameActive = true;
        while (gameActive) {
            gameActive = false; // will become true if at least one player has chances left

            for (auto &p : players) {
                if (p.remainingChances <= 0) continue; // skip if player is out

                gameActive = true;

                int length = (level / 3) + 3;
                if (level > 5) difficulty = 2;
                if (level > 10) difficulty = 3;

                string sequence = generateRandomString(length, difficulty);

                clearScreen();
                cout << "Player: " << p.name << endl;
                cout << "Memorize this sequence: " << sequence << endl;
                wait(3);

                clearScreen();
                string userInput;
                cout << p.name << ", enter the sequence: ";
                cin >> userInput;

                p.attempts++;

                if (userInput == sequence) {
                    cout << "Correct!" << endl;
                    p.score += 10;
                    p.correct++;
                } else {
                    p.remainingChances--;
                    if (p.remainingChances > 0) {
                        cout << "Wrong! You have " << p.remainingChances
                             << " chance(s) left.\nTry again next turn." << endl;
                    } else {
                        cout << "Wrong! You have no chances left.\n" << endl;
                    }
                }
                wait(2);
            }
            level++;
        }

        // Show final individual and group results
        clearScreen();
        cout << "\n===== Final Results =====\n";
        int groupScore = 0;
        for (auto &p : players) {
            double acc = (p.attempts > 0) ? (p.correct * 100.0 / p.attempts) : 0;
            cout << p.name << " → Score: " << p.score << " | Accuracy: " << acc << "%\n";
            if (p.score < 50)
                cout << "Keep practicing, " << p.name << "!\n";
            else if (p.score < 120)
                cout << "Impressive memory, " << p.name << "!\n";
            else
                cout << "Outstanding memory, " << p.name << "!\n";

            groupScore += p.score;
        }
        cout << "\nGroup Score: " << groupScore << endl;

        char choice;
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            playAgain = false;
    }

    cout << "\nThanks for playing NUMPLAY!" << endl;
    return 0;
}
