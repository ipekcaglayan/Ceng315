#ifndef THE5_THE5_H
#define THE5_THE5_H


#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>


int recursiveMethod(int W, int L, bool** partitions, int* numberOfCalls);
int memoizationMethod(int W, int L, bool** partitions, int* numberOfCalls);
int bottomUpMethod(int W, int L, bool** partitions, int* numberOfIterations);


#endif //THE5_THE5_H


