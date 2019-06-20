#include <string>
#include <vector>
#include <iostream>

#include "ConsoleWriter.h"

ConsoleWriter::ConsoleWriter() {
}

void ConsoleWriter::printLines(std::vector<std::string> lines) {
    for (std::string line : lines) {
        this->printLine(line);
    }
}

void ConsoleWriter::printLine(std::string line) {
    std::cout << line << std::endl;
}

ConsoleWriter::~ConsoleWriter() {
}

