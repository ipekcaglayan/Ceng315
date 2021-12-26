// this file is for you for testing purposes, it won't be included in evaluation.

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "the4.h"

int getRandomInt(){
        int r = rand()%100;
        return r;
}


void randomArray(int*& array, int size){
    array = new int [size];
    for (int i = 0; i < size; i++){
        int r = getRandomInt();
        array[i] = r;
    }
}


void printArrayInLine(int arr[], int arraySize){
        std::cout << "{ ";
        for(int i = 0; i < arraySize; i++){
                std::cout << arr[i];
        if (i == arraySize - 1){
            continue;
        }else{
            std::cout << ", ";
        }
        }
        std::cout << " }" << std::endl;
}



void test(){
    clock_t begin, end;
        double duration;
    int max_sum_rec;
        int max_sum_mem;
        int max_sum_dp;


    int size = 10;      // max 10000
//    int* arr;
//    randomArray(arr, size);

//    int *arr = new int[5];
//    arr[0] = 8;
//    arr[1] = 64;
//    arr[2] = 55;
//    arr[3] = 34;
//    arr[4] = 46;
    int *arr = new int[10];
    arr[0] = 32;
    arr[1] = 51;
    arr[2] = 51;
    arr[3] = 92;
    arr[4] = 54;
    arr[5] = 90;
    arr[6] = 13;
    arr[7] = 69;
    arr[8] = 20;
    arr[9] = 6;
//
    std::cout << "Array:" << std::endl;
    printArrayInLine(arr, size);



        std::cout << "_____________RECURSIVE IMPLEMENTATION:_____________" << std::endl;

    int number_of_calls_rec = 0;

    if ((begin = clock() ) ==-1)
                std::cerr << "clock error" << std::endl;

        max_sum_rec = recursive_sln(size-1, arr, number_of_calls_rec);

    if ((end = clock() ) ==-1)
                std::cerr << "clock error" << std::endl;

    duration = ((double) end - begin) / CLOCKS_PER_SEC;
        std::cout << "Duration: " << duration << " seconds." << std::endl;

        std::cout << "Max sum: " << max_sum_rec << std::endl;
    std::cout << "Number of recursive calls: " << number_of_calls_rec << std::endl;

        std::cout << "---------------------------------------------------";
        std::cout << "\n" << std::endl;



        int* mem = new int[size];


        std::cout << "______________________MEMOIZATION:__________________" << std::endl;

        for(int i = 0; i < size-1; i++) mem[i] = -1;


        if ((begin = clock() ) ==-1)
                std::cerr << "clock error" << std::endl;

    max_sum_mem = memoization_sln(size-1, arr, mem);
    if ((end = clock() ) ==-1)
                std::cerr << "clock error" << std::endl;

    duration = ((double) end - begin) / CLOCKS_PER_SEC;
        std::cout << "Duration: " << duration << " seconds." << std::endl;

        std::cout << "Max sum: " << max_sum_mem << std::endl;
        std::cout << "Final mem: " << std::endl;
        printArrayInLine(mem, size);

        std::cout << "----------------------------------------------------";
        std::cout << "\n" << std::endl;




        std::cout << "__________________DYNAMIC PROGRAMMING:______________" << std::endl;

        for(int i = 0; i < size; i++) mem[i] = -1;


    if ((begin = clock() ) ==-1)
                std::cerr << "clock error" << std::endl;

        max_sum_dp = dp_sln(size, arr, mem);

    if ((end = clock() ) ==-1)
                std::cerr << "clock error" << std::endl;

    duration = ((double) end - begin) / CLOCKS_PER_SEC;
        std::cout << "Duration: " << duration << " seconds." << std::endl;

        std::cout << "Max sum: " << max_sum_dp << std::endl;
        std::cout << "Final mem: " << std::endl;
        printArrayInLine(mem, size);

        std::cout << "----------------------------------------------------";
        std::cout << "\n" << std::endl;

}

int main()
{
        srandom(time(0));
    test();
////    int *arr = new int[5];
////    arr[0] = 8;
////    arr[1] = 64;
////    arr[2] = 55;
////    arr[3] = 34;
////    arr[4] = 46;
//    int *arr = new int[10];
//    arr[0] = 32;
//    arr[1] = 51;
//    arr[2] = 51;
//    arr[3] = 92;
//    arr[4] = 54;
//    arr[5] = 90;
//    arr[6] = 13;
//    arr[7] = 69;
//    arr[8] = 20;
//    arr[9] = 6;
//
//    int call_number = 0;
//    std::cout<<"max sum: "<<recursive_sln(9,arr,call_number)<<std::endl;
//    std::cout<< "number of  recursive calls is: "<< call_number<<std::endl;
    return 0;
}
