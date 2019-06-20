#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <functional>

double MultBy2(double num) {
    return num * 2;
}

double MultBy3(double num) {
    return num * 3;
}

double DoMath(std::function<double(double) > func, double num) {
    return func(num);
}

bool isOdd(int num) {
    if (num % 2 == 0) {
        return false;
    } else {
        return true;
    }
}

std::vector<int> filter(std::vector<int> numbers,
        std::function<bool(int) > comparer) {
    std::vector<int> result;

    for (auto num : numbers) {
        if (comparer(num)) {
            result.push_back(num);
        }
    }

    return result;
}

std::vector<char> GetHAndTList(std::vector<char> possibleValues, int count) {
    std::vector<char> result(count);
    for (int i = 0; i < count; i++) {
        result.push_back(possibleValues[std::rand() % possibleValues.size()]);
    }

    return result;
}

int GetNumberOfMatches(std::vector<char> list, char element) {
    int count = 0;
    for(char ch: list){
        if(ch == element){
            count++;
        }
    }
    
    return count;
}

int main() {
    // 13.1 functions
    //    auto times2 = MultBy2;
    //    std::cout << "5 * 2 = " << times2(5) << std::endl;
    //    std::cout << "6 * 2 = " << DoMath(times2, 6) << std::endl;
    //
    //    std::vector < std::function<double(double) >> funcs(2);
    //    funcs[0] = MultBy2;
    //    funcs[1] = MultBy3;
    //
    //    std::cout << "3 * 10 = " << funcs[1](10) << std::endl;
    //
    //-------------------------------------------------------------------------
    // 13.2 Problem
    // filter function recieves a list and a func(isOdd) and returns passing
    //    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //    std::vector<int> oddNumbers = filter(vec, isOdd);
    //
    //    for (auto num : oddNumbers) {
    //        std::cout << num << std::endl;
    //    }
    //
    //-------------------------------------------------------------------------
    // 13.3 Problem
    // generate list of head of tails and check how many heads and tails were
    // generated
    srand(time(NULL));
    std::vector<char> possibleValues{'H', 'T'};
    std::vector<char> hAndTList = GetHAndTList(possibleValues, 100);
    std::cout << "Number of Heads: " << GetNumberOfMatches(hAndTList,
            possibleValues[0]) << std::endl;

    std::cout << "Number of Tails: " << GetNumberOfMatches(hAndTList,
            possibleValues[1]) << std::endl;



    return 0;
}

