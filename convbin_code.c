#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[100], new_line[100];

// Converting an instruction to binary 
char* convbin(char *instruction, int *flag) {
    static char x[9];

    // The binary codes for each instruction
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

// Reading and Writing the assembler files
void assembler_function() {
    int flag = 0;
    FILE *input_file = fopen("fibonacci.asm", "r");
    FILE *output_file = fopen("fibonacci.bin", "w");

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

	// Convert each character to uppercase and remove spaces and newlines
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t') {
                new_line[j++] = toupper(line[i]);
            }
	 }
/*	if(flag == 1){
		printf("There is error in line %d\n",j);
	}
*/
        new_line[j] = '\0'; // Null-terminate the string

        // Convert the instruction to binary and write it to the output file
        char *bin = convbin(new_line, &flag);
	
        fprintf(output_file, "%s\n", bin);
	
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    assembler_function();
    return 0;
}

