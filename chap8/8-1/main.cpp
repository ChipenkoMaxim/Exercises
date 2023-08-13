#include <iostream>
using std::cin;
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <list>
using std::list;
using std::iterator;
#include <cstring>

// Write a complete implementation for the cheating hangman problem that’s
// better than mine.

void displayGuessedLetters(bool letters[26]) {
    cout << "Letters guessed: ";
    for (int i = 0; i < 26; i++) {
        if (letters[i]) cout << (char)('a' + i) << " ";
    }
    cout << "\n";
}

void removeWordsWithoutLetter(list<string> & wordList, char requiredLetter) {
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(requiredLetter) == string::npos) {
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void removeWordsWithLetter(list<string> & wordList, char forbiddenLetter) {
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(forbiddenLetter) != string::npos) {
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

bool numberInPattern(const list<int> & pattern, int number) {
    list<int>::const_iterator iter;
    iter = pattern.begin();
    while (iter != pattern.end()) {
        if (*iter == number) {
            return true;
        }
        iter++;
    }
    return false;
}

bool matchesPattern(string word, char letter, list<int> pattern) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            if (!numberInPattern(pattern, i)) {
                return false;
            }
        } else {
            if (numberInPattern(pattern, i)) {
                return false;
            }
        }
    }
    return true;
}

void mostFreqPatternByLetter(list<string> wordList, char letter, list<int> & maxPattern, int & maxPatternCount) {
    removeWordsWithoutLetter(wordList, letter);
    list<string>::iterator iter;
    maxPatternCount = 0;
    while (wordList.size() > 0) {
        iter = wordList.begin();
        list<int> currentPattern;
        for (int i = 0; i < iter->length(); i++) {
            if ((*iter)[i] == letter) {
                currentPattern.push_back(i);
            }
        }
        int currentPatternCount = 1;
        iter = wordList.erase(iter);
        while (iter != wordList.end()) {
            if (matchesPattern(*iter, letter, currentPattern)) {
                currentPatternCount++;
                iter = wordList.erase(iter);
            } else {
                iter++;
            }
        }
        if (currentPatternCount > maxPatternCount) {
            maxPatternCount = currentPatternCount;
            maxPattern = currentPattern;
        }
        currentPattern.clear();
    }
}

void removeWordsOfWrongLength(list<string> & wordList, int acceptableLength) {
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->length() != acceptableLength) {
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

int countWordsWithoutLetter(const list<string> & wordList, char letter) {
    list<string>::const_iterator iter;
    int count = 0;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(letter) == string::npos) {
            count++;
        }
        iter++;
    }
    return count;
}

void displayList(const list<string>& wordList) {
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        cout << iter->c_str() << "\n";
        iter++;
    }
}

list<string> readWordFile(const char * filename) {
    list<string> wordList;
    ifstream wordFile(filename, ios::in);
    if (!wordFile.is_open()) {
        cout << "File open failed. \n";
        return wordList;
    }
    char currentWord[30];
    while (wordFile >> currentWord) {
        if (strchr(currentWord, '\'') == 0) {
            string temp(currentWord);
            wordList.push_back(temp);
        }
    }
    return wordList;
}

list<string> reduceByPattern(list<string> words, char letter, list<int> reducedPattern) {
    list<string> newWords;
    list<string>::iterator iter = words.begin();
    while (iter != words.end())
    {
        if(matchesPattern(*iter, letter, reducedPattern)) {
            newWords.push_back(*iter);
        } else {
            //skip that word
        }
        iter++;
    }
    return newWords;
}

bool isSymbolValidNumber(char symbol) {
    return symbol > '0' && symbol <= '9';
}


void setUpLengthOfWordToGuess(int& wordLength) {
    cout << "Enter length of word to guess in range from 1 to 9: ";
    char promptedSymbol;
    cin >> promptedSymbol;
    while (!isSymbolValidNumber(promptedSymbol))
    {
        cout << "\nWrong value for length of word, try again: ";
        cin >> promptedSymbol;
    }
    wordLength = promptedSymbol - '0';
}


void setUpMaxMissesAmount(int& maxMisses) {
    cout << "Enter number of wrong attempts in range from 1 to 9: ";
    char promptedSymbol;
    cin >> promptedSymbol;
    while (!isSymbolValidNumber(promptedSymbol))
    {
        cout << "\nWrong value for number of wrong attempts, try again: ";
        cin >> promptedSymbol;
    }
    maxMisses = promptedSymbol - '0';
}


void displayNumberOfWrongGuesses(int missesTotal, int missesMax) {
    cout << "Attempts to guess word: " << missesMax - missesTotal << "\n";
}


int main() {
    list<string> wordList = readWordFile("words.txt");

    int wordLength;
    setUpLengthOfWordToGuess(wordLength);
    removeWordsOfWrongLength(wordList, wordLength);
    if(wordList.empty()) {
        cout << "There is no words of given length";
        return 0;
    }
    //Initialize revealedWordSofar
    char *revealedWord =  new char[wordLength + 1];
    for(int i = 0; i < wordLength; i++) revealedWord[i] = '*';
    revealedWord[wordLength] = '\0';

    int maxMisses;
    setUpMaxMissesAmount(maxMisses);
    

    //Initialize guessed letters
    bool guessedLetters[26];
    for (int i = 0; i < 26; i++) guessedLetters[i] = false;


    //cout << "Word so far: " << revealedWord << "\n";
    int misses = 0;
    int discoveredLetterCount = 0;
    while (discoveredLetterCount < wordLength && misses < maxMisses) {
        cout << "\n\nWord so far: " << revealedWord << "\n";
        displayGuessedLetters(guessedLetters);
        displayNumberOfWrongGuesses(misses, maxMisses);
        cout << "Letter to guess: ";
        
        //check prompted letter
        //Check repeating letters
        char nextLetter;
        cin >> nextLetter;
        while (!(nextLetter >= 'a' && nextLetter <= 'z'))
        {
            cout << "Enter valid lower case symbol: ";
            cin >> nextLetter;
        }
        
        if(guessedLetters[nextLetter - 'a'] == true) {
            cout << "Letter already guessed, try again\n";
            continue;
        }
        guessedLetters[nextLetter - 'a'] = true;
        int missingCount = countWordsWithoutLetter(wordList, nextLetter);
        list<int> nextPattern;
        int nextPatternCount;
        mostFreqPatternByLetter(wordList, nextLetter, nextPattern, nextPatternCount);
        if (missingCount > nextPatternCount) {
            removeWordsWithLetter(wordList, nextLetter);
            misses++;
        } else {
            
            //RevealGuessedLetter function
            list<int>::iterator iter = nextPattern.begin();
            while (iter != nextPattern.end()) {
                discoveredLetterCount++;
                revealedWord[*iter] = nextLetter;
                iter++;
            }
            //Remove words that don't correspond pattern
            wordList = reduceByPattern(wordList, nextLetter, nextPattern);
        }
    }
    //DeclareResult Function
    if (misses == maxMisses) {
        cout << "Sorry. You lost. The word I was thinking of was '";
        cout << (wordList.cbegin())->c_str() << "'.\n";
    } else {
        cout << "Great job. You win. Word was '" << revealedWord << "'.\n";
    }
    return 0;
}