#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int collatCon (int n){
    int i = 0;
    while(n != 1){
        if(n%2 == 0){
            n /= 2;
        }
        else{
            n = 3 * n +1;
        }
        i = i+ 1; 
    }
    return i;
}

int main( int argc, char *argv[] ) {
    int max = 0;
    int maxi = 0;
    for(int i = 1; i < 100000; i++){
        if(collatCon(i) >= max){
            max = collatCon(i);
            maxi = i;
        }
    }

    printf( "%d has a stopping time of %d", maxi, max);
}
