//libcalc Calculus Library v.1
//Written by Zander Scott Ackerman
//GNU GPLv3

#include "libcalc.h"
#include <iostream>


double initArray(int data[], int dimensionCount){
    //data: element 0= number of dimensions
    //element 1 through inf define the size of each dimension
    //dimensionCount keeps track of the current dimension being manipulated by the function


    //Allocate dynamic memory for the current dimension
    double* output;
    output=new double[data[dimensionCount]];

    int i=dimensionCount;

    while(i<data[dimensionCount]){
	    if( !(output[i]= initArray(data, dimensionCount++))){
	    	std::cout<< "Error! Out of Memory!";
	    	break;
	    }

	    i++;
    }
    //returning the generated array tacks on the generated dimension to the lower dimension preceding it
    double array=*output;
    return array;
}



class coordinate{
		int dimension;
		double* location;
	public:
		coordinate(int dim){
			dimension=dim;
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

};

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



