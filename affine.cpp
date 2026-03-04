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

        point = transform * point;

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

    Matrix identity(3,3);
    identity.at(0,0) = 1.0;
    identity.at(1,1) = 1.0;
    identity.at(2,2) = 1.0;
    return identity;
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
    double radians = angle * M_PI / 180.0; // Convert angle to radians
    Matrix rotation(3,3);
    rotation.at(0,0) = cos(radians);
    rotation.at(0,1) = -sin(radians);
    rotation.at(1,0) = sin(radians);
    rotation.at(1,1) = cos(radians);
    rotation.at(2,2) = 1.0; // Set the bottom-right element to 1
    return rotation;
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
    Matrix scale(3,3);
    scale.at(0,0) = sx;
    scale.at(1,1) = sy;
    scale.at(2,2) = 1.0; // Set the bottom-right element to 1
    return scale;
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
    Matrix translation(3,3);
    translation.at(0,0) = 1.0;
    translation.at(1,1) = 1.0;
    translation.at(0,2) = tx;
    translation.at(1,2) = ty;
    translation.at(2,2) = 1.0; // Set the bottom-right element to 1
    return translation;
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
        switch(choice) {
            case 'T':
                cout << "Enter x and y translation: ";
                cin >> x >> y;
                result = translate(x, y) * result;
                break;
            case 'R':
                cout << "Enter the angle of rotation (degrees): ";
                cin >> angle;
                result = transRotate(angle) * result;
                break;
            case 'S':
                cout << "Enter the x and y scaling factors: ";
                cin >> x >> y;
                result = transScale(x, y) * result;
                break;
            case 'D':
                // Done, do nothing
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

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
    double x, y;
    cout << "Enter a point (x y): ";
    cin >> x >> y;
    Matrix point(3,1);
    point.at(0,0) = x;
    point.at(1,0) = y;
    point.at(2,0) = 1.0;
    return point;
}