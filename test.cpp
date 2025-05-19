// test file for classes Power, Exponential and Function

#include <iostream>
#include <cstdlib>

#include "CFunction.h"
#include "CExponential.h"
#include "Power.h"
#include "Polynomial.h"

int main() {

    // ************** test for class Exponential ************** 

    // instatiation of the objects
    Exponential e1;
    Exponential e2(2, 4, -1);
    Exponential e3(e2);

    // first dumps of the objects
    cout << "*** Exponential function e1 ***\n";
    e1.Dump();

    cout << "*** Exponential function e2 ***\n";
    e2.Dump();

    cout << "*** Exponential function e3 ***\n";
    e3.Dump();

    // test of operator ==
    if(e2 == e3)
        cout << "e2 and e3 are the same function\n\n";
    else 
        cout << "e2 and e3 are not the same function\n\n";

    // test of SetParam() and operator = 
    e3.SetParam(5, -3, 2);
    cout << "*** Exponential function e3 ***\n";
    e3.Dump();

    e1 = e3;

    cout << "*** Exponential function e1 ***\n";
    e1.Dump();

    // test of operator +
    Exponential e4;
    e4 = e3 + e2;

    cout << "*** Exponential function e4 ***\n";
    e4.Dump();

    e4 = e3 + e1;

    cout << "*** Exponential function pw4 ***\n";
    e4.Dump();

    // ************** test for class Power ************** 

    // instatiation of the objects
    Power pw1;
    Power pw2(-3, 4);
    Power pw3(pw2);

    // first dumps of the objects
    cout << "*** Power function pw1 ***\n";
    pw1.Dump();

    cout << "*** Power function pw2 ***\n";
    pw2.Dump();

    cout << "*** Power function pw3 ***\n";
    pw3.Dump();

    // test of operator ==
    if(pw2 == pw3)
        cout << "pw2 and pw3 are the same function\n\n";
    else 
        cout << "pw2 and pw3 are not the same function\n\n";

    // test of SetParam() and operator = 
    pw3.SetParam(6, 0.5);
    cout << "*** Power function pw3 ***\n";
    pw3.Dump();

    pw1 = pw3;

    cout << "*** Power function pw1 ***\n";
    pw1.Dump();

    // test of operator +
    Power pw4;
    pw4 = pw3 + pw2;

    cout << "*** Power function pw4 ***\n";
    pw4.Dump();

    pw4 = pw3 + pw1;

    cout << "*** Power function pw4 ***\n";
    pw4.Dump();

    // ************** test for class Polynomial **************

    // instatiation of the objects
    double coeff[4] = { 0., 1.2, -3.6, 4. };
    int size = sizeof(coeff) / sizeof(coeff[0]);

    Polynomial p1;
    Polynomial p2(coeff, size);
    Polynomial p3(p2);

    // first dumps of the objects
    cout << "*** Polynomial function p1 ***\n";
    p1.Dump();

    cout << "*** Polynomial function p2 ***\n";
    p2.Dump();

    cout << "*** Polynomial function p3 ***\n";
    p3.Dump();

    // test of operator ==
    if(p2 == p3)
        cout << "p2 and p3 are the same function\n\n";
    else 
        cout << "p2 and p3 are not the same function\n\n";

    // test of SetParam() and operator = 
    double new_coeff[4] = { 5., 8., -3.2, 1.7 };
    int new_size = sizeof(new_coeff) / sizeof(new_coeff[0]);

    p3.SetNewParam(new_coeff, new_size);
    cout << "*** Polynomial function p3 ***\n";
    p3.Dump();

    p1 = p3;

    cout << "*** Polynomial function p1 ***\n";
    p1.Dump();


    // ************** test for Polymorphism **************

    // creating array of pointers to Function objects
    Function* array[3];
    array[0] = &e2;
    array[1] = &pw2;
    array[2] = &p2;

    srand(time(0)); // get a different random number each time the program runs

    // testing virtual functions of base class Function

    // testing GetValue() for each derived class for a random value of the independent variable
    for (int i = 0; i < 3; i++) {
        int x = rand() % 21;
        double res = array[i]->GetValue(x);

        cout << "The value of function " << i << " in the array for x = " << x << " is: " << res << "\n\n";
    }

    // testing Dump() with polymorphism
    for (int i = 0; i < 3; i++) {
    
        cout << "*** Function " << i << " ***\n";
        array[i]->Dump();

    }

    return 0;

}
