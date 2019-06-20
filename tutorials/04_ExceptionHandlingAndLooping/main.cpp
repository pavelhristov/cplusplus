#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <ctime>

std::vector<int> Range(int start, int end, int increment);
std::string BuildTreeLine(int height, int currentHeight);

int main() {
    // 4.1 while loop
    //    int i = 1;
    //
    //    while (i <= 20) {
    //        if ((i % 2) == 0) {
    //            i += 1;
    //            continue;
    //        }
    //
    //        if (i == 15) {
    //            break;
    //        } else {
    //            std::cout << i << std::endl;
    //        }
    //
    //        i += 1;
    //    }
    //
    //-------------------------------------------------------------------------
    // 4.2 Problem
    /* How tall is the tree: 5
            #
           ###
          #####
         #######
        #########
            #
     */
    //    int height = 0;
    //    std::cout << "How tall is the tree: ";
    //    std::cin >> height;
    //
    //    for (int i = height; i > 0; i--) {
    //        std::cout << BuildTreeLine(height, i) << std::endl;
    //    }
    //
    //    std::cout << BuildTreeLine(height, height) << std::endl;
    //
    //-------------------------------------------------------------------------
    // 4.3 Exceptions
    //    double num1 = 0;
    //    double num2 = 0;
    //
    //    std::cout << "Enter number 1: ";
    //    std::cin>> num1;
    //    std::cout << "Enter number 2: ";
    //    std::cin>> num2;
    //
    //    try {
    //        if (num2 == 0) {
    //            throw "Division by zero is not possible!";
    //        } else {
    //            printf("%.1f / %.1f = %.2f", num1, num2, (num1 / num2));
    //        }
    //    } catch (const char* ex) {
    //        std::cout << "Error: " << ex << std::endl;
    //    }
    //
    //-------------------------------------------------------------------------
    // more exceptions
    //    try {
    //        std::cout << "Throwing exception" << std::endl;
    //        throw std::runtime_error("Error Occured");
    //        std::cout << "After exception!" << std::endl;
    //    } catch (std::exception &ex) {
    //        std::cout << "Handled Exception: " << ex.what() << std::endl;
    //    } catch (...) {
    //        std::cout << "Default Exception" << std::endl;
    //    }
    //
    //-------------------------------------------------------------------------
    // 4.4 Do while loop
    //    srand(time(NULL));
    //    int secretNum = std::rand() % 11;
    //    int guess = 0;
    //
    //    do {
    //        std::cout << "Guess the number:";
    //        std::cin >> guess;
    //        if (guess > secretNum) {
    //            std::cout << "To Big" << std::endl;
    //        }
    //
    //        if (guess < secretNum) {
    //            std::cout << "To Small" << std::endl;
    //        }
    //    } while (secretNum != guess);
    //
    //    std::cout << "You guessed it" << std::endl;
    //
    //-------------------------------------------------------------------------
    // 4.5 Problem: Create do-while loop using while loop
    srand(time(NULL));
    int secretNum = std::rand() % 11;
    int guess = 0;

    while (true) {
        std::cout << "Guess the number:";
        std::cin >> guess;
        if (guess > secretNum) {
            std::cout << "To Big" << std::endl;
        }

        if (guess < secretNum) {
            std::cout << "To Small" << std::endl;
        }

        if (guess == secretNum) {
            break;
        }
    }

    std::cout << "You guessed it" << std::endl;

    return 0;
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

std::string BuildTreeLine(int height, int currentHeight) {
    char empty = ' ';
    char treeChar = '#';

    std::string line = "";
    int j = 0;
    while (j < (2 * height)) {
        if (j < currentHeight) {
            line += empty;
        } else if (j >= currentHeight && j < (2 * height - currentHeight + 1)) {
            line += treeChar;
        }

        j++;
    }

    return line;
}

