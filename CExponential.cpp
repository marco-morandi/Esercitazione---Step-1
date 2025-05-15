/// @file CExponential.cpp
///	@brief class Exponential: implementations of the exponential function
/// @author Marco Morandi - Igor Coppola

#include <iostream> 

using namespace std;

#include "CExponential.h"

/// @brief default constructor
Exponential::Exponential() {

	cout << "*** Exponential - Default Constructor ***\n\n";

	SetParam(0,0,0);
	
}

/// @brief costructor
/// @param b base of the exponent
/// @param k coefficient of the base
/// @param c coefficient of the exponent 
Exponential::Exponential(double b, double k, double c)
{
    cout << "*** Exponential - Constructor ***\n\n";
    SetParam(b, k, c);
}

/// @brief copy costructor 
Exponential::Exponential(const Exponential &E)
{
    cout << "*** Exponential - Copy Constructor ***\n\n";
    SetParam(E.b_coeff, E.k_coeff, E.c_coeff);
}

/// @brief destructor 
Exponential::~Exponential()
{
    cout << "*** Exponential - Destructor ***\n\n";
}

/// @brief operator =
/// @param p reference to the exponential function on the right side of the operator
/// @return reference to the exponential function on the left side of the operator
Exponential& Exponential::operator=(const Exponential& p)
{
    cout << "*** Exponential - Operator = ***\n\n";
    SetParam(p.b_coeff, p.k_coeff, p.c_coeff);
}

/// @brief operator == 
/// @param p reference to the exponential function on the right side of the operator
/// @return true if every param of the exponential function on the left is equal to the right exponential function param

bool Exponential::operator==(const Exponential& p)
{
    if(b_coeff == p.b_coeff && k_coeff == p.k_coeff && c_coeff == p.c_coeff)
    {
        return true;
    }
    return false;
}


/// @brief Reset
void Exponential :: Reset()
{
    SetParam(0, 0, 0);
}

