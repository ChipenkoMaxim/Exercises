#include <iostream>

using namespace std;


int factorial(int n) {
    if(n == 1 || n == 0) return 1;
    return factorial(n - 1) * n;
}


int main() {
    cout << factorial(1);
    return 0;
}