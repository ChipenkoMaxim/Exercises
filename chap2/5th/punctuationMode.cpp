#include <iostream>
using namespace std;



//На входе текстовый поток (char input)
//Посимвольное считывание потока
//числа раздёлённые запятой 145,4124,412412,4214,33123 - можно представить в виде int

//3 режима расшифровки

int punctuationDecode(int numb) {
    int processedNumb = numb % 9;
    switch (processedNumb)
    {
    case 0:
        return 0;
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
    return 1;
}


int main() {
    punctuationDecode(19);
    return 0;
}