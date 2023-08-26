#include <math/matrix.h>

// 1xn matrix dot product 
double _1xn_dotproduct(double a[], double b[], int n) {
	double res = 0;
	for (int i=0; i<n; i++) {
		res += a[i]*b[i];
	}
	return res;
}
