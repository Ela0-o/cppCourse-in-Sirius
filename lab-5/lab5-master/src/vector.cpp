#include <iostream>
#include "list.h"

#include <fstream>
#include <vector>

#include <sstream>
#include <string>

using namespace VecListFuncks;

// вывод ошибок
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


// чтение файла 1.txt
std::vector<int> read_vectors(const char *filename){
    std::ifstream ifs(filename);
    if (!ifs){
        throw IOErrors::NoInputFile;
    }

    if (!ifs){
        throw IOErrors::IncorrectInputData;
    }

    std::vector<int> output;
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