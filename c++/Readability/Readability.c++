#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

int count_letters(const string &text) {
    int letters = 0;
    for (char c : text) {
        if (isalpha(c)) {
            letters++;
        }
    }
    return letters;
}

int count_words(const string &text) {
    int words = 0;
    bool in_word = false;

    for (char c : text) {
        if (isspace(c)) {
            if (in_word) {
                words++;
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }

    if (in_word) {
        words++;
    }

    return words;
}

int count_sentences(const string &text) {
    int sentences = 0;
    for (char c : text) {
        if (c == '.' || c == '!' || c == '?') {
            sentences++;
        }
    }
    return sentences;
}

int main() {
    string text;

    // Prompt user for input
    cout << "Text: ";
    getline(cin, text);

    // Count letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the Coleman-Liau index
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Output grade level
    if (index < 1) {
        cout << "Before Grade 1\n";
    } else if (index >= 16) {
        cout << "Grade 16+\n";
    } else {
        cout << "Grade " << round(index) << "\n";
    }

    return 0;
}
