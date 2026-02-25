/**
 * @file matrix_test.cpp
 * @brief A basic test of the matrix class.
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include "matrix.h"

using namespace std;
int main()
{
    Matrix a{3,3};
    Matrix b{3,3};

    // Test out the input
    cout << "Enter a 3x3 matrix (A)" << endl;
    cin >> a;
    cout << "Enter a 3x3 matrix (B)" << endl;
    cin >> b;

    // Test out the output
    cout << "Matrix A" << endl;
    cout << a << endl;

    cout << "Matrix B" << endl;
    cout << b << endl;

    // Test out matrix arithmetic
    cout << "A + B" << endl << a+b << endl;
    cout << "A - B" << endl << a-b << endl;
    cout << "A * B" << endl << a*b << endl;

    // Test out scalar multiplication
    cout << "2*A" << endl << 2*a << endl;
    cout << "A*2" << endl << a*2 << endl;
}