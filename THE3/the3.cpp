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

void printArray(std::string arr[], int n){

    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout<<endl;
}

void countingSort(std::string *arr, bool ascending, int n, int l, int start, int& iter, bool lastCall){
    std::string arrEle;
    int index;
    long k = pow(26,l);
    int *C =new int[k];
    for(int i=0; i<k;i++){
        C[i]=0;
    }
    std::string *B = new std::string[n];
    for(int i=0; i<n;i++){
        B[i] = arr[i];
        arrEle = arr[i].substr(start, l);
        index = calculateIndex(arrEle);
//        cout<<"index: "<<index<<endl;

        C[index]++;


        iter++;
//        cout<<"first Time B: "<<endl;
//        printArray(B, n);
    }
//    for(int x=0;x<k;x++){
//        cout<<C[x]<< " ";
//    }

    for(int i=1; i<k;i++){
        C[i] += C[i-1];
        iter++;
    }
//    for(int x=0;x<k;x++){
//        cout<<C[x]<< " ";
//    }
//    cout<<endl;

    for(int j=n-1; j>=0;j--){
        arrEle = arr[j].substr(start, l);
        index = calculateIndex(arrEle);
//        cout<<"arrEle: "<<arrEle<< " index: "<<index<<endl;
//        cout<< "index: "<< index<< " C'de karsilik gelen: "<< C[index]<<endl;



        B[C[index]-1] = arr[j];
        C[index]--;
        iter++;
    }

//    cout<<"printing B"<<endl;
//    printArray(B, n);
    for(int i=0;i<n;i++){
        arr[i] = B[i];
        iter++;
    }
    if(lastCall &&  !ascending){
        for(int i=0;i<n;i++){
            arr[i] = B[n-i-1];
        }
    }


    delete[] B;
    delete[] C;

}


int radixSort(std::string arr[], bool ascending, int n, int l){
    int iter = 0;
    int sLen = arr[0].length();
    int lastStart;
    for(int i=sLen-l; i>=0; i=i-l){
        if(i==0){
            countingSort(arr, ascending, n, l, i, iter, true);

        }
        else{
            countingSort(arr, ascending, n, l, i, iter, false);

        }
        lastStart = i;
        iter++;
    }
    if(lastStart!=0){
        countingSort(arr, ascending, n, lastStart, 0, iter, true);
        iter++;

    }
//    cout<<calculateIndex("BAA")<<endl;


    return iter;

}
