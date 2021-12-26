#include "the3.h"

// do not add extra libraries here


/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time

    you can use ceil function from cmath

*/

using namespace std;
void printArray(std::string* arr, int size){

//    for(int i=0; i<size;i++){
//        cout<< arr[i]<<" ";
//
//    }
    for(int i=0; i<size;i++){
        cout<<"i: "<<i<< " arr[i]: "<<arr[i]<<endl;

    }
    cout<<endl;
}

int calculateIndex(std::string s){
    int index = 0;
    int l = s.length();
    switch(l) {
        case 1:

            index = s[0]-65;
            break;
        case 2:
            index = (s[0]-'A')*26 +(s[1]-65);
            break;
        case 3:

            index = (s[0]-65)*pow(26,2) +(s[1]-65)*26 +(s[2]-65);


            break;
        case 4:


            index = (s[0]-65)*pow(26,3)+(s[1]-65)*pow(26,2) +(s[2]-65)*26 +(s[3]-65);


            break;
        case 6:


            index = (s[0]-65)*pow(26,5)+(s[1]-65)*pow(26,4)+(s[2]-65)*pow(26,3)+(s[3]-65)*pow(26,2) +(s[4]-65)*26 +(s[5]-65);


            break;

    }
    return index;
}

int radixSort(std::string arr[], bool ascending, int n, int l){
    long k = pow(26, l);

    std::string *B = new std::string [n];
    int iter = 0;
    int strLength = arr[0].length();
    int oldStart = strLength-l;
    int start = strLength-l;
    std::string arr_element;
    int *C = new int[k];

    int indexOfString;
//    printArray(arr, n);
    while(1){
        for(int m=0; m<k;m++){
            C[m]=0;
        }
        if(oldStart<0){
            break;
        }


////

        oldStart = start;
        start = oldStart-l;
        iter++;

        for(int i=0; i<n;i++){
            arr[i] = B[i];
            iter++;
        }

    }



    //printArray(copied, n);
    delete [] B;
    delete[] C;



    printArray(arr, n);
    return 0;

}
