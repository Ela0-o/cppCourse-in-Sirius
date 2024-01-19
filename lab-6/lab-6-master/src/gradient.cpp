#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.h"


using namespace Matrix;

double dot_vect(const std::vector<double> &a, const std::vector<double> &b, const size_t &n){
    double c = 0.0;
    for (int i = 0; i < n; ++i) {
        c += a[i] * b[i];
    }
    return c;
}

std::vector<double> Matrix::GradientSolver(const AbstractMatrix &A, const std::vector<double> &b, double eps, int max){

    size_t n = A.n();

    std::vector<double> x(n, 0.0);
    std::vector<double> r(n);
    std::vector<double> z(n);

    std::vector<double> Az;

    A.multiply(x, r); //r

    for (int i = 0; i < n; ++i) {
        r[i] = b[i] - r[i];
        z[i] = r[i];
    }

    double rr_1 = dot_vect(r, r, n);
    double r0 = sqrt(rr_1);

    for (int iter = 0; iter < max; ++iter) {

        A.multiply(z, Az);
        double Az_z = dot_vect(z, Az, n);    

        // 1
        double alpha = rr_1 / Az_z;

        // 2, 3
        for (int i = 0; i < n; ++i) {
            x[i] += alpha * z[i];
            r[i] -= alpha * Az[i];
        }

        double rr = dot_vect(r, r, n);
        if (std::sqrt(rr) < eps*std::sqrt(dot_vect(b, b, n))) {
            break; // Критерий завершения
        }

        //4
        double betta = (rr / rr_1);

        // 5
        for (int i = 0; i < n; ++i) {
            z[i] = r[i] + betta * z[i];
        }
        rr_1 = rr;
        
    }
    return x;
}

