#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;

// To make the ciphertext problem even more challenging, have your pro-
// gram randomly generate the cipher array instead of a hard-coded const array.
// Effectively, this means placing a random character in each element of the
// array, but remember that you can’t substitute a letter for itself. So the first
// element can’t be A, and you can’t use the same letter for two substitutions—
// that is, if the first element is S, no other element can be S.


const int CIPHER_LETTERS_SIZE = 26;
const char PLAIN_ALPHABET[CIPHER_LETTERS_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char CIPHER_ALPHABET[CIPHER_LETTERS_SIZE];

void printMessage(vector<char> message) {
    for(int i = 0; i < message.size(); i++) {
        cout << message[i];
    }
    cout << "\n";
}

void printAlphabet(const char* arr) {
    for(int i = 0; i < CIPHER_LETTERS_SIZE; i++) {
        cout << arr[i];
    }
    cout << "\n";
} 

int generateRandNum(int range) {
    return rand() % range;
}

void initAlphabet(char* alphabet) {
    for(int i = 0; i < CIPHER_LETTERS_SIZE; i++) {
        alphabet[i] = PLAIN_ALPHABET[i];
    }
}

void swap(char* arr, int firstI, int secondI) {
    char temp = arr[firstI];
    arr[firstI] = arr[secondI];
    arr[secondI] = temp;
}


void shuffle(char* arr) {
    for(int i = CIPHER_LETTERS_SIZE - 1; i > 0; i--) {
        int j = generateRandNum(i);
        swap(CIPHER_ALPHABET, i, j);
    }
}

bool isDifferentFromPlain(char* arr) {
    for(int i = 0; i < CIPHER_LETTERS_SIZE; i++) {
        if(arr[i] == PLAIN_ALPHABET[i]) {
            return true;
        }
    }
    return false;
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
        if(CIPHER_ALPHABET[i] == letter) {
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
        (*message)[i] = CIPHER_ALPHABET[index];
    }
}

void decipherMessage(vector<char>* message) {
      for(int i = 0; i < (*message).size(); i++) {
        int index = findOriginalLetterIndex((*message)[i]);
        if (index == -1) {continue;}
        (*message)[i] = PLAIN_ALPHABET[index];
    }
}


void createCipherAlphabet() {
    //Shuffle plain alphabet and check if letter in plain alph doent match with ciphered on the same position
    initAlphabet(CIPHER_ALPHABET);
    while(isDifferentFromPlain(CIPHER_ALPHABET)) {
        shuffle(CIPHER_ALPHABET);
    }
}


int main() {
    srand(time(NULL));
    createCipherAlphabet();
    cout << "P Alphabet: ";
    printAlphabet(PLAIN_ALPHABET);
    cout << "C Alphabet: ";
    printAlphabet(CIPHER_ALPHABET);

    
    vector<char> message;
    message.reserve(50);
    cout << "Enter message: ";
    char letter = cin.get();
    while (letter != 10)
    {
        message.push_back(letter);
        letter = cin.get();
    }
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