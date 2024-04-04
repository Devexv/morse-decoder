#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, char> morseCodeMap = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
    {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
    {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
    {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
    {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
    {"-.--", 'Y'}, {"--..", 'Z'},
    {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
    {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'},
    {"---..", '8'}, {"----.", '9'}
};

string decodeMorse(string morseCode) {
    string decodedMessage;
    string currentLetter;
    for (char c : morseCode) {
        if (c == ' ') {
            if (!currentLetter.empty()) {
                decodedMessage += morseCodeMap[currentLetter];
                currentLetter.clear();
            }
        } else {
            currentLetter += c;
        }
    }
    if (!currentLetter.empty()) {
        decodedMessage += morseCodeMap[currentLetter];
    }
    return decodedMessage;
}

int main() {
    string morseCode;
    cout << "Enter Morse code: ";
    getline(cin, morseCode);
    string decodedMessage = decodeMorse(morseCode);
    cout << "Decoded message: " << decodedMessage << endl;
    return 0;
}
