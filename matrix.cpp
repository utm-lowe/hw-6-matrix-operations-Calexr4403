/**
 * @file matrix.cpp
 * @author Alex Ritter
 * @brief Implementation of the Matrix class and its overloaded operators.
 * @version 0.1
 * @date 2026-03-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "matrix.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) 
{
    ar = new double*[m];
    for (int i = 0; i < m; ++i) {
        ar[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            ar[i][j] = 0.0; // Initialize all elements to zero
        }
    }
}

Matrix::Matrix(const Matrix& rhs) : m(rhs.m), n(rhs.n) 
{
    ar = new double*[m];
    for (int i = 0; i < m; ++i) {
        ar[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            ar[i][j] = rhs.ar[i][j]; // Copy each element from the source matrix
        }
    }
}

Matrix::~Matrix() 
{
    for (int i = 0; i < m; ++i) {
        delete[] ar[i]; // Delete each row
    }
    delete[] ar; // Delete the array of pointers
}

int Matrix::getRows() const 
{
    return m;
}

int Matrix::getCols() const 
{
    return n;
}

double& Matrix::at(unsigned int row, unsigned int col) 
{
    if (row >= m || col >= n) {
        throw std::out_of_range("Index out of range");
    }
    return ar[row][col];
}

const double& Matrix::at(unsigned int row, unsigned int col) const 
{
    if (row >= m || col >= n) {
        throw std::out_of_range("Index out of range");
    }
    return ar[row][col];
}

Matrix& Matrix::operator=(const Matrix& rhs) 
{
    if (this == &rhs) {
        return *this; // Handle self-assignment
    }

    // Clean up existing resources
    for (int i = 0; i < m; ++i) {
        delete[] ar[i];
    }
    delete[] ar;

    // Copy dimensions
    m = rhs.m;
    n = rhs.n;

    // Allocate new memory and copy elements
    ar = new double*[m];
    for (int i = 0; i < m; ++i) {
        ar[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            ar[i][j] = rhs.ar[i][j];
        }
    }

    return *this;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) 
{
    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    Matrix result(m1.getRows(), m1.getCols());
    for (int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m1.getCols(); ++j) {
            result.at(i, j) = m1.at(i, j) + m2.at(i, j);
        }
    }
    return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2) 
{
    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()) {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction");
    }

    Matrix result(m1.getRows(), m1.getCols());
    for (int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m1.getCols(); ++j) {
            result.at(i, j) = m1.at(i, j) - m2.at(i, j);
        }
    }
    return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) 
{
    if (m1.getCols() != m2.getRows()) {
        throw std::invalid_argument("Number of columns of the first matrix must equal the number of rows of the second matrix for multiplication");
    }

    Matrix result(m1.getRows(), m2.getCols());
    for (int i = 0; i < m1.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            double sum = 0.0;
            for (int k = 0; k < m1.getCols(); ++k) {
                sum += m1.at(i, k) * m2.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }
    return result;
}

Matrix operator*(const Matrix& m, double scalar) 
{
    Matrix result(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            result.at(i, j) = m.at(i, j) * scalar;
        }
    }
    return result;
}

Matrix operator*(double scalar, const Matrix& m) 
{
    return m * scalar; // Reuse the previous operator for scalar multiplication
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) 
{
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            os << std::setw(10) << m.at(i, j) << " "; // Format output with fixed width
        }
        os << std::endl; // New line after each row
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m) 
{
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            is >> m.at(i, j); // Read each element from the input stream
        }
    }
    return is;
}