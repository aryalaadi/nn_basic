#include <math/approximators.h>

#define eps 1e-5
#define dx  1e-3

// fininte difference, works good  
float derivatives(float (*func)(float), float x) {
	return (((*func)(x+eps))-((*func)(x)))/eps;
}

// finite sum, works decent but painfully slow at larger ranges
float integral(float (*func)(float),  float lower, float upper) {
	float n = lower; 
	float sum = 0; 
	while (n!=upper) {
		sum += (*func)(n)*dx;
		n+=1e-3;
	}
}

// finite limit, works good 
float limit((*func)(float), float h) {
	return (*func)(h-eps);
}
