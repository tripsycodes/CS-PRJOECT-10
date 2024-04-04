#include <stdio.h>
#include<stdlib.h>
#include<math.h>

//To create a function that tells the dimension of an array
int dimension(void *arr){
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

//To create a function to determine the shape of an array
int shape(void *arr, int dim_size)
{
    int shape = dim_size / sizeof(int);
    return shape;
}

double* linspace(double start, double end, int n) {
     double *x;
     int i = 0;
     double step = (end - start) / ((double)n-1);
     x = (double*)calloc(n, sizeof(double));
     x[i] = start; 

     for (i = 1; i < n; i++) {
         x[i] = x[i - 1] + step;
     }
     x[n - 1] = end;
     return x;
     }


double* logspace(double start, double end, int n, double base) {
    double* result = (double*)calloc(n,sizeof(double));
    double log_start = log10(start) / log10(base);
    double log_end = log10(end) / log10(base);
    double step = (log_end - log_start) / (n - 1);

    for (int i = 0; i < n; i++) {
        result[i] = pow(base, log_start + i * step);
    }
    return result;
}


double* arange(double start, double end, double step) {
    int n = (int)((end - start) / step) + 1;
    double* result = (double*)calloc(n , sizeof(double));

    for (int i = 0; i < n; i++) {
        result[i] = start + i * step;
    }

    return result;
}
