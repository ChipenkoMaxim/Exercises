#include <iostream>
using namespace std;



//На входе текстовый поток (char input)
//Посимвольное считывание потока
//числа раздёлённые запятой 145,4124,412412,4214,33123 - можно представить в виде int

//3 режима расшифровки

int lowerCaseDecode(int numb) {
    int processedNumb = numb % 27;
    if(processedNumb == 0) {
        return 0;
    }

    cout << (char)(processedNumb + 96);
    return 1;
}


int main() {
    lowerCaseDecode(56);
    return 0;
}