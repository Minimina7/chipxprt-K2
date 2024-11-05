#include<stdio.h>
#include<stdlib.h>

int load(char *fileName, char *memory){
    int i = 0;
    char text[8];
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (fgets(text,sizeof(text),fp)){
        memory[i] = text;
        i++;
    } 
    printf("Number of instructions is: %d",i);
    fclose(fp);
    return i;
}