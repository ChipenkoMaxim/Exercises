#include <iostream>

using namespace std;

int main() {

    int numberOfWords = 0;
    int longestLength = 0;
    int greatestNumbOfVowels = 0;

    char letter = cin.get();
    int currVowels = 0;
    int currLength = 0;

    while (letter != 10) 
    {
        if(currLength > 0 && (letter == ',' || letter == '.' || letter == ' ')) {
            if(currLength > longestLength) {
                longestLength = currLength;
            }
            if(currVowels > greatestNumbOfVowels) {
                greatestNumbOfVowels = currVowels;
            }
            currVowels = 0;
            currLength = 0;
            numberOfWords++;
        } else if(letter == 'a' || letter == 'e' || letter == 'o' || letter == 'y' || letter == 'u' ||
        letter == 'i') {
            currVowels++;
            currLength++;
        } else {
            currLength++;
        }
        letter = cin.get();
    }
    cout << "Number of Words = " << numberOfWords << endl
    << "Longest length = " << longestLength << endl
    << "Greatest Number of Vowels = " << greatestNumbOfVowels << endl;
    
    return 0;
}