#include "the5.h"
// do not add extra libraries here

/*
W: the width of the field
L: the length of the field
partitions: 2D Boolean array for partitions, if a partition of w x l exists then partitions[x][y] is true.
numberOfCalls/numberOfIterations: method specific control parameter
*/
using namespace std;
int recursiveMethod(int W, int L, bool** partitions, int* numberOfCalls){
    (*numberOfCalls)++;
    if(partitions[W][L]){
        return 0;
    }
    int min1 = W*L , min2 = W*L;
    for(int M=1; M <= W/2; M++){
        min1 = std::min(min1, recursiveMethod(W-M, L, partitions, numberOfCalls) + recursiveMethod(M, L, partitions, numberOfCalls));
    }
    for (int N=1; N<=L/2; N++){
        min2 = std::min(min2, recursiveMethod(W, L-N, partitions, numberOfCalls) + recursiveMethod(W, N, partitions, numberOfCalls));

    }
    return std::min(min1, min2);
//	return std::min( recursiveMethod(W, L, partitions, numberOfCalls), std::min(min1, min2)); // this is a dummy return value. YOU SHOULD CHANGE THIS!
}


int helperMemoization(int W, int L, bool** partitions, int* numberOfCalls, int mem[][601]){
    (*numberOfCalls)++;

    if(mem[W][L]>=0){
        return mem[W][L] ;
    }
    if(partitions[W][L]){
        mem[W][L] = 0;
        return 0;
    }
    int min1 = W*L , min2 = W*L;
    int x, y;
    for(int M=1; M <= W/2; M++){
        x = helperMemoization(W-M, L, partitions, numberOfCalls, mem);
        y = helperMemoization(M, L, partitions, numberOfCalls, mem);

        min1 = std::min(min1, x+y);
    }
    for (int N=1; N<=L/2; N++){

        x = helperMemoization(W, L-N, partitions, numberOfCalls, mem);
        y = helperMemoization(W, N, partitions, numberOfCalls, mem);

        min2 = std::min(min2, x+y);
    }

    mem[W][L] = std::min(min1, min2);
    return mem[W][L];
}

int memoizationMethod(int W, int L, bool** partitions, int* numberOfCalls){
    int mem[601][601];
    for(int i=1; i<601;i++){
        for(int j=1; j<601;j++){
            mem[i][j]= -1;
        }
    }
    (*numberOfCalls)++;
    int result = helperMemoization(W, L, partitions, numberOfCalls , mem);
    return result;

     // this is a dummy return value. YOU SHOULD CHANGE THIS!
}


int bottomUpMethod(int W, int L, bool** partitions, int* numberOfIterations){

    int mem[601][601];
    for(int i=1; i<=W;i++){
        for(int j=1; j<=L;j++){
            if(partitions[i][j]){
                mem[i][j]= 0;
            }
            else{
                mem[i][j] = i*j;
            }
        }
    }

    int x,y, min1, min2;

    for(int r=1; r<=W; r++){
        for (int c=1; c<=L; c++){
            if(!partitions[r][c]){
                min1 = W*L,min2 = W*L;
                for(int M=1; M<r+1;M++){
                    (*numberOfIterations)++;
                    x = mem[r-M][c];
                    y = mem[M][c];
                    min1 = std::min(min1, x+y);
                }
                for(int N=1; N<c+1;N++){
                    (*numberOfIterations)++;
                    x = mem[r][c-N];
                    y = mem[r][N];
                    min2 = std::min(min2, x+y);
                }
                mem[r][c] = std::min(mem[r][c], std::min(min1, min2));

            }

        }
    }

    return mem[W][L];
}
