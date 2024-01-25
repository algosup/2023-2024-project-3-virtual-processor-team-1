#include"global.h"

// int main(int argc, char *argv[]) --> arguments from command line arg[1] = filename
int main (void)
{
    // argv[1]; for debugging
    char *file = "C:/Users/SalaheddineNAMIR/Documents/GitHub/2023-2024-project-3-virtual-processor-team-1/Interpreter/test.asm2"; 
    int buffer_size = 256;
    char *buffer[buffer_size];
    //readFile(file, buffer, buffer_size);
    cleanFile(file, buffer, buffer_size);
    char *cleanFile ="C:/Users/SalaheddineNAMIR/Documents/GitHub/2023-2024-project-3-virtual-processor-team-1/Interpreter/Clean.asm2";
    
    return 0;
}