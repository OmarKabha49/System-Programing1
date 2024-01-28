
#include "NumClass.h"
double pow(double num,double exp){
    if(exp == 0){return 1;}
    double result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= num;
    }
    return result;
}
int HowManyDigits(int num){
    int result = 0;
    while(num > 0){
        num/=10;
        result+=1;
    }
    return result;
}

int isArmstrong(int num){
    int result = 0;
    int temp = num;
    int digitsN = HowManyDigits(num);
    for(int i = 0; i < digitsN; ++i) {
        int digit = temp%10;
        temp/=10;
        result += pow(digit,digitsN);
    }
    if(result == num){return 1;}
    return 0;
}

int isPalindrome(int num){
    int arr[HowManyDigits(num)];
    int temp = num;
    int arrSize = HowManyDigits(num);
    for (int i = arrSize - 1; i >=0 ; --i) {
        arr[i] = temp%10;
        temp/=10;
    }

    int j = arrSize - 1;
    for (int i = 0; i<=j;++i,--j){
        if(arr[i] != arr[j]){return 0;}
    }

    return 1;
}