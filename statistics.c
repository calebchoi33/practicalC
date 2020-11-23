#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

double *read_array(size_t count){
    double *array = calloc(count, sizeOf(double));
    printf("Enter %d numbers, one per line:\n", count);
    for(size_t i= 0; i < count; i++){
        scanf("%d", &array[i]);
    }
    return array;
}

double sum(const double *nums, size_t count){
    double sum = 0.0;
    for(size_t i = 0; i < count; i++){
        sum += nums[i];
    }
    return sum;
}

double average(const double *nums, size_t count){
    return sum(nums, count)/count; 
}

double std_dev(const double *nums, size_t count){
    double average = average(nums, count);
    double deviation = 0.0;
    for(size_t i = 0; i < count; i++){
        deviation += pow(nums[i] - average, 2);
    }
    return sqrt(deviation/count);
}

int main( int argc, char *argv[] ) {
    int test = 0;
    printf("How many numbers will you enter?");
    scanf("%d", &test);
    const double *nums = read_array(test);
    printf("Time to roll the numbers baby\n Sum: %d\n Average: %d\n Standard Deviation: %f\n", sum(nums, test), average(nums, test), std_dev(nums, test));
    free(test);    
}
