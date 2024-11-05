#include<stdio.h>
#include<stdlib.h>

int immediate(char imm2 , char imm1, char imm0){
    int immediate = 0;
            if(imm2 == 1)
                 immediate += 4;
            if(imm1 == 1)
                 immediate += 2;
            if(imm0 == 1)
                 immediate += 1;
    return immediate;
}