#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>

class Box {
public:
    double length, width, breadth;
    std::string boxString;

    Box() {
        this->length = 1;
        this->width = 1;
        this->breadth = 1;
    }

    Box(double l, double w, double b) {
        this->length = l;
        this->width = w;
        this->breadth = b;
    }

    // other unary operators : --, *(pointer dereference), 
    // -> (member selection), !, & (address of), +, -

    Box& operator++() {
        this->length++;
        this->width++;
        this->breadth++;
        return *this;
    }

    operator const char*() {
        std::ostringstream boxStream;
        boxStream << "Box: " << this->length << ", " << this->width <<
                ", " << this->breadth;

        this->boxString = boxStream.str();
        return this->boxString.c_str();
    }

    // +, -, *, /, %, ==, !=, >, <, >=, <=, &&, ||, !, =, +=, -=, *=, /=, ^,
    // [], &, | 

    Box operator+(const Box& box2) {
        Box boxSum;
        boxSum.length = this->length + box2.length;
        boxSum.width = this->width + box2.width;
        boxSum.breadth = this->breadth + box2.breadth;

        return boxSum;
    }

    double operator[](int x) {
        if (x == 0) {
            return this->length;
        } else if (x == 1) {
            return this->width;
        } else if (x == 2) {
            return this->breadth;
        } else {
            return 0;
        }
    }

    bool operator==(const Box& box2) {
        return ((this->length == box2.length) &&
                (this->width == box2.width) &&
                (this->breadth == box2.breadth));
    }

    bool operator<(const Box& box2) {
        double thisSize = this->length + this->width + this->breadth;
        double box2Size = box2.length + box2.width + box2.breadth;
        if (thisSize < box2Size) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const Box& box2) {
        double thisSize = this->length + this->width + this->breadth;
        double box2Size = box2.length + box2.width + box2.breadth;
        if (thisSize > box2Size) {
            return true;
        } else {
            return false;
        }
    }

    void operator=(const Box& boxToCopy) {
        this->length = boxToCopy.length;
        this->width = boxToCopy.width;
        this->breadth = boxToCopy.breadth;
    }
};

#include <fstream>

std::vector<std::string> StringToVector(std::string, char separator);

int main() {
    // 12.1 Operator overloading
    //    Box box(10, 10, 10);
    //    ++box;
    //    std::cout << box << std::endl;
    //    Box box2(5, 5, 5);
    //    std::cout << "Box1 + Box2 = " << box + box2 << std::endl;
    //
    //    std::cout << "Box Length: " << box[0] << std::endl;
    //    std::cout << std::boolalpha;
    //    std::cout << "Are boxes equal: " << (box == box2) << std::endl;
    //    std::cout << "Is box < box2: " << (box < box2) << std::endl;
    //    std::cout << "Is box > box2: " << (box < box2) << std::endl;
    //
    //    box = box2;
    //    std::cout << box << std::endl;
    //
    //-------------------------------------------------------------------------
    // 12.2 Files
    //    std::ofstream writeToFile;
    //    std::ifstream readFromFile;
    //    std::string textToWrite = "";
    //    std::string textFromFile = "";
    //    // ios::app : Append to the end of the file;
    //    // ios::trunc :  If the file exists delete the content;
    //    // ios::in : Open file for reading;
    //    // ios::out : Open file for writing;
    //    // ios::ate : Open file for writing and move to the end of the file;
    //
    //    writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
    //    if (writeToFile.is_open()) {
    //        writeToFile << "Begining of File" << std::endl;
    //        std::cout << "Enter data to write: ";
    //        getline(std::cin, textToWrite);
    //        writeToFile << textToWrite;
    //        writeToFile.close();
    //    }
    //
    //    readFromFile.open("test.txt", std::ios_base::in);
    //    if (readFromFile.is_open()) {
    //        while (readFromFile.good()) {
    //            getline(readFromFile, textFromFile);
    //            std::cout << textFromFile << std::endl;
    //        }
    //
    //        readFromFile.close();
    //    }
    //
    //-------------------------------------------------------------------------
    // 12.3 problem
    // whenever reading print words count and avarage word length for line
    std::ofstream writeToFile;
    std::ifstream readFromFile;
    std::string textToWrite = "";
    std::string textFromFile = "";

    writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
    if (writeToFile.is_open()) {
        writeToFile << "Beginning of File" << std::endl;
        std::cout << "Enter data to write: ";
        getline(std::cin, textToWrite);
        writeToFile << textToWrite;
        writeToFile.close();
    }

    readFromFile.open("test.txt", std::ios_base::in);
    if (readFromFile.is_open()) {
        while (readFromFile.good()) {
            getline(readFromFile, textFromFile);
            std::cout << textFromFile << std::endl;

            std::vector<std::string> vect = StringToVector(textFromFile, ' ');
            int wordsInLine = vect.size();
            std::cout << "Words in line: " << wordsInLine << std::endl;

            int charCount = 0;
            for (auto word : vect) {
                for (auto letter : word) {
                    charCount++;
                }
            }

            int avgNumChars = charCount / wordsInLine;
            std::cout << "Avg Word Lenght: " << avgNumChars << std::endl;
        }

        readFromFile.close();
    }



    return 0;
}

std::vector<std::string> StringToVector(std::string theString, char separator) {
    std::vector<std::string> vecsWords;
    std::stringstream ss(theString);
    std::string sIndivStr;

    while (getline(ss, sIndivStr, separator)) {
        vecsWords.push_back(sIndivStr);
    }

    return vecsWords;
}