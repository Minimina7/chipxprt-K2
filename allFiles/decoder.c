#include<stdio.h>
#include<stdlib.h>

void decoder(char memory[32][9], char *j, char *c, char *D1,char *D0, char *Sreg ,char *S, char *imm1, char *imm0, int counter){
    //char text = memory[counter];
    char byte = (char)strtol(memory[counter], NULL, 2);
    *j = (byte >> 7) & 1;
    *c = (byte >> 6) & 1;
    *D1 = (byte >> 5) & 1;
    *D0 = (byte>> 4) & 1;
    *Sreg = (byte >> 3) & 1;
    *S = (byte >> 2) & 1;
    *imm1 = (byte>> 1) & 1;
    *imm0 = (byte>> 0) & 1;
    }