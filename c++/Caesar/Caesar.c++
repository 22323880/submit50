#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to shift a single character by 1 position
char shift_char(char c) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return (c - base + 1) % 26 + base;
    }
    return c;
}

int main() {
    // Prompt the user for the key (even though it won't be used)
    int key;
    cout << "Enter key (a non-negative integer): ";
    cin >> key;

    // Clear the input buffer
    cin.ignore();

    // Prompt the user for plaintext
    string plaintext;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    // Encipher the plaintext (shift each letter by 1 position)
    string ciphertext;
    for (char c : plaintext) {
        ciphertext += shift_char(c);
    }

    // Output the ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}