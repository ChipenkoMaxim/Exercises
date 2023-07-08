#include <iostream>
using namespace std;



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