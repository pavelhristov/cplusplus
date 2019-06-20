#include <string>
#include <vector>
#include <fstream>

#include "FileReader.h"

FileReader::FileReader() {
    this->filePath = "array.txt";
}

FileReader::FileReader(std::string filePath) {
    this->filePath = filePath;
}

std::vector<std::string> FileReader::readLines(int linesCount) {
    std::ifstream readFromFile;
    std::string line;
    std::vector<std::string> lines;

    readFromFile.open(this->filePath, std::ios_base::in);
    int count = 0;
    while (readFromFile.good()) {
        getline(readFromFile, line);
        lines.push_back(line);
        count++;
        if (count >= linesCount) {
            break;
        }
    }

    readFromFile.close();
    return lines;
};

void FileReader::setFilePath(std::string newFilePath) {
    this->filePath = newFilePath;
}

std::string FileReader::getFilePath() {
    return this->filePath;
}

FileReader::~FileReader() {
}

