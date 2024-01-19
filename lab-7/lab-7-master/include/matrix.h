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
    
    template <typename DT>
    DT dot_vect(const std::vector<DT> &a, const std::vector<DT> &b, const size_t &n){
        DT c = 0.0;
        for (int i = 0; i < n; ++i) {
            c += a[i] * b[i];
        }
        return c;
    }

    template <typename MT, typename DT>
    std::vector<DT> GradientSolver(const MT &A, const std::vector<DT> &b, DT eps, int max){
        size_t n = A.n();

        std::vector<DT> x(n, 0.0);
        std::vector<DT> r(n);
        std::vector<DT> z(n);

        std::vector<DT> Az;

        A.multiply(x, r); //r

        for (int i = 0; i < n; ++i) {
            r[i] = b[i] - r[i];
            z[i] = r[i];
        }

        DT rr_1 = dot_vect(r, r, n);
        DT r0 = sqrt(rr_1);

        for (int iter = 0; iter < max; ++iter) {

            A.multiply(z, Az);
            DT Az_z = dot_vect(z, Az, n);    

            // 1
            DT alpha = rr_1 / Az_z;

            // 2, 3
            for (int i = 0; i < n; ++i) {
                x[i] += alpha * z[i];
                r[i] -= alpha * Az[i];
            }

            DT rr = dot_vect(r, r, n);
            if (std::sqrt(rr) < eps*std::sqrt(dot_vect(b, b, n))) {
                break; // Критерий завершения
            }

            //4
            DT betta = (rr / rr_1);

            // 5
            for (int i = 0; i < n; ++i) {
                z[i] = r[i] + betta * z[i];
            }
            rr_1 = rr;
            
        }
        return x;
    }
        
    std::istream& operator>>(std::istream &os, SparseMatrix &matrix);
    std::istream& operator>>(std::istream &os, DenseMatrix &matrix);

}

#endif