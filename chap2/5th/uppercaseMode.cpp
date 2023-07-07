#include <iostream>
using namespace std;



//На входе текстовый поток (char input)
//Посимвольное считывание потока
//числа раздёлённые запятой 145,4124,412412,4214,33123 - можно представить в виде int

//3 режима расшифровки

int upperCaseDecode(int numb) {
    int processedNumb = numb % 27;
    if(processedNumb == 0) {
        return 0;
    }

    cout << (char)(processedNumb + 64);
    return 1;
}


int main() {
    //Uppercase расшифровка
    //число mod 27 = позиция буквы в алфавите
    //преобразование числа 1 к заглавной букве А (прибавить 64)
    upperCaseDecode(143);
    return 0;
}