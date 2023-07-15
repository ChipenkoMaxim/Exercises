#include <iostream>
#include <vector>

using namespace std;

const int CYPHER_LETTERS_SIZE = 26;
const char CYPHER_LETTERS[CYPHER_LETTERS_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void printMessage(vector<char> message) {
    for(int i = 0; i < message.size(); i++) {
        cout << message[i];
    }
    cout << "\n";
}

int findLetterIndex(char letter) {
    int index = -1;
    for(int i = 0; i < CYPHER_LETTERS_SIZE; i++) {
        if(CYPHER_LETTERS[i] == letter) {
            index = i;
            break;
        }
    }
    return index;
}


void cypherMessage(vector<char>* message) {
    for(int i = 0; i < (*message).size(); i++) {
        int index = findLetterIndex((*message)[i]);
        if(index == -1) {continue;}
        (*message)[i] = CYPHER_LETTERS[(index + 10) % 26];
        // index = findLetterIndex((*message)[i]);
        // if(index - 10 < 0) { (*message)[i] = CYPHER_LETTERS[(26 - abs(index - 10)) % 26];}
        // else {(*message)[i] = CYPHER_LETTERS[(index - 10) % 26];}
    }
}


int main() {
    vector<char> message;
    message.reserve(50);
    cout << "Enter message: ";
    char letter = cin.get();
    while (letter != 10)
    {
        message.push_back(letter);
        letter = cin.get();
    }
    cout << "\n";
    cout << "Original message is: ";
    printMessage(message);
    

    cypherMessage(&message);
    cout << "Cyphered message is: ";
    printMessage(message);
    return 0;
}