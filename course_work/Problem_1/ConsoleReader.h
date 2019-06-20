#ifndef CONSOLEREADER_H
#define CONSOLEREADER_H

#include <string>

#include "IReader.h"

class ConsoleReader : public Reader {
public:
    ConsoleReader();
    std::vector<std::string> readLines(int linesCount) override;
    std::string readLine();
    ~ConsoleReader();
};

#endif /* CONSOLEREADER_H */

