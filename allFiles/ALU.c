#include<stdio.h>
#include<stdlib.h>


int ALU(int S , int regA , int regB, int *flagC){
    int sum = 0;
    if( S == 0){
        sum = regA + regB;
        if(sum > 15){
            *flagC = 1;
            sum = sum -16;
        }
        else{
            *flagC = 0;
        }
    }
    else if ( S == 1){
        sum = regA - regB;
    }
    return sum;
}