#include<stdio.h>
#include<stdlib.h>

int mux(int Sreg, int immediate, int sum){
    if( Sreg == 1)
        return immediate;
    else if(Sreg == 0)
        return sum;

}