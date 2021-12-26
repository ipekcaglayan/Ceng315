#ifndef THE_4_THE4_H
#define THE_4_THE4_H

#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>


int recursive_sln(int i, int*& arr, int &number_of_calls);
int memoization_sln(int i, int*& arr, int*& mem);
int dp_sln(int size, int*& arr, int*& mem);

#endif //THE_4_THE4_H
