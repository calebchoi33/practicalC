#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include <stdint.h>
//gmplib.org, remember to look at this for help. 
//This looks eerily alike Parth's code, it's almost as if he helped me very closely, please don't hurt me. 

void fib(size_t n, mpz_t m){
    size_t count = 0;
    mpz_t a = m; //declaring the variable
    mpz_init(a); //initialization of a variable
    mpz_t b;
    mpz_init(b);
    mpz_t c;
    mpz_init(c);
    mpz_set_ui(a, 1); //assignment of 1 to already initialized variable of a
    mpz_set_ui(b, 1);
    mpz_set_ui(c, 1);

    while(count < n){
        mpz_add(m, b, c); //m = b + a
        char* mpzstr = malloc(mpz_sizeinbase(a,10)+1); //Returns the size of a measured in the number of digits in the given base. 
        mpz_get_str(mpzstr, 10, n);//Typical fibonacci stuff
        
        mpz_get_str(mpzstr, 10, a); //Converts a into a string of digits into mpzstr
        count = strlen(mpzstr); //finds the length of the string as of right now
        free(mpzstr);
        mpz_set(b, c); //assigns the C value to already initialized variable b
        mpz_set(b, a);
    }
}

int main(int argc, char* argv[]){
    mpz_t x;
    mpz_init(x);
    fib(1000, x);
    return 0;
}
