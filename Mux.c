#include<stdio.h>
#include<stdlib.h>

void mux(int *regA, int *regB, int D0, int Sreg, int immediate, int sum){
    if(D0 == 0 && Sreg == 1)
        *regA = immediate;
    else if(D0 == 1 && Sreg == 1)
        *regB = immediate;
    else if(D0 == 1 && Sreg == 0)
        *regB = sum;
    else if(D0 == 0 && Sreg == 0)
        *regA = sum;
}