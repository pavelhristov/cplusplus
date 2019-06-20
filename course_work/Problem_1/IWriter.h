#ifndef IWRITER_H
#define IWRITER_H

#include <string>
#include <vector>

class Writer {
public:
    virtual void printLines(std::vector<std::string> lines) = 0;
};

#endif /* IWRITER_H */

