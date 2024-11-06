#include<stdio.h>
#include<stdlib.h>

int immediate(char imm2 , char imm1, char imm0){
    int value = 0;
            if(imm2 == 1)
                 value += 4;
            if(imm1 == 1)
                 value += 2;
            if(imm0 == 1)
                 value += 1;
    return value;
}