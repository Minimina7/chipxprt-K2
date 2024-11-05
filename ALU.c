#include<stdio.h>
#include<stdlib.h>

int ALU(int S , int regA , int regB){
    int sum = 0;
    if( S == 0){
        sum = regA + regB;
    }
    else if ( S == 1){
        sum = regA - regB;
    }
    return sum;
}