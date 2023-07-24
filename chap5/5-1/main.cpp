#include <iostream>
// Let’s try implementing a class using the basic framework. Consider a class to
// store the data for an automobile. We’ll have three pieces of data: a manufacturer
// name and model name, both strings, and a model year, an integer. Create a
// class with get/set methods for each data member. Make sure you make good
// decisions concerning details like member names. It’s not important that you
// follow my particular naming convention. What’s important is that you think
// about the choices you make and are consistent in your decisions.
using namespace std;
class Automobile {
    public:
        Automobile();
        Automobile(string manufacturer, string model, string year);
        string manufacturer();
        void setManufacturer(string manufacturer);
        string model();
        void setModel(string model);
        int year();
        void setYear(int year);
    private:
        string _manufacturer;
        string _model;
        int _year;
};


int main () {

    return 0;
}