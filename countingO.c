#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int most_common_element(int num[], size_t length){

    int count[100] = {0};

    for(size_t i = 0; i < length; i++){
        count[num[i]] += 1; 
    }

    int max = 0;
    int maxi = 0;

    for(size_t i = 0; i < 100; i++){
        if(count[i] > max){
            max = count[i];
            maxi = i; 
        }
    }

    for(size_t j = 0; j < 100; j++){
        if(count[j] == max){
            return maxi;
        }
    }
    
    return max;

}

int main(int argc, char *argvp[]){
    int test[99] = {0};
    for(int i = 0; i < 100; i++){
        test[i] = i;
    }
    printf("The most common element is %d.", most_common_element((size_t)test, 99));
}
