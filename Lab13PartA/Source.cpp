#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

void pressEnterToContinue();
void letterFrequencyAnalysis(const string& filePath);

int main() {
    string fileName;
    cout << "Enter filename: ";
    getline(cin, fileName);
    letterFrequencyAnalysis(fileName);
    pressEnterToContinue();
    return 0;
}

void pressEnterToContinue(void) {
    char c;
    cout << "Press Enter to continue...";
    cin.ignore(1024, '\n');
    do { cin.get(c); } while (c != '\n' && c != EOF);
    return;
}

void letterFrequencyAnalysis(const string& filePath) {
    ifstream file(filePath);
    unordered_map<char, int> frequencies;

    if (file.is_open()) {
        char c;
        while (file >> c) {
            // Convert character to uppercase
            c = toupper(c);
            // Check if the character is a letter
            if (isalpha(c)) {
                // Increment the frequency count for the letter
                frequencies[c]++;
            }
        }
        file.close();

        // Print the total number of letters
        int totalLetters = 0;
        for (const auto& pair : frequencies) {
            totalLetters += pair.second;
        }
        cout << "Total number of letters: " << totalLetters << endl;

        // Print the letter frequencies in uppercase and alphabetically
        cout << "Frequency:" << endl;
        cout << fixed << setprecision(3);
        for (char letter = 'A'; letter <= 'Z'; ++letter) {
            int count = frequencies[letter];
            double percentage = static_cast<double>(count) / totalLetters * 100;
            cout << "'" << letter << "': " << percentage << endl;
        }
    }
    else {
        cerr << "Unable to open file: " << filePath << endl;
    }
}