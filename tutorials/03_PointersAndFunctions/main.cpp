#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// 3.3 Functions prototypes
double AddNumbers(double num1, double num2);
void AssignAge(int age);
int AssignAge2(int age);
void AssignAge3(int* pAge);
void DoubleArray(int* arr, int size);
std::vector<int> Range(int start, int end, int increment);
void PrintVector(std::vector<int> vec);

int main() {
    // 3.1 vectors and loops
    //    std::vector<int> myVec(10);
    //    std::iota(std::begin(myVec), std::end(myVec), 0);
    //
    //    for (int i = 0; i < myVec.size(); i++) {
    //        std::cout << myVec[i] << std::endl;
    //    }
    //
    //    // foreach
    //    for (auto y : myVec) {
    //        std::cout << y << std::endl;
    //    }
    //
    //    int val = 8;
    //    if ((val % 2) == 0) {
    //        std::cout << val << " is even" << std::endl;
    //    } else {
    //        std::cout << val << " is odd" << std::endl;
    //    }
    //
    // ------------------------------------------------------------------------
    // 3.2 Problem
    // generate vector with values 1-10 and print the odd ones
    //    std::vector<int> myVec(10);
    //    std::iota(std::begin(myVec), std::end(myVec), 1);
    //    for (auto y : myVec) {
    //        if ((y % 2) == 0) {
    //            std::cout << y << std::endl;
    //        }
    //    }
    //
    // ------------------------------------------------------------------------
    // 3.3 Functions
    //    double num1, num2;
    //    std::cout << "Enter Num 1: ";
    //    std::cin >> num1;
    //    std::cout << "Enter Num 2: ";
    //    std::cin >> num2;
    //
    //    printf("%.1f + %.1f = %.1f", num1, num2, AddNumbers(num1, num2));
    //
    //    int age = 43;
    //    AssignAge(age);
    //    std::cout << "New Age " << age << std::endl;
    //
    //    age = AssignAge2(age);
    //    std::cout << "Returned Age " << age << std::endl;
    //
    // ------------------------------------------------------------------------
    // 3.4 Pointers
    //    int age = 43;
    //    int* pAge = NULL;
    //
    //    pAge = &age;
    //
    //    std::cout << "Address: " << pAge << std::endl;
    //    std::cout << "Value at Address: " << *pAge << std::endl;
    //
    //    int intArray[] = {1, 2, 3, 4};
    //    int* pIntArray = intArray;
    //
    //    std::cout << "1st " << *pIntArray << " Address " << pIntArray << std::endl;
    //    pIntArray++;
    //    std::cout << "2st " << *pIntArray << " Address " << pIntArray << std::endl;
    //    pIntArray--;
    //    std::cout << "1st " << *pIntArray << " Address " << pIntArray << std::endl;
    //
    //    int age = 43;
    //    AssignAge3(&age);
    //    std::cout << "Pointer Age " << age << std::endl;
    //
    // ------------------------------------------------------------------------
    // 3.5 Pointers in array
    //    int arr[] = {1, 2, 3, 4};
    //    DoubleArray(arr, 4);
    //    for (int i = 0; i < 4; i++) {
    //        std::cout << "Array " << arr[i] << std::endl;
    //    }
    //
    // ------------------------------------------------------------------------
    // 3.6 Problems
    // create func recieving start and end value and increment, it will return
    // array as result; Range(start, end, increment);
    //
    //    std::vector<int> vec = Range(0, 21, 3);
    //    PrintVector(vec);
    //
    // How much to invest:  1000;
    // Interest Rate: 8;
    // Value after 10 years: 2158.92
    double investment = 0.0;
    double interestRate = 0.0;
    std::cout << "How much to invest: ";
    std::cin >> investment;
    std::cout << "Interest Rate: ";
    std::cin >> interestRate;

    interestRate *= .01;

    for (auto y : Range(1, 10, 1)) {
        investment += (investment * interestRate);
    }

    std::cout << "Value after 10 years: " << investment << std::endl;

    
    return 0;
}

// 3.3 Functions 

double AddNumbers(double num1, double num2) {
    return num1 + num2;
}

void AssignAge(int age) {
    age = 24;
}

int AssignAge2(int age) {
    age = 24;
    return age;
}

void AssignAge3(int* pAge) {
    *pAge = 22;
}

void DoubleArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;
    }
}

std::vector<int> Range(int start, int end, int increment) {
    std::vector<int> result;
    int current = start;

    while (current <= end) {
        result.push_back(current);

        current += increment;
    }

    return result;
}

void PrintVector(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < (vec.size() - 1)) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

