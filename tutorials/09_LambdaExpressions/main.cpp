#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <functional>

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
std::vector<int> GenerateFibList(int count);

int main() {
    // 9.1 Lambda expressions
    //    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    //
    //    for (auto val : vecVals) {
    //        std::cout << val << std::endl;
    //    }
    //
    //    std::cout << "---------------" << std::endl;

    // 9.1.1 sort with lambda
    //    std::sort(vecVals.begin(), vecVals.end(), [](int x, int y) {
    //        return x < y;
    //    });
    //
    //    for (auto val : vecVals) {
    //        std::cout << val << std::endl;
    //    }

    // 9.1.2 Copy with lambda condition
    //    std::vector<int> evenVecVals;
    //    std::copy_if(vecVals.begin(),
    //            vecVals.end(),
    //            std::back_inserter(evenVecVals),
    //            [](int x) {
    //                return (x % 2) == 0;
    //            });
    //
    //    for (auto val : evenVecVals) {
    //        std::cout << val << std::endl;
    //    }

    // 9.1.3 Sum with lambda foreach
    //    int sum = 0;
    //    std::for_each(vecVals.begin(), vecVals.end(), [&](int x) {
    //        sum += x;
    //    });
    //
    //    std::cout << "Sum: " << sum << std::endl;
    //
    //-------------------------------------------------------------------------
    // 9.2 Problem
    //
    //    int devisor;
    //    std::vector<int> vecVals2;
    //    std::cout << "List of Values Devisable by: ";
    //    std::cin >> devisor;
    //
    //    std::copy_if(vecVals.begin(), vecVals.end(),
    //            std::back_inserter(vecVals2),
    //            [devisor](int x) {
    //                return (x % devisor) == 0;
    //            });
    //
    //    std::cout << "Values devisable by " << devisor << ": " << std::endl;
    //    for (auto val : vecVals2) {
    //        std::cout << val << std::endl;
    //    }

    // 9.2.1 double a vector
    //    std::vector<int> doubleVec;
    //
    //    std::for_each(vecVals.begin(), vecVals.end(), [&](int x) {
    //        doubleVec.push_back(2 * x);
    //    });
    //
    //    std::cout << "Doubled values: " << std::endl;
    //    for (auto val : doubleVec) {
    //        std::cout << val << std::endl;
    //    }

    // 9.2.2 combine vectors
    //    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    //    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    //    std::vector<int> vec3(5);
    //
    //    std::transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(),
    //            [](int x, int y) {
    //                return x + y;
    //            });
    //
    //    std::cout << "Combined vector: " << std::endl;
    //    for (auto val : vec3) {
    //        std::cout << val << std::endl;
    //    }
    //
    //-------------------------------------------------------------------------
    // 9.3 ternary operator
    //    int age = 43;
    //    bool canIVote = (age >= 18) ? true : false;
    //    std::cout.setf(std::ios::boolalpha);
    //    std::cout << "Can vote: " << canIVote << std::endl;
    //
    //-------------------------------------------------------------------------
    // 9.4 Lambda recursion and variables
    //    std::function<int(int)> Fib = [&Fib](int n) {
    //        return n < 2 ? n : Fib(n - 1) + Fib(n - 2);
    //    };
    //
    //    std::cout << "Fib 4: " << Fib(4) << std::endl;

    // 9.4.1 Problem: Genereate list of Fibunacci numbers
    std::vector<int> listOfFibs = GenerateFibList(10);
    for (auto val : listOfFibs) {
        std::cout << val << std::endl;
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

std::vector<int> GenerateFibList(int count) {
    std::vector<int> fibs = {0, 1};
    for (int i = 2; i < count; i++) {
        fibs.push_back(fibs[i - 2] + fibs[i - 1]);
    }
    
    return fibs;
}