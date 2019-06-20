#ifndef CONSOLEWRITER_H
#define CONSOLEWRITER_H

#include <string>
#include <vector>

#include "IWriter.h"

class ConsoleWriter : public Writer {
public:
    ConsoleWriter();
    void printLines(std::vector<std::string> lines) override;
    void printLine(std::string line);
    ~ConsoleWriter();
};

#endif /* CONSOLEWRITER_H */

