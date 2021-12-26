#include "the4.h"


using namespace std;
int recursive_sln(int i, int*& arr, int &number_of_calls){ //direct recursive
    number_of_calls+=1;
    if(i<3){
        int max=arr[0];
        for(int j=0; j<=i; j++ ){
            if(arr[j]>max){
                max = arr[j];
            }
        }
        return max;
    }

    return(std::max(recursive_sln(i-3, arr, number_of_calls)+arr[i], recursive_sln(i-1, arr, number_of_calls)));


}


int memoization_sln(int i, int*& arr, int*& mem){ //memoization
    if(i<3){
        switch (i) {
            case 0:
                mem[0] = arr[0];
                return mem[0];
            case 1:
                mem[1] = arr[1]>arr[0]? arr[1]: arr[0];
                return mem[1];

            case 2:
                int a = std::max(arr[1],arr[0]);
                mem[2] = a > arr[2] ? a: arr[2];
                return mem[2];

        }
    }
    if(mem[i-3]==-1){
        mem[i-3] = memoization_sln(i-3, arr, mem);
    }
    if(mem[i-1]==-1){
        mem[i-1] = memoization_sln(i-1, arr, mem);

    }
    mem[i] = std::max(mem[i-3]+arr[i], mem[i-1]);
    return(mem[i]);

}



int dp_sln(int size, int*& arr, int*& mem){ //dynamic programming
    int x,y;
    if(size>0){
        mem[0] = arr[0];
    }
    if(size>1){
        mem[1] = arr[1]>arr[0]? arr[1]: arr[0];
    }
    if(size>2){
        int a = std::max(arr[1],arr[0]);
        mem[2] = a > arr[2] ? a: arr[2];
    }
    for(int i=3; i<size;i++){
        x = mem[i-3] +arr[i];
        y = mem[i-1];
        mem[i] = x > y ? x : y;
    }
    return mem[size-1];
}

