#ifndef IREADER_H
#define IREADER_H

#include <string>
#include <vector>

class Reader {
public:
    virtual std::vector<std::string> readLines(int linesCount) = 0;
};

#endif /* IREADER_H */

