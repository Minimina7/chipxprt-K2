#include<stdio.h>
#include<stdlib.h>

void decoder(char *lines , int counter, char *j, char *c, char *D1,char *D0, char *Sreg ,char *S, char *imm1, char *imm0){
    char byte = (char)strtol(lines, NULL, 2);
    *j = (byte >> 7) & 1;
    *c = (byte >> 6) & 1;
    *D1 = (byte >> 5) & 1;
    *D0 = (byte>> 4) & 1;
    *Sreg = (byte >> 3) & 1;
    *S = (byte >> 2) & 1;
    *imm1 = (byte>> 1) & 1;
    *imm0 = (byte>> 0) & 1;
    }

int main(int argc, char *argv[]) {
    char lines[8];
    char j = 0;
    char c = 0;
    char D1 = 0;
    char D0 = 0;
    char Sreg = 0;
    char S = 0;
    char imm1 = 0;
    char imm0 = 0;
    int i = 0;
    if (argc < 2) {
        printf("you did't entered input in command prompt!!\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(lines,sizeof(lines),fp)){
        if(lines == '\n')
            continue;
        printf("Read it from the file\n");
        printf("\nfile input:\n%s\n",lines);
        decoder(lines,i,&j,&c,&D1,&D0,&Sreg,&S,&imm1,&imm0);
        i++;
        printf("The variables: j= %d c= %d D1 = %d D0 = %d Sreg = %d S = %d imm1 = %d imm0 = %d \n",j,c,D1,D0,Sreg,S,imm1,imm0);
    }

}