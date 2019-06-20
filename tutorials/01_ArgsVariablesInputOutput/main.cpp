#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

// globals
//int g_iRandomNumber = 0;
//const double PI = 3.14159;

int main(int argc, char** argv) {

    // 1.1 print and arguments
    //
    //    std::cout << "Hello World!" << std::endl;
    //    
    //    if(argc != 1){
    //        std::cout << "You entered " << argc << " arguments" << std::endl;
    //    }
    //    
    //    for (int i = 0; i < argc; i++){
    //        std::cout << argv[i] << "\n";
    //    }
    //
    // ------------------------------------------------------------------------
    // 1.2 variables
    //    
    //    bool bMarried = true;
    //    char chMyGrade = 'A';
    //    unsigned short int u16Age = 43;
    //    short int siWeight = 180;
    //    int nDays = 7;
    //    long lBigNum = 1100000;
    //    float fPi = 3.14159;
    //    double dbBigFloat = 1.11111111111111111;
    //    long double ldPi = 3.14159;
    //    auto whatWillIBe = true;
    //    
    //    std::cout << "Min bool " <<
    //            std::numeric_limits<bool>::min() << std::endl;
    //    std::cout << "Max bool " <<
    //            std::numeric_limits<bool>::max() << std::endl;
    //    
    //    std::cout << "int size " << sizeof(int) << std::endl;
    //    
    //    float fBigFloat = 1.1111111111;
    //    float fBigFloat2 = 1.1111111111;
    //    float fFloatSum = fBigFloat + fBigFloat2;
    //    
    //    printf("fFloatSum Precision %.10f\n", fFloatSum);
    //    
    //    double dbBigFloat1 = 1.11111111111111111;
    //    double dbBigFloat2 = 1.11111111111111111;
    //    double dbBigFloatSum = dbBigFloat1 + dbBigFloat2;
    //    
    //    printf("dbBigFloatSum Precision %.20f\n", dbBigFloatSum);
    //    
    //    printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.1234, "Hi!");
    //
    // ------------------------------------------------------------------------
    // 1.3 strings
    //    
    //    std::string sQuestion("Enter Number 1 : ");
    //    std::string sNum1, sNum2;
    //    std::cout << sQuestion;
    //    getline(std::cin, sNum1);
    //    std::cout << "Enter Number 2 : ";
    //    getline(std::cin, sNum2);
    //
    //    int nNum1 = std::stoi(sNum1); // std::stoi() doesnt work properly in
    //    int nNum2 = std::stoi(sNum2); //  windows with mingw
    //
    //    printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
    //    printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
    //    printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
    //    printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
    //    printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2));
    //
    // ------------------------------------------------------------------------
    // problem 1
    // km = miles * 1.60934;
    // Enter Miles:  (std::stod)(string to double) 
    // output "X miles equals Y:4 kilometers"

    const double KM_MILES_RATIO = 1.60934;
    std::cout << "To close the program type 'EXIT'" << std::endl;
    std::string sMessage = "Enter misles for convetion to kilometers: ";

    while (true) {
        std::cout << sMessage << std::endl;
        
        std::string sMiles;
        getline(std::cin, sMiles);
        if(sMiles == "EXIT"){
            break;
        }

        double dbMiles = std::stod(sMiles);
        double dbKilometers = dbMiles * KM_MILES_RATIO;
        printf("%.4f miles equals %.4f kilometers.\n", dbMiles, dbKilometers);
    }
    
    std::cout << "Program shutting down!" << std::endl;

    return 0;
}

