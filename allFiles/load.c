#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int load(char *fileName, char memory[32][9]){
    int i = 0;
    char text[9];
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (fgets(text,sizeof(text),fp)){
        if(text[0] == '\n') continue;
        strcpy(memory[i],text);
        printf("Mem[%d] = %s\n", i, memory[i]);
        i++;
    } 

    fclose(fp);
    return i;
}