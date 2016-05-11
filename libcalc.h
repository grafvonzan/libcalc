//libcalc Calculus Library v.1
//Written by Zander Scott Ackerman
//GNU GPLv3

#ifndef libcalc
#define libcalc

#define PI 3.14159265358979323846264338327950288419716
//Utility
//Create a multidimensional array using dynamic memory
double initArray(int[], int);

//Structures

//Classes
//Used to hold coordinate values.
class coordinate{
private:
	int dimension;
	double* location;

public:
	coordinate(int);
	void setDimension(int);
	int getDimension();
	void setLocation(double input[]);
	double* getLocation();
	double getElement(int);
	void modifyElement(int, double);
	void printCoordinate();


};
class vector : public coordinate{
private:
	double* direction;
public:
	vector(int);
	void setDirection(double[]);
	double* getDirection();
	double getDirectionElement(int);
	void printVector();


};

//holds arrays of coordinate values
class function{
private:
	coordinate* array;
	int size;
	int dimension;
public:
	function(coordinate*, int, int);
	coordinate* getArray();
	int getSize();
	int getDimension();
	coordinate* takeDerivative2D(int, int);
	coordinate* takeIntegral2D(int, int);
	void printFunction2D();


};

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
