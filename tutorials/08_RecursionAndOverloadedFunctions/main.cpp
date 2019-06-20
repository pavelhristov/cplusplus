#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <cmath>

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
void BubbleSort(std::vector<int>& theVec);
int Factorial(int number);
void PrintHorzVector(std::vector<int> vec);
int Fib(int index);
double Area(double radius);
double Area(double height, double width);

int main() {
    // 8.1 BubbleSort
    //    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    //    BubbleSort(vecVals);
    //    for (auto x : vecVals) {
    //        std::cout << x << std::endl;
    //    }
    //
    //-------------------------------------------------------------------------
    // 8.2 Recursion
    //    std::cout << Factorial(3) << std::endl;
    //
    //-------------------------------------------------------------------------
    // 8.3 Problem
    //    std::vector<int> vec = {10, 8, 2, 5, 9, 11, 6, 14};
    //    PrintHorzVector(vec);
    //
    //-------------------------------------------------------------------------
    // 8.4 Problem: fibunacci
    //    int index = 0;
    //    std::cout << "Get Fibonacci Index: ";
    //    std::cin >> index;
    //    printf("Fib(%d) = %d\n", index, Fib(index));
    //
    //-------------------------------------------------------------------------
    // 8.5 Overloading functions
    std::cout << "Area Circle (c) or Rectangle (r): ";
    char areaType;
    std::cin >> areaType;
    switch (areaType) {
        case 'c':
            std::cout << "Enter Radius: ";
            double radius;
            std::cin >> radius;
            
            std::cout << "Area = " << Area(radius) << std::endl;
            break;
        case 'r':
            std::cout << "Enter Height: ";
            double height;
            std::cin >> height;

            std::cout << "Enter width: ";
            double width;
            std::cin >> width;
            
            std::cout << "Area = " << Area(height, width) << std::endl;
            break;
        default:
            std::cout << "Incorect type!" << std::endl;
            break;
    }

    return 0;
}

std::vector<int> GenerateRandVec(int numOfNums, int min, int max) {
    std::vector<int> vecValues;
    srand(time(NULL));
    int i = 0;
    int randVal = 0;

    while (i < numOfNums) {
        randVal = min + std::rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }

    return vecValues;
}

void BubbleSort(std::vector<int>& theVec) {
    int i = theVec.size() - 1;

    while (i >= 1) {
        int j = 0;

        while (j < i) {
            printf("\nIs %d > %d \n", theVec[j], theVec[j + 1]);
            if (theVec[j] >= theVec[j + 1]) {
                std::cout << "Switching";

                int temp = theVec[j];
                theVec[j] = theVec[j + 1];
                theVec[j + 1] = temp;
            } else {
                std::cout << "Don't switch";
            }

            j++;

            for (auto k : theVec) {
                std::cout << k << ", ";
            }
        }

        std::cout << "\nEnd of Round\n";
        i--;
    }
}

int Factorial(int number) {
    if (number == 1) {
        return 1;
    } else {
        int result = number * Factorial(number - 1);
        return result;
    }
}

void PrintHorzVector(std::vector<int> vec) {

    std::string line(6 * vec.size(), '-');
    char separator = '|';

    std::cout << line << std::endl;

    for (int i = 0; i < vec.size(); i++) {
        printf("%c%3d  ", separator, i);
    }

    std::cout << separator << std::endl;
    std::cout << line << std::endl;

    for (int i = 0; i < vec.size(); i++) {
        printf("%c%3d  ", separator, vec[i]);
    }

    std::cout << separator << std::endl;
    std::cout << line << std::endl;
}

int Fib(int index) {
    if (index < 2) {
        return index;
    } else {
        return Fib(index - 1) + Fib(index - 2);
    }
}

double Area(double radius) {
    return 3.14159 * std::pow(radius, 2);
}

double Area(double height, double width) {
    return height * width;
}
