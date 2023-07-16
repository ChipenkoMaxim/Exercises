#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

void printArray(int* arr) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int gradeComparator(const void* fist, const void* second) {
    int* A = (int*)(fist);
    int* B = (int*)(second);

    return (*A - *B);
}

void sortGrades(int* grades) {
    qsort(grades, ARRAY_SIZE, sizeof(int), gradeComparator);        
}

int findAverageOfTwo(int first, int second) {
    return (first + second) / 2;
}



int findMedian(int* sales, int start, int end) {
    int median = 0;
    if((start + end + 1) % 2 == 0) {
        median = findAverageOfTwo(sales[(start + end) / 2], sales[((start + end) / 2) - 1]);
    } else {
        median = sales[(start + end) / 2];
    }
    return median;
}

void printStats(int first, int second, int third) {
    cout << "25% Quartile grade is: " << first << "\n";
    cout << "50% Quartile grade is: " << second << "\n";
    cout << "75% Quartile grade is: " << third << "\n";
}


void findQuartiles(int* grades) {
    int lowestGradeIndex = 0;
    int hightestGradeIndex = ARRAY_SIZE - 1;
    
    int medianIndex = ARRAY_SIZE / 2;
    int fiftiethQuartile = findMedian(grades, lowestGradeIndex, hightestGradeIndex);
    int twentyFifthQuartile = findMedian(grades, lowestGradeIndex, medianIndex);
    int seventyFifthQuartile = findMedian(grades, medianIndex, hightestGradeIndex);
    printStats(twentyFifthQuartile, fiftiethQuartile, seventyFifthQuartile);
}

int main() {
    int studentGrades[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
    cout << "Student Grades: ";
    sortGrades(studentGrades);
    printArray(studentGrades);
    findQuartiles(studentGrades);
    return 0;
}