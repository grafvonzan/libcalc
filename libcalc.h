//LibCalc Version .1
//Written by Zander S. Ackerman
//All Rights Reserved

#ifndef libcalc
#define libcalc

#define PI 3.14159265358979323846264338327950288419716
//Utility
//Create a multidimensional array using dynamic memory
double initArray(int[]);

//Structures

//Classes
//Used to hold coordinate values.
class coordinate;
class vector;

//holds arrays of coordinate values
class function;

//Conversion Functions
double degToRad(double);
double radToDeg(double);

//Operations

//Magnitude
double magnitude(vector);
//Distance
double distance(coordinate, coordinate);
//Dot-Product
double dotProduct(vector, vector);
//Cross-Product
vector crossProduct(vector, vector);
//Derivative
function derivative(function);
//Anti-Derivative
function antiDerivative(function);
//Integrate



#endif
