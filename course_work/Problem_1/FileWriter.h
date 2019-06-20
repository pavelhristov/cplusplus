#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <vector>

#include "IWriter.h"

class FileWriter : public Writer {
private:
    std::string filePath;

public:
    FileWriter();
    FileWriter(std::string filePath);
    void printLines(std::vector<std::string> lines) override;
    void setFilePath(std::string newFilePath);
    std::string getFilePath();
    ~FileWriter();
};

#endif /* FILEWRITER_H */

