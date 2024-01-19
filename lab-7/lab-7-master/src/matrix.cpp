#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.h"

using namespace Matrix;
void Matrix::SparseMatrix::multiply(const std::vector<double> &x, std::vector<double> &y) const{
    if (x.size() != _n)
        throw std::runtime_error("Error in COOMatrix::matvec: size of input vector differ from number of matrix columns");
    y.resize(_m);
    for (auto &v : y)
        v = 0;
    for (const auto &element : _elements)
        y[element.row] += element.data * x[element.column];
}

void Matrix::DenseMatrix::multiply(const std::vector<double> &x, std::vector<double> &y) const{
    if (x.size() != _n)
        throw std::runtime_error("Error in COOMatrix::matvec: size of input vector differ from number of matrix columns");
    y.resize(_m);
        for (auto &v : y)
            v = 0;
    for (size_t i = 0; i < _m; ++i)
        for (size_t j = 0; j < _n; ++j) {
            y[i] += _data[i * _n + j]* x[j];
    }
}