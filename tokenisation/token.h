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

typedef struct token
{
    data_t type; // register, operator, address register, value
    data_t parameter; // parameter of the token (register, operator, address register, value)
    int row; // row number 
    int column; // column number

}token_t;

