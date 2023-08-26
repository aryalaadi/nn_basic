/*
using talyor's series to train a sine approximator model with a single layer perceptron

x = [1, x^2, x^3, x^4, ...]
w = [a, a1, a2, a3, a4, ...]

sigmoid(x*w) -> w -= matrix gradient descent -> loop until the graident of the cost function is close to zero 
after training sin_approx(x) = dot_product([1, x^2, x^3, ...], [trained weight function]) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <math/sigmoids.h>
#include <math/matrix.h>

double* cost(double w[]);

double dataset[128][2];

void generate_data();
void test_accuracy();

int main(void) {
    generate_data();

    double rate = 1e-5;
    double weights[] = {0.12, 0.34, 0.21, 0.56};
    for (int runs = 0; runs<128; runs++) {
        double* adjusts = cost(weights);
        weights[0] -= rate * adjusts[0];
        weights[1] -= rate * adjusts[1];
        weights[2] -= rate * adjusts[2];
        weights[3] -= rate * adjusts[3];
        free(adjusts);
    }

    printf("%lf %lf %lf %lf", weights[0], weights[1], weights[2], weights[3]);
    return  0;
}

void generate_data() {
    srand(0);
    for (int i=0; i<128; i++) {
        dataset[i][0] = (double)rand() / RAND_MAX * M_PI * 2;
        dataset[i][1] = sin(dataset[i][0]);
    }
}

double* cost(double w[]) {
    double out = 0;
    double out1 = 0;
    double out2 = 0;
    double out3 = 0;
    for (int i=0; i<128; i++) {
        double x = dataset[i][0];
        double x_[] =  {1, pow(x, 1), pow(x, 2), pow(x, 3)}; 
        out += 2*(_1xn_dotproduct(w, x_, 4) - dataset[i][1]);
        out1 += pow(out, 2);
        out2 += pow(out, 3);
        out3 += pow(out, 4);
    }
    
    double *ret = malloc(sizeof(double)*4);
    ret[0] = out;
    ret[1] = out1;
    ret[2] = out2;
    ret[3] = out3;

    return ret; 
}