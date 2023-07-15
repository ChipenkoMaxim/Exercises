#include <iostream>

using namespace std;

void alterate(int* m) {
    *m = 15;
}

int main() {
    int m = 10;
    alterate(&m);
    cout << m;
    return 0;
}