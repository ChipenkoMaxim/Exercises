#include <iostream>

using namespace std;

int main() {
    string numb;
    cin >> numb;
    int index = 0;
    while(numb[index] != 0){
        cout << numb[index] << "\n";
        index++;

    }
    cout << index << "\n";
    return 0;
}