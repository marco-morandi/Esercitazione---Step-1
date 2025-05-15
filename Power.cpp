/// @file Power.cpp
///	@brief class Power: implementations of the functions
/// @author Marco Morandi

#include <iostream>
#include <cmath>

#include "Power.h"

using namespace std;

/// @brief default constructor
Power::Power() {

    cout << "*** Power - Default Constructor ***\n\n";

    SetParam(0, 0);

}

/// @brief constructor
/// @param k coefficient of independent variable
/// @param e exponent of independent variable
Power::Power(double k, double e) {

    cout << "*** Power - Constructor ***\n\n";

    SetParam(k, e);

}

/// @brief copy constructor
/// @param p reference to object to be copied
Power::Power(const Power& p) {

    cout << "*** Power - Copy Constructor ***\n\n";

    SetParam(p.k_coeff, p.e_coeff);

}

/// @brief destructor
Power::~Power() {

    cout << "*** Power - Destructor ***\n\n";

}

/// @brief overload of operator =
/// @param p reference to object on the right side of the eoperator
/// @return reference to the object on the left side of the operator
Power& Power::operator=(const Power& p) {

    cout << "*** Power - operator = ***\n\n";

    SetParam(p.k_coeff, p.e_coeff);

    return *this;

}

/// @brief overload of operator ==
/// @param p reference to the object on the right side of the operator
/// @return true if the coefficient of the independent variable and the exponent are the same
bool Power::operator==(const Power& p) {

    if (k_coeff == p.k_coeff) {
        if (e_coeff == p.e_coeff)
            return true;
    }

    return false;

}

/// @brief total reset of the object
void Power::Reset() {

    SetParam(0, 0);

}

/// @brief returns the value of the power function given a specific value of the function
/// @param in specific value of the independent variable
