#include <vector>

#include "IReader.h"
#include "IWriter.h"
#include "Matrix.h"

Matrix::Matrix() {
    this->length = M;
    this->initMatrix();
}

void Matrix::setLength(int length) {
    this->length = length;
    this->initMatrix();
}

bool Matrix::insertValue(Reader& reader) {
    std::vector<std::string> lines = reader.readLines(this->length);
    for (int i = 0; i < lines.size() && i< this->length; i++) {
        std::vector<std::string> line = StringToVector(lines[i], ' ');
        for (int j = 0; j < line.size() && j < this->length; j++) {
            this->matrix[i][j] = std::stoi(line[j]);
        }
    }
}

void Matrix::print(Writer& writer) {
    std::vector<std::string> lines;
    for (int i = 0; i< this->length; i++) {
        lines.push_back(intArrayToString(this->matrix[i], this->length, ' '));
    }

    writer.printLines(lines);
}

Matrix::getLength() {
    return this->length;
}

std::vector<int> Matrix::getSumByRows() {
    std::vector<int> sumByRows(this->length);
    int sum;
    for (int i = 0; i<this->length; i++) {
        sum = 0;
        for (int num : matrix[i]) {
            sum += num;
        }

        sumByRows[i] = sum;
    }

    return sumByRows;
}

Matrix::getSum() {
    int sum = 0;
    for (int i = 0; i<this->length; i++) {
        for (int num : matrix[i]) {
            sum += num;
        }
    }

    return sum;
}

Matrix::getWithMaxSumByRows() {
    std::vector<int> sumByRows = this->getSumByRows();
    int max = sumByRows[0];
    for (int i = 1; i < sumByRows.size(); i++) {
        if (max < sumByRows[i]) {
            max = sumByRows[i];
        }
    }

    return max;
}

Matrix::~Matrix() {
}

