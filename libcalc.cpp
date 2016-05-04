//libcalc Calculus Library v.1
//Written by Zander Scott Ackerman
//GNU GPLv3

#include "libcalc.h"
#include <iostream>
#include <math.h>


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
    private:
		int dimension;
		double* location;
	public:
		coordinate(int dim){
			dimension=dim;
			location=new double[dim];
		}
		void setDimension(int input){
			dimension=input;
		}
		int getDimension(){
			return dimension;
		}
		void setLocation(double input[]){
			location=input;
		}
		double* getLocation(){
			return location;
		}
		double getElement(int key){
			return location[key];
		}
};

class vector : public coordinate{
	private:
		double* direction;
	public:
		vector(int dim) : coordinate(dim){
			setDimension(dim);
			double* tempLocation=new double[dim];
			setLocation(tempLocation);
			direction=new double[dim];
		}
		void setDirection(double input[]){
			direction=input;
		}
		double* getDirection(){
			return direction;
		}
		double getDirectionElement(int element){
			//element 0=x, element 1=y, etc.
			return direction[element];
		}


};

double degToRad(double input){
	double output;
	output=(input/180)*PI;
	return output;
}

double radToDeg(double input){
	double output;
	output=(input/PI)*180;
	return output;
}

double magnitude(vector input){
	double output=0;
	int dim=input.getDimension();
	int i=0;
	while (i<dim){
		output=output+pow((input.getDirectionElement(i)),2);
		i++;
	}
	output=pow(output, .5);
	return output;
}

double distance(coordinate inputA, coordinate inputB){
	double output;
	int i=0;
	int dimA=inputA.getDimension();
	int dimB=inputB.getDimension();

	//These two conditionals handle obtaining the square of the difference between the coordinates positions
	if(dimA>=dimB){
		while(i<dimA){
			if(i>=dimB){
				//Input B doesn't even have an element at i, if we have gone into this conditional.
				output=output+pow(inputA.getElement(i),2);
			}
			else{
				output=output+pow((inputA.getElement(i)-inputB.getElement(i)),2);
			}
			i++;
		}
	}
	else{
		while(i<dimB){
					if(i>=dimA){
						//Input A doesn't even have an element at i, if we have gone into this conditional.
						output=output+pow(inputB.getElement(i),2);
					}
					else{
						output=output+pow((inputA.getElement(i)-inputB.getElement(i)),2);
					}
					i++;
				}
	}

	//To actually get the distance, we take the square root of output
	output=pow(output,.5);

	return output;
}

double dotProduct(vector inputA, vector inputB){
	double output;
		int dimA=inputA.getDimension();
		int dimB=inputB.getDimension();
		int dimLarger;
		if (dimA>=dimB){
			dimLarger=dimA;
		}
		else{
			dimLarger=dimB;
		}
		int i=0;
		while(i<dimLarger){
			output=output+(inputA.getElement(i)*inputB.getElement(i));
			i++;
		}
	return output;

}

//Warning: only works in 3-Space!
vector crossProduct(vector A, vector B){
	vector output(3);
	if(A.getDimension()!=3 || B.getDimension()!=3){
		output.setDirection(NULL);
		return output;
	}
	else{
		double tempDirection[3];
		//Using Definition of 3 Space Cross Product
		tempDirection[0]=(A.getElement(1)*B.getElement(2))-(B.getElement(1)*A.getElement(2));
		tempDirection[1]=(A.getElement(0)*B.getElement(2))-(B.getElement(0)*A.getElement(2));
		tempDirection[2]=(A.getElement(0)*B.getElement(1))-(B.getElement(0)*A.getElement(1));
		output.setDirection(tempDirection);
	}
	return output;
}



