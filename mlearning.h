#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265

int size(int*arr){
    int out = sizeof(arr)/sizeof(arr[0]);
}

//To create a function to calculate the length of an array
int length(int arr[]) {
    int length = 0;
    int i = 0;
    while (arr[i] != '\0') {
        length++;
        i++;
    }
    return length;
}

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
int shape(void *arr)
{
    int dim_size = size(arr); 
    int shape = dim_size / sizeof(int);
    return shape;
}

//To return an equally spaced array
double* linspace(double start, double end, int n) {
     double *x;
     int i = 0;
     double step = (end - start) / ((double)n-1);    //the space between to consecutive elements
     x = (double*)calloc(n, sizeof(double));    //allocation of memory and initialisation woth 0
     x[i] = start; 

    i=1;
     while(i<n){
         x[i] = x[i - 1] + step;
         i++;
     }
     x[n - 1] = end;
     return x;
     }

//to return an array equally spaced on the logarithmic scale
double* logspace(double start, double end, int n, double base) {
    double* result;
    result = (double*)calloc(n,sizeof(double));
    double log_start = log10(start) / log10(base);
    double log_end = log10(end) / log10(base);
    double step = (log_end - log_start) / (n - 1);    //calculating the difference between 2 numbers ont he logarithmic scale

    int i = 0;
    while(i<n){
        result[i] = pow(base, log_start + i * step);
        i++;
    }
    return result;
}

// Values are generated within the half-open interval [start, stop), with spacing between values given by step.
double* arange(double start, double end, double step) {
    int n = (int)((end - start) / step) + 1;
    double* result = (double*)calloc(n , sizeof(double));

    for (int i = 0; i < n; i++) {
        result[i] = start + i * step;
    }

    return result;
}

//To calculate mean of an array
int mean(int*arr) {
    int n = length(arr); // Number of data points
    double sum = 0.0; 
    double mean; 

    int i=0;
    while(i<n){
        sum += arr[i];
        i++;
    }
    mean = sum / n;
    return mean;
}

typedef struct {
    int row;
    int col;
} Index;

Index* argwhere(int **indicesArray, int rows, int cols, int reqCondition, int *length) {
    
    Index* indices = malloc(rows * cols * sizeof(Index));
    if (indices == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int count = 0; 

    // Loop through the array to find indices where the value is greater than the threshold
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (indicesArray[i][j] > reqCondition) {
                indices[count].row = i;
                indices[count].col = j;
                count++;
            }
        }
    }

    
    *length = count;

    return indices;
}

void pad_array(int *array, int rows, int cols, int pad_top, int pad_bottom, int pad_left, int pad_right) {
    int new_rows = rows + pad_top + pad_bottom;
    int new_cols = cols + pad_left + pad_right;

    int *padded_array = (int *)malloc(new_rows * new_cols * sizeof(int));

    // Fill padded_array with original array
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            if (i >= pad_top && i < rows + pad_top && j >= pad_left && j < cols + pad_left) {
                padded_array[i * new_cols + j] = array[(i - pad_top) * cols + (j - pad_left)];
            } else {
                padded_array[i * new_cols + j] = 0;  // Assuming padding with zeros
            }
        }
    }

    // Copy padded_array back to array
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            array[i * new_cols + j] = padded_array[i * new_cols + j];
        }
    }

    free(padded_array);
}

// Function to convert degrees to radians
double toRadians(double degree) {
    return degree * (PI / 180);
}

// Function to calculate factorial
double factorial(int n) {
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate sine using Taylor series
double sine(double angle) {
    angle = toRadians(angle);
    double result = 0;
    double power = angle;
    double sign = 1;

    for (int i = 1; i <= 10; ++i) {
        result += sign * power / factorial(2 * i - 1);
        power *= angle * angle;
        sign = -sign;
    }

    return result;
}

// Function to calculate cosine using Taylor series
double cosine(double angle) {
    angle = toRadians(angle);
    double result = 0;
    double power = 1;
    double sign = 1;

    for (int i = 0; i <= 10; ++i) {
        result += sign * power / factorial(2 * i);
        power *= angle * angle;
        sign = -sign;
    }

    return result;
}

// Function to calculate tangent using Taylor series
double tangent(double angle) {
   angle = toRadians(angle);
    double result1 = 0;
    double power1 = angle;
    double sign1 = 1;

    for (int i = 1; i <= 10; ++i) {
        result1 += sign1 * power1 / factorial(2 * i - 1);
        power1 *= angle * angle;
        sign1 = -sign1;
    }
     angle = toRadians(angle);
    double result2 = 0;
    double power2 = 1;
    double sign2 = 1;

    for (int i = 0; i <= 10; ++i) {
        result2 += sign2 * power2 / factorial(2 * i);
        power2 *= angle * angle;
        sign2 = -sign2;
    }
    double result=0;
    result = result1/result2;
    return result;
    
}

// Function to calculate cotangent using Taylor series
double cotangent(double angle) {
    angle = toRadians(angle);
    double result1 = 0;
    double power1 = angle;
    double sign1 = 1;

    for (int i = 1; i <= 10; ++i) {
        result1 += sign1 * power1 / factorial(2 * i - 1);
        power1 *= angle * angle;
        sign1 = -sign1;
    }
     angle = toRadians(angle);
    double result2 = 0;
    double power2 = 1;
    double sign2 = 1;

    for (int i = 0; i <= 10; ++i) {
        result2 += sign2 * power2 / factorial(2 * i);
        power2 *= angle * angle;
        sign2 = -sign2;
    }
    double result=0;
    result = result2/result1;
    return result;
   
}

// Function to calculate cosecant using Taylor series
double cosecant(double angle) {
    angle = toRadians(angle);
    double result = 0;
    double power = angle;
    double sign = 1;

    for (int i = 1; i <= 10; ++i) {
        result += sign * power / factorial(2 * i - 1);
        power *= angle * angle;
        sign = -sign;
    }
    result =1/result;
    return result;
}

// Function to calculate secant using Taylor series
double secant(double angle) {
    angle = toRadians(angle);
    double result = 0;
    double power = 1;
    double sign = 1;

    for (int i = 0; i <= 10; ++i) {
        result += sign * power / factorial(2 * i);
        power *= angle * angle;
        sign = -sign;
    }
    result=1/result;
    return result;
}

