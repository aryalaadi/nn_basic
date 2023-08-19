#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Single Layer Perceptron with a Single Parameter 
Programmed to approximate linear functions 

Dataset 		:	{1:2, 2:4, 3:6, 4:8, ...}	[f(x)=2x]
Cost Function 		: 	C(w) = (sum(fw(x)-f(x)))) / n 	[w: weight]
Weight Adjustment 	:	w -= (cost(w+h)-cost(w))/h*rate	[h: 1e-5, rate: 1e-3] 
Training Eras		: 	128 
Accuracy		:	~99.999% 			[w converges to 1.999995]	
*/

int dataset[16][2];


// Mean Squared Error 
// https://en.wikipedia.org/wiki/Mean_squared_error
// This MSE cost function is used to measure the quality of the estimation made
double cost(double w) {
	double out = 0.0f;
	for (int i = 1; i<=16; i++) {
		double x = dataset[i][0];
		double fx = x*w;
		double d = fx-dataset[i][1];
		out += d*d;
	}
	return out/16;
}


int main(void) {
	for (int i = 1; i<=16; i++) {
		dataset[i][0] = i;
		dataset[i][1] = i*2;					// f(x) = 2x
	}

	double w = (double)rand()/(double)RAND_MAX*4;			// Random initial weight 

	double h = 1e-5;						// Infinitesimal approx for derivatives 
	double rate = 1e-3;						// Rate of training
									// Ideal: rate>>h	
	double dw;							
	for (int era = 0; era<128; era++) { 				// Training loop 
		dw = (cost(w+h)-cost(w))/h;				// Infinitesmial change in MSE 
		w -= dw*rate;						// Adjusting weight based on change in MSE
		printf("era %d dcost %lf w %lf\n", era, dw, w);		// https://en.wikipedia.org/wiki/Gradient_descent
	}
}

/*
Aaditya Aryal 2023
Public Domain
*/
