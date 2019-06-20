#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main() {
    // 2.1 Conditions
    //    std::string sAge = "0";
    //    std::cout << "Enter your age: ";
    //    getline(std::cin, sAge);
    //    int nAge = std::stoi(sAge);
    //
    //    if ((nAge >= 1) && (nAge <= 18)) {
    //        std::cout << "Important Birthday" << std::endl;
    //    } else if ((nAge == 21) || (nAge == 50)) {
    //        std::cout << "Important Birthday" << std::endl;
    //    } else if (nAge >= 65) {
    //        std::cout << "Important Birthday" << std::endl;
    //    } else {
    //        std::cout << "Not an Important Birthday" << std::endl;
    //    }
    // ------------------------------------------------------------------------
    //2.2 Problem
    // If age 5 => "go to kindergarten"
    // if age 6-17 => "go to grade" class 1-12
    // age > 17 go to college
    // age < 5 =>  too young for school
    //
    //    std::cout << "Enter your age: ";
    //    std::string sAge = "0";
    //    getline(std::cin, sAge);
    //    int nAge = std::stoi(sAge);
    //
    //    if (nAge < 5) {
    //        std::cout << "Too young for school!" << std::endl;
    //    } else if (nAge == 5) {
    //        std::cout << "Go to Kindergarten!" << std::endl;
    //    } else if (nAge >= 6 && nAge <= 17) {
    //        printf("Go to grade %d!\n", (nAge - 5));
    //    } else {
    //        std::cout << "Go to College!" << std::endl;
    //    }
    //
    // ------------------------------------------------------------------------
    // 2.3 Arrays
    //    int arrnNums[10] = {0};
    //    int arrnNums2[] = {1, 2, 3};
    //    int arrnNums3[5] = {8, 9};
    //
    //    std::cout << "1st Value" << arrnNums3[0] << std::endl;
    //    arrnNums3[0] = 7;
    //    std::cout << "1st Value" << arrnNums3[0] << std::endl;
    //
    //    std::cout << "Array size: " <<
    //            sizeof (arrnNums3) / sizeof (*arrnNums3) << std::endl;
    //
    //    int arrnNums4[2][2][2] = {
    //        {
    //            {1, 2},
    //            {3, 4}
    //        },
    //        {
    //            {5, 6},
    //            {7, 8}
    //        }
    //    };
    //
    //    std::cout << arrnNums4[1][1][1] << std::endl;
    //
    // ------------------------------------------------------------------------
    // 2.4 Vectors
    //    std::vector<int> vecnRandNums(2);
    //    vecnRandNums[0] = 10;
    //    vecnRandNums[1] = 20;
    //    vecnRandNums.push_back(30);
    //    
    //    std::cout << "Last Index: " <<
    //            vecnRandNums[vecnRandNums.size() - 1] << std::endl;
    //    
    //    std::string sSentence = "This is a random string";
    //    std::vector<std::string> vecsWords;
    //    
    //    std::stringstream ss(sSentence);
    //    std::string sIndivStr;
    //    char cSpace = ' ';
    //    
    //    while(getline(ss, sIndivStr, cSpace)){
    //        vecsWords.push_back(sIndivStr);
    //    }
    //    
    //    for(int i = 0; i < vecsWords.size(); i++){
    //        std::cout << vecsWords[i] << std::endl;
    //    }
    //
    // ------------------------------------------------------------------------
    // 2.5 Problem
    // Enter calculation (ex. 5+6): 10 - 6
    // 10.0 - 6.0 = 4.0;
    // Please enter only +, -, *, /

    std::cout << "Enter calculation (ex. 5 + 6): ";
    std::string sInput = "";
    getline(std::cin, sInput);
    std::vector<std::string> vecsWords;
    std::stringstream ss(sInput);
    std::string sIndivStr;
    char cSpace = ' ';

    while (getline(ss, sIndivStr, cSpace)) {
        vecsWords.push_back(sIndivStr);
    }

    double dNum1 = std::stod(vecsWords[0]);
    double dNum2 = std::stod(vecsWords[2]);
    double dResult = 0;
    if (vecsWords[1] == "+") {
        dResult = dNum1 + dNum2;
        printf("%.1f %s %.1f = %.1f", dNum1, "+", dNum2, dResult);
    } else if (vecsWords[1] == "-") {
        dResult = dNum1 - dNum2;
        printf("%.1f %s %.1f = %.1f", dNum1, "-", dNum2, dResult);
    } else if (vecsWords[1] == "/") {
        dResult = dNum1 / dNum2;
        printf("%.1f %s %.1f = %.1f", dNum1, "/", dNum2, dResult);
    } else if (vecsWords[1] == "*") {
        dResult = dNum1 * dNum2;
        printf("%.1f %s %.1f = %.1f", dNum1, "*", dNum2, dResult);
    } else {
        std::cout << "Please enter only +, -, *, /" << std::endl;
    }

    return 0;
}

