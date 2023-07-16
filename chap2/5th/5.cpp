#include <iostream>
using namespace std;

// PROBLEM: DECODE A MESSAGE
// A message has been encoded as a text stream that is to be read character by charac-
// ter. The stream contains a series of comma-delimited integers, each a positive number
// capable of being represented by a C++ int. However, the character represented by
// a particular integer depends on the current decoding mode. There are three modes:
// uppercase, lowercase, and punctuation.
// In uppercase mode, each integer represents an uppercase letter: The integer
// modulo 27 indicates the letter of the alphabet (where 1 = A and so on). So an input
// value of 143 in uppercase mode would yield the letter H because 143 modulo 27 is
// 8 and H is the eighth letter in the alphabet.
// The lowercase mode works the same but with lowercase letters; the remainder of
// dividing the integer by 27 represents the lowercase letter (1 = a and so on). So an
// input value of 56 in lowercase mode would yield the letter b because 57 modulo 27
// is 2 and b is the second letter in the alphabet.
// In punctuation mode, the integer is instead considered modulo 9, with the inter-
// pretation given by Table 2-3 below. So 19 would yield an exclamation point because
// 19 modulo 9 is 1.
// At the beginning of each message, the decoding mode is uppercase letters. Each
// time the modulo operation (by 27 or 9, depending on mode) results in 0, the decod-
// ing mode switches. If the current mode is uppercase, the mode switches to lowercase
// letters. If the current mode is lowercase, the mode switches to punctuation, and if it is
// punctuation, it switches back to uppercase.




//На входе текстовый поток (char input)
//Посимвольное считывание потока
//числа раздёлённые запятой 145,4124,412412,4214,33123 - можно представить в виде int

//3 режима расшифровки
int upperCaseDecode(int numb) {
    int processedNumb = numb % 27;
    if(processedNumb == 0) {
        return 2;
    }

    cout << (char)(processedNumb + 64); // processedNumb + ('A' - 1);
    return 1;
}

int lowerCaseDecode(int numb) {
    int processedNumb = numb % 27;
    if(processedNumb == 0) {
        return 3;
    }

    cout << (char)(processedNumb + 96);// processedNumb + ('a' - 1);
    return 2;
}

int punctuationDecode(int numb) {
    int processedNumb = numb % 9;
    switch (processedNumb)
    {
    case 0:
        return 1;
    case 1:
        cout << "!";
        break;
    case 2:
        cout << "?";
        break;
    case 3:
        cout << ",";
        break;
    case 4:
        cout << ".";
        break;
    case 5:
        cout << " ";
        break;
    case 6:
        cout << ";";
        break;
    case 7:
        cout << "\"";
        break;
    case 8:
        cout << "\'";
        break;
    default:
        break;
    }
    return 3;
}


int main() {
    //Получить число
    char symbol;
    int number = 0;
    int mode = 1;
    while (symbol != 10)
    {
        symbol = cin.get();
        while (symbol != ',' && symbol != 10)
        {
        number = number * 10 + (symbol - '0');
        symbol = cin.get();
        }
        //cout << number << endl;
        switch (mode)
        {
        case 1:
            mode = upperCaseDecode(number);
            break;
        case 2:
            mode = lowerCaseDecode(number);
            break;
        case 3:
            mode = punctuationDecode(number);
            break;
        default:
            break;
        }
        number = 0;
    }
    return 0;
}