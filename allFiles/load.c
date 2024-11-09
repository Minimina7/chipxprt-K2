#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int load(char *fileName, char *memory){
    int i = 0;
    char text[9];
    int instructionToInt = 0;
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (fgets(text,sizeof(text),fp)){
        if(text[0] == '\n') continue;
        int instructionToInt = (char)strtol(text, NULL, 2);
        //strcpy(memory[i],text);
        memory[i] = instructionToInt;
        printf("Mem[%d] = %d\n", i, memory[i]);
        i++;
    } 

    fclose(fp);
    return i;
}