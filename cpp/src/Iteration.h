#ifndef ITERATION_H
#define ITERATION_H

#include <valarray>
std::valarray<double> Iteration(std::valarray<std::valarray<double>> &ms, double Eps = 10e-5);

#endif //ITERATION_H