#include <string>
#include <vector>
#include <iostream>

#include "ConsoleReader.h"

ConsoleReader::ConsoleReader() {
}

std::vector<std::string> ConsoleReader::readLines(int linesCount){
    std::vector<std::string> lines;

    for (int i = 0; i < linesCount; i++) {
        lines.push_back(this->readLine());
    }

    return lines;
};

std::string ConsoleReader::readLine() {
    std::string line;
    getline(std::cin, line);
    return line;
}

ConsoleReader::~ConsoleReader() {
}

