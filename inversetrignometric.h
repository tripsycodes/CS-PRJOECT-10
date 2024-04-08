#include <stdio.h>

#define PI 3.14159265358979323846

// Function to calculate the square root of a number
double sqrt(double x) {
    double guess = x / 2.0;
    double prevGuess;
    do {
        prevGuess = guess;
        guess = (guess + x / guess) / 2.0;
    } while (prevGuess - guess > 0.00001); // Change the threshold for desired precision
    return guess;
}

// Function to calculate the inverse trigonometric arcsine (asin)
double arcsin(double x) {
    if (x < -1.0 || x > 1.0)
        return NAN; // Not a Number for invalid input
    
    double result = 0.0;
    double term = x;
    double xSquared = x * x;
    double coefficient = 1.0;
    for (int n = 1; n <= 100; ++n) { // Change the number of terms for desired precision
        result += term * coefficient;
        term *= xSquared * (2 * n - 1) / (2 * n);
        coefficient *= (2 * n - 1) / (2 * n);
    }

    return PI / 2 - result;
}

// Function to calculate the inverse trigonometric arccosine (acos)
double arccos(double x) {
    if (x < -1.0 || x > 1.0)
        return NAN; // Not a Number for invalid input

    double result = 0.0;
    double term = x;
    double xSquared = x * x;
    double coefficient = 1.0;
    for (int n = 1; n <= 100; ++n) { // Change the number of terms for desired precision
        result += term * coefficient;
        term *= xSquared * (2 * n - 1) / (2 * n);
        coefficient *= (2 * n - 1) / (2 * n);
    }
    return result;
}

// Function to calculate the inverse trigonometric arctangent (atan)
double arctan(double x) {
    if (x == 0.0)
        return 0.0;
    if (x < -1.0 || x > 1.0)
        return NAN; // Not a Number for invalid input

    double result = 0.0;
    double term = x;
    double xSquared = x * x;
    for (int n = 1; n <= 100; ++n) { // Change the number of terms for desired precision
        result += term / n;
        term *= -xSquared;
    }
    return result;
}

// Function to calculate the inverse trigonometric arccotangent
double arccot(double x) {
    if (x == 0.0)
        return PI / 2;
    if (x < -1.0 || x > 1.0)
        return NAN; // Not a Number for invalid input

    double result = 0.0;
    double term = x;
    double xSquared = x * x;
    for (int n = 1; n <= 100; ++n) { // Change the number of terms for desired precision
        result += term / n;
        term *= -xSquared;
    }
    return PI / 2 - result;
}

// Function to calculate the inverse trigonometric arcsecant
double arcsec(double x) {
    if (x <= -1.0 || x >= 1.0)
        return NAN; // Not a Number for invalid input
    
     double result = 0.0;
    double term = 1/x;
    double xSquared = 1/x * 1/x;
    double coefficient = 1.0;
    for (int n = 1; n <= 100; ++n) { // Change the number of terms for desired precision
        result += term * coefficient;
        term *= xSquared * (2 * n - 1) / (2 * n);
        coefficient *= (2 * n - 1) / (2 * n);
    }
    return result;
}

// Function to calculate the inverse trigonometric arccosecant
double arccsc(double x) {
    if (x <= -1.0 || x >= 1.0)
        return NAN; // Not a Number for invalid input
    
    double result = 0.0;
    double term = 1/x;
    double xSquared = 1/x * 1/x;
    double coefficient = 1.0;
    for (int n = 1; n <= 100; ++n) { // Change the number of terms for desired precision
        result += term * coefficient;
        term *= xSquared * (2 * n - 1) / (2 * n);
        coefficient *= (2 * n - 1) / (2 * n);
    }
    return result;
}

int main() {
    double value = 0.5; // Example value
    
    printf("arcsin(%lf) = %lf\n", value, arcsin(value));
    printf("arccos(%lf) = %lf\n", value, arccos(value));
    printf("arctan(%lf) = %lf\n", value, arctan(value));
    printf("arccot(%lf) = %lf\n", value, arccot(value));
    printf("arcsec(%lf) = %lf\n", value, arcsec(value));
    printf("arccsc(%lf) = %lf\n", value, arccsc(value));

    return 0;
}
