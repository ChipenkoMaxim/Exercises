#include <iostream>
using namespace std;

class sample {
    public:
        sample();
        sample(int numb);
        int doesSomething(double param);
    private:
        int intData;
};

int main() {
    sample test();
    return 0;
}

sample::sample() {}
