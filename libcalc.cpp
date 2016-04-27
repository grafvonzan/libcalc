//LibCalc Version .1
//Written by Zander S. Ackerman
//All Rights Reserved

#include <libcalc.h>

double* initArray(int data[], int startElement, int dimensionCount){
	//data: element 0= number of dimensions
	//element 1 through inf define the size of each dimension

	double* output;
	output=new double[data[startElement]];

	int i=dimensionCount;

	while(i<data[0]){
		output[i]= initArray(data[], startElement++, i++);
		i++;
	}
	return output;
}



class coordinate{
		int dimension;
		double* location;
	public:
		coordinate(int dim){
			dimension=dim;
			double* location;
			location=new double[dim];
		}
		void setDimension(int);
		int getDimension();
		void changeLocation(double[]);
		double getLocation();
};

class vector : coordinate{
		double direction[];
	public:
		vector();
		void changeDirection(double[]);
		double getDirection();

}

double degToRad(double input){
	double output;
	output=(input/180)*PI;
	return output;
};

double radToDeg(double input){
	double output;
	output=(input/PI)*180;
	return output;
}



