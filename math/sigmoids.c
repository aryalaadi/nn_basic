#include <math/sigmoids.h>

//https://en.wikipedia.org/wiki/Logistic_function
double logistic_sigmoid(double x) {
	return (1/(1+exp(-1*x)));
}

//https://en.wikipedia.org/wiki/Algebraic_function
double algebraic_sigmoid(double x) {
	return (x/sqrt(1+(x*x)));
}

/*
tanh() in math.h
atan() in math.h
erf()  in bits/mathcalls.h
*/
