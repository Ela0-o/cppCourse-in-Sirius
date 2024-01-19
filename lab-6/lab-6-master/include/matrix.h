#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>


enum class IOErrors {NoFileName = -999, NoInputFile, IncorrectInputData, NoOutputFile, CannotWriteData, NoError = 0};

std::vector<double> read_vectors(const char *filename);

std::string error_name(const IOErrors &error);


namespace Matrix{
    class AbstractMatrix{
        protected:
            size_t _m = 0, _n = 0;

        public:
            inline const size_t & m() const{return _m;}
            inline const size_t & n() const{return _n;}

            inline virtual void multiply(const std::vector<double> &x,std::vector<double> &y) const = 0;
    };

    class DenseMatrix: public AbstractMatrix{
        private:
            std::vector<double> _data;
        
        public:

            virtual void multiply(const std::vector<double> &x, std::vector<double> &y) const override;
            
            friend std::istream& operator>>(std::istream &os, DenseMatrix &matrix);
    };

    class SparseMatrix: public AbstractMatrix{
        private:
            struct Elem{
                double data;
                size_t row, column;
            };
            std::vector<Elem> _elements;
        
        public:
            virtual void multiply(const std::vector<double> &x,std::vector<double> &y) const override;

            friend std::istream& operator>>(std::istream &os, SparseMatrix &matrix);
    };

    std::vector<double> GradientSolver(const AbstractMatrix &A, const std::vector<double> &b, double eps, int max);
    
    std::istream& operator>>(std::istream &os, SparseMatrix &matrix);
    std::istream& operator>>(std::istream &os, DenseMatrix &matrix);

}
// std::vector<double> GradientSolver(const AbstractMatrix &A, const std::vector<double> &b, double eps, int max);

// std::istream& operator>>(std::istream &os, SparseMatrix &matrix);
// std::istream& operator>>(std::istream &os, DenseMatrix &matrix);

#endif