/**
 * @file affine.cpp
 * @author Bob Lowe
 * @brief Perform affine transformations on 2D points.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "matrix.h"
#include <iostream>
#include <cmath>

using namespace std;

// Transformation Matrix Creation Functions

/**
 * @brief Create a 3x3 identity matrix.
 * 
 * @return Matrix 
 */
Matrix transIdent();

/**
 * @brief Rotate about an angle in degrees
 * 
 * @param angle 
 * @return Matrix 
 */
Matrix transRotate(double angle);


/**
 * @brief Scale by factors sx and sy
 * 
 * @param sx 
 * @param sy 
 * @return Matrix 
 */
Matrix transScale(double sx, double sy);

/**
 * @brief Translate by tx and ty
 * 
 * @param tx 
 * @param ty 
 * @return Matrix 
 */
Matrix translate(double tx, double ty);

/**
 * @brief Prompt the user for transformations, return the resultant matrix.
 * 
 * @return Matrix 
 */
Matrix transformMenu();

/**
 * @brief Get the 3 element column vector affine point from the user.
 * 
 * @return Matrix 
 */
Matrix getPoint();

int main() 
{
    Matrix transform = transformMenu();

    // Display the transformation matrix
    cout << "Transformation Matrix: " << endl;
    cout << transform << endl;
    cout << endl;

    // transform points
    while(cin) {
        Matrix point = getPoint();

        // TODO: Write code to transform the point. This should be a single
        //       line of code!
        // YOUR CODE HERE

        // If we have a new point, display it.
        if(cin) {
            cout << "Transformed Point: (" 
                 << point.at(0,0) << ", " << point.at(1,0) << ")" << endl;
        }
    }
}


// build an identity matrix
Matrix transIdent()
{
    // TODO: Build and return a 3x3 identity matrix. The identity matrix
    //       should look like this:
    //         1 0 0
    //         0 1 0
    //         0 0 1
    // YOUR CODE HERE
}


// build a rotation matrix
Matrix transRotate(double angle)
{
    // TODO: Build and return a rotation matrix. The rotation matrix should
    //       look like this:
    //         cos(angle) -sin(angle) 0
    //         sin(angle)  cos(angle) 0
    //         0           0          1
    // YOUR CODE HERE
}

// build a scaling matrix
Matrix transScale(double sx, double sy) 
{
    // TODO: Build and return a scaling matrix. The scaling matrix should
    //       look like this:
    //         sx 0  0
    //         0  sy 0
    //         0  0  1
    // YOUR CODE HERE
}

// build a translation matrix
Matrix translate(double tx, double ty) 
{
    // TODO: build and return the translation matrix. The translation
    //       matrix should look like this:
    //         1 0 tx
    //         0 1 ty
    //         0 0 1
    // YOUR CODE HERE
}

// do the transformation menu
Matrix transformMenu()
{
    Matrix result = transIdent();
    double x,y,angle;
    char choice;

    do {
        // get the choice
        cout << "(T)ranslate, (R)otate, (S)cale, or (D)one? ";
        cin >> choice;
        choice = toupper(choice);

        // TODO: Process the choice. I would do this with a handy switch
        //       statement. Be sure to handle the invalid choice condition!
        // As you build up the transformation matrix, you will need to
        // multiply like this:
        //     result = newTransform * result;
        // Do a quick google search for "Affine Transformation Matrix" to
        // get more details
        // YOUR CODE HERE

    }while(choice != 'D');

    return result;
}


// get the point from the user 
Matrix getPoint() 
{
    // TODO:  Get the x and y coordinate from the user and build a
    //        3x1 matrix consisting of:
    //          x
    //          y
    //          1
    // Return your matrix at the end of the function.
    // YOUR CODE HERE
}