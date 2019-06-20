#ifndef MATRIX_H
#define MATRIX_H

#include "IReader.h"
#include "IWriter.h"
#include "helpers.h"

#define M 10

class Matrix {
private:
    int length;
    int matrix[M][M];

    void initMatrix() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = 0;
            }
        }
    }
public:

    Matrix();

    void setLength(int length);

    bool insertValue(Reader& reader);

    void print(Writer& writer);

    int getLength();

    std::vector<int> getSumByRows();

    int getSum();

    int getWithMaxSumByRows();

    ~Matrix();
};


#endif /* MATRIX_H */

