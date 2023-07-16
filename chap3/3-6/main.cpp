#include <iostream>
#include <cstdlib>

using namespace std;

const int CIPHER_LETTERS_SIZE = 26;
const char PLAIN_ALPHABET[CIPHER_LETTERS_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char CIPHER_ALPHABET[CIPHER_LETTERS_SIZE];


int generateRandNum(int range) {
    srand(time(NULL));
    return rand() % range;
}


void createCipherAlphabet() {
    //Shuffle plain alphabet and check if letter in plain alph doent match with ciphered on the same position

}


int main() {
    createCipherAlphabet();
    return 0;
}