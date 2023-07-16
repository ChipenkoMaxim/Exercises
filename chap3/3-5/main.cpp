#include <iostream>
#include <vector>

using namespace std;

// Have the previous program convert the ciphertext back to the plaintext to
// verify the encoding and decoding.


const int CIPHER_LETTERS_SIZE = 26;
const char PLAIN_ALPHABET[CIPHER_LETTERS_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char CIPHER_LETTERS[CIPHER_LETTERS_SIZE] = {'N', 'B', 'A', 'J', 'Y', 'F', 'O', 'W', 'L', 'Z', 'M', 'P', 'X', 'I', 'K', 'U', 'V', 'C', 'D', 'E', 'G', 'R', 'Q', 'S', 'T', 'H'};

void printMessage(vector<char> message) {
    for(int i = 0; i < message.size(); i++) {
        cout << message[i];
    }
    cout << "\n";
}

int findCipherLetterIndex(char letter) {
    int index = -1;
    for(int i = 0; i < CIPHER_LETTERS_SIZE; i++) {
        if(PLAIN_ALPHABET[i] == letter) {
            index = i;
            break;
        }
    }
    return index;
}

int findOriginalLetterIndex(char letter) {
    int index = -1;
    for(int i = 0; i < CIPHER_LETTERS_SIZE; i++) {
        if(CIPHER_LETTERS[i] == letter) {
            index = i;
            break;
        }
    }
    return index;
}


void cipherMessage(vector<char>* message) {
    for(int i = 0; i < (*message).size(); i++) {
        int index = findCipherLetterIndex((*message)[i]);
        if (index == -1) {continue;}
        (*message)[i] = CIPHER_LETTERS[index];
    }
}

void decipherMessage(vector<char>* message) {
      for(int i = 0; i < (*message).size(); i++) {
        int index = findOriginalLetterIndex((*message)[i]);
        if (index == -1) {continue;}
        (*message)[i] = PLAIN_ALPHABET[index];
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
    

    cipherMessage(&message);
    cout << "Cyphered message is: ";
    printMessage(message);

    cout << "Deciphered message is: ";
    decipherMessage(&message);
    printMessage(message);

    return 0;
}