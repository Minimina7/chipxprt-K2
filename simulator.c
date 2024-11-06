#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"allFiles/mux.h"
#include"allFiles/immediate.h"
#include"allFiles/ALU.h"
#include"allFiles/decoder.h"
#include"allFiles/jump.h"
#include"allFiles/load.h"
#include"allFiles/fetch.h"


int main(int argc, char *argv[]) {
    int PC = 0;
    char memory[16];
    char choice;
    int cureentInstruction;
    unsigned short immediateValue = 0;
    unsigned short sum = 0;
    int regA = 0;
    int regB = 0;
    int regZ = 0;
    int carry_Reg = 0;
    int value = 0;
    char j = 0;
    char c = 0;
    char D1 = 0;
    char D0 = 0;
    char Sreg = 0;
    char S = 0;
    char imm1 = 0;
    char imm0 = 0;
    int flagC = 0;
    

    if (argc < 2) {
        printf("you did't entered input in command prompt!!\n");
        return 1;
    }

    // FILE *fp = fopen(argv[1], "rb");
    // if (fp == NULL) {
    //     perror("Error opening file");
    //     return 1;
    // }
    
    printf("Select one of the following mode\nR - Run in continuous mode\nS - Run step-by-step\nSelect mode: ");
    scanf(" %c", &choice);
    while (choice != 'R' && choice != 'r' && choice != 'S' && choice != 's'){
        printf("Wrong input, please try again\n");
        printf("Select one of the following mode\nR - Run in continuous mode\nS - Run step-by-step\nSelect mode: ");
        scanf(" %c", &choice);
    }
    
    printf("Loading binary file: %s\n", argv[1]);
    int instructions = load(argv[1] , memory);
    printf("Execution (Register RO output):\n");

    for(PC; PC <= instructions ; PC++){
        cureentInstruction = ftech(memory,PC);
        decoder(cureentInstruction, &j, &c, &D1, &D0, &Sreg, &S, &imm1, &imm0);
        //printf("decoder is working\n");
        immediateValue = immediate(S, imm1, imm0);
        //PC = jump(j, c, flagC, immediateValue, PC);
        //printf("immediateValue is working\n");
        sum = ALU(S, regA, regB ,&flagC);
        value = mux(Sreg , immediateValue, sum);
        //printf("mux is working\n");
        if(D1 == 0 && D0 == 0){
            regA = value;
        }
        if(D1 == 0 && D0 == 1){
            regB = value;
        }
        //printf("ALU is working\n");
        if(D1 == 1 && D0 == 0){
            regZ = regA;
            printf("R0 = %d\n", regZ);
        }
        //printf("R0 is working\n");
        //printf("jump is working\n");
        //printf("RA = %d\n", regA);
        //printf("RB = %d\n", regB);
        PC = jump(j, c, carry_Reg, immediateValue, PC);
        usleep(15000);

        carry_Reg = flagC;

        if(choice == 'S' || choice == 's'){
            printf("The code excuted the follwoing instrcution: %d%d%d%d%d%d%d%d\n",j,c,D1,D0,Sreg,S,imm1,imm0);
            printf("Please press S to continue: ");
            scanf(" %c",&choice);
            while (choice != 'S' && choice != 's')
            {
                printf("Wrong input, please try again\n");
                printf("Select one of the following mode\nR - Run in continuous mode\nS - Run step-by-step\nSelect mode: ");
                scanf(" %c", &choice);
            }
            
        }



    }
    return 0;
}