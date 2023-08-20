/*
using talyor's series to train a sine approximator model with a single layer perceptron

x = [1, x^2, x^3, x^4, ...]
w = [a, a1, a2, a3, a4, ...]

sigmoid(x*w) -> w -= matrix gradient descent -> loop until the graident of the cost function is close to zero 
after training sin_approx(x) = dot_product([1, x^2, x^3, ...], [trained weight function]) 
*/
