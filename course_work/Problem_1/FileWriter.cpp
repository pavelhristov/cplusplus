#include <string>
#include <vector>
#include <fstream>

#include "FileWriter.h"

FileWriter::FileWriter() {
    this->filePath = "array.txt";
}

FileWriter::FileWriter(std::string filePath) {
    this->filePath = filePath;
}

void FileWriter::printLines(std::vector<std::string> lines) {
    std::ofstream writeToFile;
    writeToFile.open(this->filePath, std::ios_base::out | std::ios_base::trunc);
    if (writeToFile.is_open()) {
        for (std::string line : lines) {
            writeToFile << line << std::endl;
        }

        writeToFile.close();
    }
}

void FileWriter::setFilePath(std::string newFilePath) {
    this->filePath = newFilePath;
};

std::string FileWriter::getFilePath() {
    return this->filePath;
}

FileWriter::~FileWriter() {
}

