#include <stdio.h>

//To create a function that tells the dimension of an array
int array_dimension(void *arr){
    int dim = 1;
    int size = sizeof(int);
    while(1){
        if((void*)arr != NULL){
            dim++;
            arr = ((void**)arr)[1]; //increasing the dimension of the array
        }
        else break;
    }
    if(dim>=1) return dim;
    else return -1;
}

