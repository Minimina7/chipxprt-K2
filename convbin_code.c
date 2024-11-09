#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[100], new_line[100];

 
char* convbin(char *instruction, int *flag) {
    static char x[9];

    
    if (strcmp(instruction, "RA=RA+RB") == 0) strcpy(x, "00000000");
    else if (strcmp(instruction, "RB=RA+RB") == 0) strcpy(x, "00010000");
    else if (strcmp(instruction, "RA=RA-RB") == 0) strcpy(x, "00000100");
    else if (strcmp(instruction, "RB=RA-RB") == 0) strcpy(x, "00010100");
    else if (strcmp(instruction, "R0=RA") == 0) strcpy(x, "00100000");
    else if (strcmp(instruction, "RA=0") == 0) strcpy(x, "00001000");
    else if (strcmp(instruction, "RA=1") == 0) strcpy(x, "00001001");
    else if (strcmp(instruction, "RA=2") == 0) strcpy(x, "00001010");
    else if (strcmp(instruction, "RA=3") == 0) strcpy(x, "00001011");
    else if (strcmp(instruction, "RA=4") == 0) strcpy(x, "00001100");
    else if (strcmp(instruction, "RA=5") == 0) strcpy(x, "00001101");
    else if (strcmp(instruction, "RA=6") == 0) strcpy(x, "00001110");
    else if (strcmp(instruction, "RA=7") == 0) strcpy(x, "00001111");
    else if (strcmp(instruction, "RB=0") == 0) strcpy(x, "00011000");
    else if (strcmp(instruction, "RB=1") == 0) strcpy(x, "00011001");
    else if (strcmp(instruction, "RB=2") == 0) strcpy(x, "00011010");
    else if (strcmp(instruction, "RB=3") == 0) strcpy(x, "00011011");
    else if (strcmp(instruction, "RB=4") == 0) strcpy(x, "00011100");
    else if (strcmp(instruction, "RB=5") == 0) strcpy(x, "00011101");
    else if (strcmp(instruction, "RB=6") == 0) strcpy(x, "00011110");
    else if (strcmp(instruction, "RB=7") == 0) strcpy(x, "00011111");
    else if (strcmp(instruction, "JC=0") == 0) strcpy(x, "01110000");
    else if (strcmp(instruction, "JC=1") == 0) strcpy(x, "01110001");
    else if (strcmp(instruction, "JC=2") == 0) strcpy(x, "01110010");
    else if (strcmp(instruction, "JC=3") == 0) strcpy(x, "01110011");
    else if (strcmp(instruction, "JC=4") == 0) strcpy(x, "01110100");
    else if (strcmp(instruction, "JC=5") == 0) strcpy(x, "01110101");
    else if (strcmp(instruction, "JC=6") == 0) strcpy(x, "01110110");
    else if (strcmp(instruction, "JC=7") == 0) strcpy(x, "01110111");
    else if (strcmp(instruction, "J=0") == 0) strcpy(x, "10110000");
    else if (strcmp(instruction, "J=1") == 0) strcpy(x, "10110001");
    else if (strcmp(instruction, "J=2") == 0) strcpy(x, "10110010");
    else if (strcmp(instruction, "J=3") == 0) strcpy(x, "10110011");
    else if (strcmp(instruction, "J=4") == 0) strcpy(x, "10110100");
    else if (strcmp(instruction, "J=5") == 0) strcpy(x, "10110101");
    else if (strcmp(instruction, "J=6") == 0) strcpy(x, "10110110");
    else if (strcmp(instruction, "J=7") == 0) strcpy(x, "10110111");
    else strcpy( x, "11111111");
   	
    printf("%s ---> %s\n", instruction, x);
   	
    return x;
	
}


void assembler_function(char *fileName) {
    int flag = 0;
    char inputFileName[100];
    char outputFileName[100];

    sprintf(inputFileName, "%s.asm", fileName);
    sprintf(outputFileName, "%s.bin", fileName);
    FILE *input_file = fopen(inputFileName, "r");
    FILE *output_file = fopen(outputFileName, "w");

    if (input_file == NULL) {
        printf("Error: The input file could not be opened.\n");
        return;
    }
    if (output_file == NULL) {
        printf("Error: The output file could not be opened.\n");
        fclose(input_file);
        return;
    }

    while (fgets(line, 100, input_file)) {
        int j = 0;

       	if (line[0] == ' '|| line[0] == '\n')
		continue;

	
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t') {
                new_line[j++] = toupper(line[i]);
            }
	 }
/*	if(flag == 1){
		printf("There is error in line %d\n",j);
	}
*/
        new_line[j] = '\0'; 

        
        char *bin = convbin(new_line, &flag);
	
	if (strcmp(bin, "11111111") == 0) {
            printf("Error: Invalid instruction in line: %s", line);
        } else {
            
            fprintf(output_file, "%s\n", bin);
        }	


       // fprintf(output_file, "%s\n", bin);
	
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("you did't entered input in command prompt!!\n");
        return 1;
    }

    assembler_function(argv[1]);
    return 0;
}

