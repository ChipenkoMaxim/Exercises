#include <iostream>
// For our automobile class from the previous exercise, add a support method
// that returns a complete description of the automobile object as a formatted
// string, such as, "1957 Chevrolet Impala". Add a second support method that
// returns the age of the automobile in years.

using namespace std;
class Automobile {
    public:
        Automobile();
        Automobile(string manufacturer, string model, int year);
        string manufacturer();
        void setManufacturer(string manufacturer);
        string model();
        void setModel(string model);
        int year();
        void setYear(int year);
        void toString();
        int automobileAge();
    private:
        string _manufacturer;
        string _model;
        int _year;
};


int main () {
    Automobile car("Chevrolet", "Impala", 1957);
    car.toString();
    cout << "Automobile's age = " << car.automobileAge();
    return 0;
}

Automobile::Automobile() {}

Automobile:: Automobile(string manufacturer, string model, int year) {
    setManufacturer(manufacturer);
    setModel(model);
    setYear(year);
}


string Automobile::manufacturer() {
    return _manufacturer;
}

void Automobile::setManufacturer(string manufacturer) {
    _manufacturer = manufacturer;
}

string Automobile::model() {
    return _model;
}

void Automobile::setModel(string model) {
    _model = model;
}

int Automobile::year() {
    return _year;
}

void Automobile::setYear(int year) {
    _year = year;
}

void Automobile::toString() {
    cout << year() <<
    " " << manufacturer() <<
    " " << model() << "\n";
}

int Automobile::automobileAge() {
    return 2023 - year();
}