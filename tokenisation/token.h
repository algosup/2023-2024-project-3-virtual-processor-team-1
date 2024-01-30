typedef enum instruction
{
    MOV,
    ADD, 
    SUB, 
    MUL,
    DIV,
    JMP,
    JE,
    JNE,
    JG,
    JGE,
    JL,
    JLE,
    RET,
    CMP,
    CALL,
    AND,
    OR,
    XOR,
    NOT,
    GAD,
    DISP
} instruction_t;

typedef enum registers
{
    R1,
    R2,
    R3,
    R4,

} registers_t;

typedef enum address_registers
{
    A1,
    A2,
    A3,
    A4,

} address_registers_t;

typedef enum values
{
    IM,
    NE,
    STR

} values_t;

typedef union data
{
    instruction_t instruction;
    registers_t registers;
    address_registers_t address_registers;
    values_t values;
} data_t;

typedef enum typeofdata
{
    INSTRUCTION,
    REGISTER,
    ADDRESS_REGISTER,
    VALUE

} typeofdata_t;

typedef struct token
{
    typeofdata_t type; // register, operator, address register, value
    typeofdata_t parameter; // parameter of the token (register, operator, address register, value)
    int row; // row number 
    int column; // column number

}token_t;

int column = 0;
int row = 0;

void getEnum(int column, int row){      // This function permitte to find the type of instruction
    
}

void tokenizationFunction(char cleanedLines[][3][1000], int numLines){
    for(int i = 0; i < numLines; i++){
        for(int c = 0; c < 3; c++){
            switch(c){
                case 0:
                    getEnum(c, i);
                    break;
                case 1:
                    printf("1 en C\n");
                    break;
                case 2:
                    printf("Zut\n");
                    break;
                default:
                    printf("Zut numero 2");
                    break;
                }
        }
    }
}