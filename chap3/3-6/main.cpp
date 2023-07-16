#include <iostream>
#include <cstdlib>

using namespace std;

const int CIPHER_LETTERS_SIZE = 26;
const char PLAIN_ALPHABET[CIPHER_LETTERS_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char CIPHER_ALPHABET[CIPHER_LETTERS_SIZE];

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


void createCipherAlphabet() {
    //Shuffle plain alphabet and check if letter in plain alph doent match with ciphered on the same position
    initAlphabet(CIPHER_ALPHABET);
    //printAlphabet(CIPHER_ALPHABET);
    for(int i = CIPHER_LETTERS_SIZE - 1; i > 0; i--) {
        int j = generateRandNum(i);
        swap(CIPHER_ALPHABET, i, j);
    }
}


int main() {
    srand(time(NULL));
    createCipherAlphabet();
    printAlphabet(CIPHER_ALPHABET);
    return 0;
}