#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include "matrix.h"


using namespace Matrix;

int main(int argc, char** argv) {

    try{
        if (argc < 4)
            throw IOErrors::NoFileName;

        double eps = 1e-6;
        int maxIt = 1000;

        std::string s(argv[1]); 
        std::ifstream file(s);
		std::string line;
        std::vector<double> b = read_vectors(argv[2]);
        std::string w(argv[3]); 
        std::vector<double> x;

		if (file.is_open()) {
			std::getline(file, line);
			if (line == "Dense") {
				DenseMatrix A;
				file >> A;
				x = Matrix::GradientSolver(A, b, eps, maxIt);
			}
			else if (line == "Sparse") {
				SparseMatrix A;
				file >> A;
				x = Matrix::GradientSolver(A, b, eps, maxIt);
			}
			else {
				throw IOErrors::IncorrectInputData;
			}
		}
		else throw IOErrors::NoInputFile;
		file.close();

        std::cout << " {";

        for (int i = 0; i < x.size(); i++) {
            std::cout << x[i] << " " << std::endl;
        }
        std::cout << " }"<< std::endl;;

        std::ofstream out;
        out.open(w);
        if (out.is_open()){
            for (int i = 0; i < x.size(); i++) {
                out << x[i] << std::endl;
            }
        }
        else throw IOErrors::NoInputFile;
        out.close();

    return 0;

    }
	catch (const IOErrors& error){
		std::cerr << error_name(error) << std::endl;
		return -1;
	}
}

