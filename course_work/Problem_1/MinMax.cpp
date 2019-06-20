#include "MinMax.h"

MinMax::MinMax() {
    this->min = 0;
    this->max = 0;
}

MinMax::MinMax(int min, int max) {
    this->min = min;
    this->max = max;
}

MinMax MinMax::getMinMaxValue(std::vector<int> list) {
    MinMax res;
    res.min = list[0];
    res.max = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (res.min > list[i]) {
            res.min = list[i];
        }

        if (res.max < list[i]) {
            res.max = list[i];
        }
    }

    return res;
}

MinMax::~MinMax() {
}

