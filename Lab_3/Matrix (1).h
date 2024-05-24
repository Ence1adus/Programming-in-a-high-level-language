#pragma once
#include <iostream>
#include "sample.h"
#include<complex>
#include <vector>
#include <fstream>
class Matrix : public Sample<double>
{
public:
    Matrix() = default;
    Matrix(int size_x, int size_y) : Sample<double>(size_x, size_y) {}
    ~Matrix() = default;

    Matrix IdentityMatrix(int size_x);
    Matrix operator*(const Matrix& temp);
    Matrix operator~();
    Matrix operator/(const Matrix& temp);
    Matrix operator/=(const Matrix& temp);
    void operator*=(const Matrix& temp);
    void CanMul(const Matrix& temp);

};


Matrix Matrix::IdentityMatrix(int size_x)
{
    Matrix result_data(size_x, size_x);

    for (int i = 0; i < m_size_x; i++) {
        for (int j = 0; j < m_size_x; j++) {
            if (i == j) {
                result_data(i, j) = 1;
            }
            else {
                result_data(i, j) = 0;
            }
        }
    }
    return result_data;

}

Matrix Matrix::operator*(const Matrix& temp)
{
    if (this->m_size_y == temp.m_size_x) {
        Matrix result(this->m_size_x, temp.m_size_y);
        for (int i = 0; i < this->m_size_x; i++) {
            for (int j = 0; j < temp.m_size_y; j++) {
                for (int k = 0; k < this->m_size_y; k++) {
                    result(i, j) += this->operator()(i, k) * temp.operator()(k, j);
             
                }
            }
        }
        return result;
    }
    else {

        std::cerr << "Incompatible matrix sizes for multiplication" << std::endl;
        //Возврат  матрицы
        return *this;
    }
}

Matrix Matrix::operator~() {
    Matrix transposed(this->m_size_y, this->m_size_x);
    for (int i = 0; i < this->m_size_x; i++) {
        for (int j = 0; j < this->m_size_y; j++) {
            transposed(j, i) = this->operator()(i, j);
        }
    }
    return transposed;
}

Matrix Matrix::operator/(const Matrix& temp)
{

    try {
        throw std::runtime_error("My exception.");
    }
    catch (const std::exception& e) {
        std::cout << "The exception is caught" << e.what() << std::endl;
    }
    return *this;
}

Matrix Matrix::operator/=(const Matrix& temp)
{
    try {
        throw std::runtime_error("My exception.");
    }
    catch (const std::exception& e) {
        std::cout << "The exception is caught" << e.what() << std::endl;
    }
    return *this;
}

void Matrix::operator*=(const Matrix& temp)
{
    if (m_size_x != m_size_y) {
        throw std::runtime_error("Matrix is not square");
    }
    else {


        for (int i = 0; i < this->m_size_x; i++) {
            for (int j = 0; j < temp.m_size_y; j++) {
                for (int k = 0; k < this->m_size_y; k++) {
                    this->operator()(i, k) = this->operator()(i, k) * temp.operator()(k, j);
                }
            }
        }
    }

}

void Matrix::CanMul(const Matrix& temp)
{

    if (this->m_size_y == temp.m_size_x)
    {
        cout << "Can MUL"<<endl;
    }
    else
    {
        cout << "CANT MUL"<<endl;
    }
}
