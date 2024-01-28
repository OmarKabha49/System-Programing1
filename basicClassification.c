#include "NumClass.h"
//calculate the factorial using recursion
int factorial(int num){
    if(num == 0 || num == 1){return 1;}

    return num * factorial(num-1);
}


/*
to make the prime function faster
we check if i <= sqrt(num)
if the function find any number(i) that divides (num) then return false
*/
int isPrime(int num){
    for(int i = 2; i*i <= num;++i){
        if(num%i == 0){return 0;}
    }
    return 1;
}

/*

*/
int isStrong(int num){
    int result = 0;
    int temp = num;
    while(temp > 0){
        int digit = temp%10;
        result += factorial(digit);
        temp/=10;
    }
    if(result == num){
        return 1;
    }
    return 0;
}