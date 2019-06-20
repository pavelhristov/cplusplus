#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

#include "IReader.h"

class FileReader : public Reader {
private:
    std::string filePath;

public:
    FileReader();
    FileReader(std::string filePath);
    std::vector<std::string> readLines(int linesCount) override;
    void setFilePath(std::string newFilePath);
    std::string getFilePath();
    ~FileReader();
};

#endif /* FILEREADER_H */

