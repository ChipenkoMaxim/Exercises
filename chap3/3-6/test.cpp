#include <iostream>
#include <cstdlib>

using namespace std;


int generateRandNum(int range) {
    return rand() % range;
}



int main() {
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        cout << generateRandNum(10) << "\n";
    }
    return 0;
}