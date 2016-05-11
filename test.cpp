//A Command Line UI For Testing Algorithms
//libcalc Calculus Library v.1
//Written by Zander Scott Ackerman
//GNU GPLv3

#include <iostream>
#include "libcalc.h"
#include <string>
#include <math.h>
#define DELTA .00001
#define SAMPLE_SIZE 1000

int main(){

	std::string input;
	while(input!="quit"){
		getline(std::cin,input);

		if (input==""){
			//do nothing
		}
		else if(input=="testDerivative"){
			coordinate* testFunction;
			int i=0;
			while(i<SAMPLE_SIZE){
				double tempLocation[2];
				tempLocation[0]=i*DELTA;
				tempLocation[1]=sin(i*DELTA);
				testFunction[i]=*(new coordinate(2));
				testFunction[i].setLocation(tempLocation);
				i++;
			}
			function base=*(new function(testFunction, SAMPLE_SIZE, 2));
			function derivative=*(new function(base.takeDerivative2D(1,0), SAMPLE_SIZE, 2));
			function integral=*(new function(base.takeIntegral2D(1,0), SAMPLE_SIZE, 2));

			std::cout<<"\n"<<"Base function Sin\n";
			base.printFunction2D();

			std::cout<<"\n"<<"Derivative of Sin\n";
			derivative.printFunction2D();

			std::cout<<"\n"<<"Integral of Sin\n";
			integral.printFunction2D();
			std::cout<<"\n\n";
		}

		else if(input=="testVectors"){
			vector vA=*(new vector(3));
			vector vB=*(new vector(3));
			double dirA[3]={4,1,5};
			double dirB[3]={1,2,3};
			double loc[3]={0,0,0};
			vA.setDirection(dirA);
			vB.setDirection(dirB);
			vA.setLocation(loc);
			vB.setLocation(loc);
			vector vCross=crossProduct(vA,vB);
			double dProduct=dotProduct(vA, vB);
			std::cout<<"The dot product of vectors\n";
			std::cout<<"A\n";
			vA.printVector();
			std::cout<<"\n"<<"and B\n";
			vB.printVector();
			std::cout<<"\n"<<"Is equal to "<<dProduct<<"\n";
			std::cout<<"and the cross product of these vectors is\n";
			vCross.printVector();



		}
	}
	return 0;
}
