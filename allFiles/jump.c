#include<stdio.h>
#include<stdlib.h>

int jump(int j, int c, int flagC, int immediate, int pc){
    if(j == 1)
        return immediate - 1;
    else if(c == 1 & flagC){
        return immediate - 1;
    }
    else{
        return pc;
    }
}