#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "matrix.h"
#include <sstream>

using namespace Matrix;

std::vector<double> read_vectors(const char *filename){
    std::ifstream ifs(filename);
    if (!ifs){
        throw IOErrors::NoInputFile;
    }
    std::vector<double> output;
    int m;
    ifs >> m;
    if (!ifs){
        throw IOErrors::IncorrectInputData;
    }
    output.resize(m);
    for (int i = 0; i < m; i++)
        ifs >> output[i];
        if (!ifs)
            throw IOErrors::IncorrectInputData;
    return output;
}

std::string error_name(const IOErrors &error){
    switch (error){

    case IOErrors::NoFileName:
        return "Filenames are not specified on the command line";
    
    case IOErrors::NoInputFile:
        return "Cannot open input file";

    case IOErrors::IncorrectInputData:
        return "Incorrect data in input file";

    case IOErrors::NoOutputFile:
        return "Cannot open file for writing";

    case IOErrors::CannotWriteData:
        return "Cannot write data to file";

    case IOErrors::NoError:
        return "No error";
    
    default:
        return "Unspecified error";
    }
}

std::istream &Matrix::operator>>(std::istream &is, SparseMatrix &matrix){
    matrix._elements.clear();
    matrix._m = 0;
    matrix._n = 0;
    std::string current_line;
    while (std::getline(is, current_line))
    {
        size_t current_n = 0;
        std::istringstream iss(current_line);
        while (true)
        {
            double v;
            iss >> v;
            if (!iss) break;
            if (std::fpclassify(v) != FP_ZERO)
            {
                matrix._elements.push_back({v, matrix._m, current_n});
            }
            current_n++;
        }
        if (matrix._m == 0) matrix._n = current_n;
        if (current_n == 0) break;
        matrix._m++;
        if (current_n != matrix._n) throw std::runtime_error("Rows of different sizes");
    }
    return is;

}


std::istream &Matrix::operator>>(std::istream &is, DenseMatrix &matrix){
    matrix._m = 0;
    matrix._n = 0;
    std::string current_line;
    while (std::getline(is, current_line))
    {
        int current_n = 0;
        std::istringstream iss(current_line);
        // std::vector<double> row;
        while (true)
        {
            double v;
            iss >> v;
            if (!iss) break;
            matrix._data.push_back(v);
            current_n++;
        }
        if (matrix._m == 0) matrix._n = current_n;
        if (current_n == 0) break;
        matrix._m++; 
        if (current_n != matrix._n) throw std::runtime_error("Rows of different sizes");
    }
    return is;
}
