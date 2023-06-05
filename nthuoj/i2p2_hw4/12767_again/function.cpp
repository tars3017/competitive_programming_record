#include "function.h"

Matrix::~Matrix() {
    for (int i = 0; i < n; ++i) {
        delete [] matrix[i];
    }
    n = 0;
}
Matrix::Matrix(int n) {
    matrix = new long long* [n]();
    this->n = n;
    for (int i = 0; i < n; ++i) {
        matrix[i] = new long long [n]();
    }
}

Matrix::Matrix(const Matrix& ref):Matrix(ref.n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = ref(i, j);
        }
    }
}

Matrix& Matrix::operator=(const Matrix& ref) {
    Matrix(ref.n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = ref(i, j);
        }
    }
    return *this;
}

long long& Matrix::operator()(const int& row, const int& column) const{
    return matrix[row][column];
}

void Matrix::toIdentity() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) matrix[i][j] = 1;
            else matrix[i][j] = 0;
        }
    }
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    Matrix res(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res(i, j) = 0;
            for (int k = 0; k < n; ++k) {
                res(i, j) += matrix[i][k] * rhs(k, j);
                res(i, j) %= mod;
            }
        }
    }
    return res;
}

Matrix Matrix::power(int k) const {
    // cout << "k_times " << k << endl;
    Matrix res(n);
    Matrix tmp = (*this);
    res.toIdentity();
    while (k > 0) {
        if (k % 2 == 1) {
            res = res * tmp;
        }
        tmp = tmp * tmp;
        k = k >> 1;
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << res(i, j) << ' ';
    //     }
    //     cout << endl;
    // }
    return res;
}


Matrix constructMatrix(int n) {
    Matrix mat(n);
    mat.toZero();
    for (int i = 0; i < n-1; ++i) {
        mat(i, i+1) = 1;
    }
    for (int i = 0; i < n; ++i) {
        mat(n-1, i) = 1;
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << mat(i, j) << ' ';
    //     }
    //     cout << endl;
    // }
    return mat;
}