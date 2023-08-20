#include "math/matrix.h"

// 1xn matrix dot product 
double _1xn_dotproduct(float a[], float[b], int n) {
	float res = 0;
	for (int i=0; i<n; i++) {
		res += a[i]*b[i];
	}
}
