
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


int isPalindromeHelper(int arr[],int i, int j){
    if(i > j){return 1;}
    if(arr[i] == arr[j]){
        return isPalindromeHelper(arr,++i,--j);
    }
    return 0;
}

int isPalindrome(int num){
    int arr[HowManyDigits(num)];
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int temp = num;
    for (int i = arrSize - 1; i >=0 ; --i) {
        arr[i] = temp%10;
        temp/=10;
    }

    return isPalindromeHelper(arr,0,arrSize-1) ;
}


int isArmstrongHelper(int num,int original,int digitsN,int result) {
    if(num == 0){
        if(original == result){return 1;}
        return 0;
    }
    int digit = num%10;
    return isArmstrongHelper(num/10,original,digitsN, result + pow(digit,digitsN));
}

int isArmstrong(int num){
    int digitsN = HowManyDigits(num);
    return isArmstrongHelper(num, num, digitsN, 0);
}
