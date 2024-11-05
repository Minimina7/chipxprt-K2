#include<stdio.h>
#include<stdlib.h>

int jump(int j, int c, int immediate, int pc){
    if(j == 1)
        return immediate;
    else if(c == 1){
        return immediate;
    }
    else{
        return pc;
    }
}