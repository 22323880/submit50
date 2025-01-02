#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to calculate the score of a word
int calculateScore(const string &word) {
    // Points corresponding to each letter
    int points[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
    };
    
    int score = 0;
    for (char c : word) {
        if (isalpha(c)) {
            c = tolower(c); // Convert character to lowercase
            score += points[c - 'a']; // Add points for the letter
        }
    }
    return score;
}

int main() {
    string player1Word, player2Word;

    // Get words from players
    cout << "Player 1: ";
    getline(cin, player1Word);

    cout << "Player 2: ";
    getline(cin, player2Word);

    // Calculate scores
    int score1 = calculateScore(player1Word);
    int score2 = calculateScore(player2Word);

    // Determine the winner
    if (score1 > score2) {
        cout << "Player 1 wins!" << endl;
    } else if (score2 > score1) {
        cout << "Player 2 wins!" << endl;
    } else {
        cout << "Tie!" << endl;
    }

    return 0;
}