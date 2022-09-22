#include "PalindromeFinder.h"

int main() {

    string line;
    ifstream file;

    file.open("strings.txt");

    if (file.is_open()) {

        while (getline(file, line)) {
            int biggerPalindrome = IdentifyBiggerPalindrome(line);
            cout << "The bigger palindrome in " << line << " has size " << biggerPalindrome << "." << endl;
        }

        file.close();
    }
    else {
        cout << "Unable to open file";
    }

    return 0;
}

bool VerifyPalindrome(string word) {

    int wordLength = word.length();

    // Technically a letter alone would be a palindrome, but for this code we will consider words over 3 letters
    if (wordLength < 3)
        return false;

    for (size_t i = 0; i < wordLength / 2; i++)
    {
        if (word[i] != word[wordLength -i -1]) {
            return false;
        }
    }

    return true;
}

int IdentifyBiggerPalindrome(string word) {

    int biggerPalindromeSize = 0;
    int wordLength = word.length();

    for (size_t i = 0; i < wordLength; i++) {

        if (wordLength - i <= biggerPalindromeSize) {
            break;
        }

        for (size_t j = 0; j < wordLength - i; j++) {

            if (wordLength - i - j <= biggerPalindromeSize) {
                break;
            }

            if (VerifyPalindrome(word.substr(i, wordLength -i -j))) {
                biggerPalindromeSize = wordLength -i -j;
                break;
            }
        }
    }

    return biggerPalindromeSize;
}