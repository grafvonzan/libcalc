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




coordinate::coordinate(int dim){
	dimension=dim;
	location=new double[dim];
}
void coordinate::setDimension(int input){
	dimension=input;
}
int coordinate::getDimension(){
	return dimension;
}
void coordinate::setLocation(double input[]){
	location=input;
}
double* coordinate::getLocation(){
	return location;
}
double coordinate::getElement(int key){
	return location[key];
}
void coordinate::modifyElement(int dimension, double delta){
	location[dimension]=location[dimension]+delta;
}
void coordinate::printCoordinate(){
	std::cout<<"Location:";
	int dim=0;
	while(dim<dimension){
		std::cout<<getElement(dim)<<",";
		dim++;
	}
	std::cout<<"\n";


}




vector::vector(int dim) : coordinate(dim){
	setDimension(dim);
	double* tempLocation=new double[dim];
	setLocation(tempLocation);
	direction=new double[dim];
}
void vector::setDirection(double input[]){
	direction=input;
}
double* vector::getDirection(){
	return direction;
}
double vector::getDirectionElement(int element){
	//element 0=x, element 1=y, etc.
	return direction[element];
}
void vector::printVector(){
	std::cout<<"Location:";
	int dim=0;
	while(dim<getDimension()){
		std::cout<<getElement(dim)<<",";
		dim++;
	}
	std::cout<<"\n";
	std::cout<<"Direction:";
	dim=0;
	while(dim<getDimension()){
		std::cout<<getDirectionElement(dim)<<",";
		dim++;
	}
	std::cout<<"\n";


}



function::function(coordinate* arrayTemp, int sizeOfArray, int tempDim){
	array=arrayTemp;
	size=sizeOfArray;
	dimension=tempDim;
}
coordinate* function::getArray(){
	return array;
}
int function::getSize(){
	return size;
}
int function::getDimension(){
	return dimension;
}
//I guess this is more a partial
//
coordinate* function::takeDerivative2D(int variable, int withRespect ){
	int i=1;
	double location[2];
	coordinate* derivative;
	while(i<size){
		derivative[i-1]= *(new coordinate(2));
		location[0]=array[i].getElement(withRespect);
		location[1]=(array[i+1].getElement(variable)-array[i-1].getElement(variable))/(array[i+1].getElement(withRespect)-array[i-1].getElement(withRespect));
		derivative[i-1].setLocation(location);
		i++;
	}
	return derivative;
}
coordinate* function::takeIntegral2D(int variable, int withRespect){
	int i=1;
	double location[2];
	coordinate* integral;
	while(i<size){
		integral[i-1]=*(new coordinate(2));
		location[0]=array[i].getElement(withRespect);
		location[1]=(array[i].getElement(variable))*(array[i+1].getElement(withRespect)-array[i-1].getElement(withRespect));
		integral[i-1].setLocation(location);
		i++;
	}
	return integral;
}
void function::printFunction2D(){
	int i=0;
	while(i<getSize()){
		std::cout <<i<<"\n"<<"x="<<array[i].getElement(0)<<"\n"<<"y="<<array[i].getElement(1);
		i++;
	}
}

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
			output=output+(inputA.getDirectionElement(i)*inputB.getDirectionElement(i));
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
		tempDirection[0]=(A.getDirectionElement(1)*B.getDirectionElement(2))-(B.getDirectionElement(1)*A.getDirectionElement(2));
		tempDirection[1]=(A.getDirectionElement(0)*B.getDirectionElement(2))-(B.getDirectionElement(0)*A.getDirectionElement(2));
		tempDirection[2]=(A.getDirectionElement(0)*B.getDirectionElement(1))-(B.getDirectionElement(0)*A.getDirectionElement(1));
		output.setDirection(tempDirection);
	}
	return output;
}



