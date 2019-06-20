#ifndef MINMAX_H
#define MINMAX_H

#include <vector>

struct MinMax {
    int min;
    int max;

    MinMax();

    MinMax(int min, int max);
    
    static MinMax getMinMaxValue(std::vector<int> list);

    ~MinMax();
};

#endif /* MINMAX_H */

