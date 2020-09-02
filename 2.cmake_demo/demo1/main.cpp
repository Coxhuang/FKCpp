#include <iostream>
#include <cstdio>
#include <cstdlib>

double power(double base, int exponent){
    int result = base;
    int i;
    if (exponent == 0) {
        return 1;
    }
    for(i = 1; i < exponent; ++i){
        result = result * base;
    }
    return result;
}

int main(int argc, char *argv[]){

    double result = power(2, 3);
    printf("is %g\n", result);
    return 0;
}
