#include <iostream>

using namespace std;

void fromThisFile(){
    cout << endl <<"Hello from headerFile" << endl;
}

double smalLest(double *arr){
    cout<< "array of doubles"<< endl;
    double small;
    small =arr[0];
    for (int i =0; i < (sizeof(arr)/sizeof(*arr)); i++){
        if(arr[i] < small){
            small = arr[i];
        }    
    }
    return small;
}

int smalLest(int *arr){
    cout<< "array of integers"<< endl;
    int small;
    small =arr[0];
    for (int i =0; i < (sizeof(arr)/sizeof(*arr)); i++){
        if(arr[i] < small){
            small = arr[i];
        }    
    }
    return small;
}

