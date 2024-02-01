
**Technical Specifications - 2023-2024-project-3-virtual-processor**


---

# DEADLINE 9/2 5pm  

<details>
<summary>Table of Contents</summary>

- [DEADLINE 9/2 5pm](#deadline-92-5pm)
  - [I. Audience](#i-audience)
  - [II. Deliverable](#ii-deliverable)
  - [IV. Requirements](#iv-requirements)
  - [III. Details](#iii-details)
  - [V. Nice to have](#v-nice-to-have)
  - [VI. Priorities](#vi-priorities)
  - [VII. Technical Architecture](#vii-technical-architecture)
    - [Technology stack](#technology-stack)
    - [Input data](#input-data)
    - [Output data](#output-data)
    - [Non-requirements / Out of scope](#non-requirements--out-of-scope)
    - [Operating requirements](#operating-requirements)
    - [Key functions, operations, and algorithms](#key-functions-operations-and-algorithms)
    - [Algorithms](#algorithms)
    - [File Cleaning and Reading](#file-cleaning-and-reading)
    - [Lexical analysis (Tokenisation)](#lexical-analysis-tokenisation)
    - [Syntax analysis (Parsing)](#syntax-analysis-parsing)
      - [Errors handling](#errors-handling)
    - [Semantic analysis](#semantic-analysis)
    - [Code generation](#code-generation)
      - [Instruction format](#instruction-format)
    - [Virtual processor](#virtual-processor)
      - [Internal Components of a Computer](#internal-components-of-a-computer)
      - [Memory](#memory)
      - [Registers](#registers)
  - [VIII. Syntax and Structure](#viii-syntax-and-structure)
    - [Folder structure](#folder-structure)
    - [Program file structure](#program-file-structure)
    - [Function declaration](#function-declaration)
    - [Naming](#naming)
    - [Comments](#comments)
  - [IX. Code Design Principles](#ix-code-design-principles)
  - [X. Ideas and Hypotheses](#x-ideas-and-hypotheses)
    - [Unproven hypotheses](#unproven-hypotheses)
    - [Proven Hypotheses](#proven-hypotheses)
  - [XI. Challenges](#xi-challenges)
  - [XII. Possible Bugs](#xii-possible-bugs)
  - [XIII. Development Process](#xiii-development-process)
  - [XIV. Glossary](#xiv-glossary)

</details>


## I. Audience

This document is primarily intended for:

- Software developer - to understand the user and technical requirements, and to guide decision-making and planning. Help them understand risks and challenges, customer requirements, and additional technical requirements and choices made  
  
Secondary audiences
- Program manager - to validate against the functional specification, and the client expectations
- QA - to aid in preparing the test plan and to use it for validating issues.
- Project manager - to help identify risks and dependencies


## II. Deliverable 

 The goal of the project is to create a virtual processor and an interpreter for running assembly code on that processor.
 

## IV. Requirements 

1. Create a minimal assembly language (This requirement is fully described in the [functional specifications](./FunctionalSpecifications.md))
   
2. Develop a C program that reads assembly code from a file, checks for semantic correctness, and executes it on the virtual processor.
   
3. Implement a virtual system call for displaying text in a virtual terminal, that can be accessed from the assembly code  
   
4. Implement a virtual processor that can execute the assembly code
   
5. Write a small assembly program conceptually similar to unit tests to showcase that everything is working 



## III. Details 

The project will be developed in plain, portable, C language without using any external library besides C standard libraries. 

The project is divided into two parts:
1. The first part is the virtual processor. The virtual processor will have the following components:
   - 4 general-purpose registers
   - 4 address registers
   - 1 instruction register
   - 1 program counter
   - 1 stack pointer
   - 1 data memory
   - 1 instruction memory
   - 1 stack memory
   - 1 virtual terminal
   - 32-bit architecture
 
2. The second part is the interpreter. The purpose of the interpreter is to read the assembly code from a file, check for semantic correctness, transform it into machine code and execute it on the virtual processor. 

   The interpreter will have the following components:
   - A lexical analyser
   - A parser
   - A semantic analyser
   - A code generator



## V. Nice to have

- Have a built-in debugger
- I/O operations inside the virtual terminal
- Have a wiki page with a detailed description of the more complex algorithms used in the project


## VI. Priorities

1. Smooth performance, each assembly instruction should be executed in the same amount of time
2. Correctness, the program should be able to run any semantically correct assembly program
3. Flexibility, the system should be designed to handle various assembly constructs and provide a foundation for potential future extensions


## VII. Technical Architecture

### Technology stack

- Operating System: Any modern, widely used operating system with support for C development (e.g., Linux, Windows, macOS)
- Programming Language: C17 (the most recent standard version)
- Compiler: GCC 14.0.0
- Integrated Development Environment (IDE): Visual Studio Code
- No additional libraries can be used besides C standard libraries


### Input data

One file on the command line.
- Arg[0] -  The input data will be a text file containing a program written in the assembly language. The program will be read by the interpreter and executed on the virtual processor.


### Output data

The output data will be the result of the execution of the assembly program or the errors returned by the program. The result will be displayed in the virtual terminal.


### Non-requirements / Out of scope

- Graphical debugger with visual representations of the register, data, and instruction memory
- Implementation of flags  

### Operating requirements

- The program should be able to run on any modern operating system with support for C development (e.g., Linux, Windows, macOS)
- The program should be able to run on any modern computer with a 64-bit processor.



### Key functions, operations, and algorithms

Some of the key operations that the software will perform and that need to be represented via functions are: 

- **Lexical Analysis (Tokenisation):**
   - Breaking down assembly code into tokens (instructions, registers, operands)
   - Removing whitespace and comments
- **Syntax Analysis (Parsing):**
   - Analysing tokens and verifying adherence to the assembly language grammar
   - Constructing an abstract syntax tree (AST) representing code structure
- **Semantic Analysis:**
   - Checking for the correctness of the assembly code
   - Ensuring that instructions are used appropriately, and operands have the correct types
- **Code Generation:**
   - Translate AST into machine code
   - Mapping assembly instructions to corresponding C functions or operations
- **Virtual Processor Execution:**
   - Implementing a virtual processor with registers, memory, and an execution pipeline
   - Executing generated machine code


### Algorithms  

The following section describes the algorithms described above in depth. Furthermore, it describes the skeleton of the program and the order in which the algorithms will be implemented.


### File Cleaning and Reading

Cleaning the file involves removing comments and whitespaces to facilitate easier reading. The size of the array storing the cleaned assembly code needs to be managed dynamically, considering potential memory constraints.

**Dynamic Array Allocation:**
   - The program will dynamically allocate memory for the array based on the size of the cleaned assembly code.
   - This dynamic allocation ensures flexibility, accommodating assembly programs of varying lengths without predefined size limitations.

```
// Initialise variables
// Initial assumption of a reasonable maximum number of lines

// Check for memory allocation success
    // Read the file line by line and dynamically allocate memory for each line
    // Assuming a maximum line length
        // Dynamically allocate memory for the current line

        // Check for memory allocation success
            // Handle memory allocation failure

    // Resize the array to the actual number of lines read

    // Continue with processing or error handling
    // Handle initial memory allocation failure


// Free allocated memory when done
```

Diagram of the cleaning function

![diagram](/Documents/Appendices/cleaning.png)

**Note:**
- The initial assumption of the maximum number of lines provides a starting point for memory allocation.
- Dynamic resizing after reading the file ensures efficient memory utilisation based on the actual number of lines.
- The program will read the file line by line and will check either if it's a carriage return or a line feed and remove it. Then, the program will remove the comments by checking if a ";" is present in the line and if it is, it will remove everything after it. Finally, this new file will be stored in a 2D array and will be used for the next step.


**Input data**
      
   ```
   MOV R1, #1
   MOV R2, #2

   ; This is a comment
   ADD R3, R1
   ```

**Output data**

   ```
   arrayFile[3][nbrLines]= {
      {"MOV", "R1", "#1"},
      {"MOV", "R2", "#2"},
      {"ADD", "R3", "R1"}
   }
   ```


 

### Lexical analysis (Tokenisation)

Tokenisation plays a crucial role by breaking down the assembly code into manageable units called tokens. Think of tokens as building blocks or Lego pieces that structure the code. Each token represents a specific element, like an instruction, register, or operand.

**Organisation:**
   - Tokens help organise the code into meaningful parts, making it easier for the computer to understand and process

**Simplification:**
   - Similar to spaces in a sentence, tokens simplify the code, aiding in the analysis of its structure

**Error Detection:**
   - Tokenisation aids in spotting errors early on. By breaking the code into tokens, we can quickly identify where issues might arise

**Efficient Parsing:**
   - Parsing the code becomes more efficient with tokens, acting as a clear guide for decoding the language

eg. 

```
// Non-Tokenised Assembly Code:
   {"MOV", "R1", "#1"},
   {"MOV", "R2", "#2"},
   {"ADD", "R3", "R1"}
```

```
// Tokenised Assembly Code
   {Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "1", 1, 3)},
   {Token("instruction", "MOV", 2, 1), Token("register", "R2", 2, 2), Token("immediate", "2", 2, 3)},
   {Token("instruction", "ADD", 3, 1), Token("register", "R3", 3, 2), Token("register", "R1", 3, 3)}
```

![diagram](/Documents/Appendices/tokenization.png)

**Note:**

The process for the tokenisation is the following:

   - The program will read the array line by line 
   - Then it will check every word of the line and it will create a token with the right type  and value according to the word. For this step, the "strcpm" function will be used to compare the word with the list of instructions, registers and operands. It's easy to implement and it's efficient.
   - Finally, it will replace each instruction, register and operand of the original array with the corresponding token

Each token will be represented by a struct with the following attributes:

   - **Type:** The type of the token (instruction, register, operand, etc...)
   - **Value:** The value of the token (MOV, R1, #1, etc...)
   - **Line:** The line where the token is located
   - **Column:** The column where the token is located

The tokenisation will be the first filter to check if the assembly code is correct. In this step the program will be able to handle the most obvious errors like:
   - Incorrect instructions
   - Incorrect registers
   - Incorrect operands

### Syntax analysis (Parsing)

The parser acts like a language detective. It takes the tokens, which are like the words of our assembly code, and figures out the rules that govern their arrangement. Think of it as a grammar expert for computers.

1. **Understanding Structure:**
   - The parser helps the computer understand the structure of the assembly code. It's like teaching it the rules of the language so it can follow along.

2. **Error Checking:**
   - Just like a teacher correcting grammar mistakes, the parser checks if the code follows the correct assembly language rules. 
3. **Creating a Plan:**
   - Once the parser understands the code structure, it creates a plan or a roadmap for the computer on how to execute the instructions. It's like giving directions for a task.

4. **Efficient Execution:**
   - By having a parser, the computer doesn't have to guess what the code means. It follows the parsed instructions step by step, ensuring efficient and accurate execution.

In a nutshell, the parser is like a language teacher and an instruction manual combined. It ensures the computer understands the code's structure, checks for mistakes, and creates a clear plan for smooth execution. In our project, having a reliable parser is key to making the virtual processor and interpreter work seamlessly.




**Note**

The process of the parsing is the following:
- Receive the tokenized assembly code obtained from the lexical analysis (tokenization) phase.

- Initialize a parsing pointer to the beginning of the token array.
  Set up data structures to represent the abstract syntax tree (AST) 

- Implement parsing rules based on those: 
```
<MOV> ::= <register> "," <register> | <register> "," <immediate> | <register> "," <adress>
<ADD> ::= <register> "," <register> | <register> "," <immediate> 
<SUB> ::= <register> "," <register> | <register> "," <immediate>
<MUL> ::= <register> "," <register> | <register> "," <immediate>
<DIV> ::= <register> "," <register> | <register> "," <immediate>
<AND> ::= <register> "," <register> | <register> "," <immediate>
<XOR> ::= <register> "," <register> | <register> "," <immediate>
<OR>  ::= <register> "," <register> | <register> "," <immediate>
<CMP> ::= <register> "," <register> | <register> "," <immediate>
<NOT> ::= <register> 
<GAD> ::= <register> 
<JMP> ::= <label>
<JE>  ::= <label>
<JNE> ::= <label>
<JG>  ::= <label>
<JGE> ::= <label>
<JL>  ::= <label>
<JLE> ::= <label>
<CALL>::= <label>
<RET> ::=
<END> ::=
<label> ::= "." <identifier>
<identifier> ::= <letter> | <identifier> <letter> | <identifier> <digit>
<letter> ::= "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z" | "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z"
<digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
```
These rules guide the parser in constructing the AST.

- Employ a top-down parsing approach, where the parsing process starts from the highest-level constructs and gradually descends to lower-level details. This aligns with the hierarchical nature of an assembly language. 

- The strategy typically follows a leftmost derivation, meaning that when multiple choices are available, the leftmost non-terminal is chosen.

- When an error is detected, the parser should provide error messages, including the printing of the line and the nature of the error. The error handling will be described in detail in the next section.

- As the parsing progresses successfully, construct the abstract syntax tree (AST) by linking nodes according to the hierarchical structure of the assembly language. Each node in the AST represents a syntactic construct, such as an instruction or operand.


- Once the entire token sequence is successfully parsed and the AST is constructed, the parsing phase concludes. The AST becomes the basis for further processing.


```mermaid
graph TD
  A[AST]
  A -->|Instruction| B1[Mov]
  B1 -->|Operand| B2[Register 'R1']
  B1 -->|Operand| B3[Immediate '#10']
  A -->|Instruction| C1[Add]
  C1 -->|Operand| C2[Register 'R2']
  C1 -->|Operand| C3[Register 'R1']
```


#### Errors handling

The parser will be able to handle the following errors:

**Unexpected Token:**
   - **Error Message:** "Unexpected token '{token}' found at line {print(line)}."
   - **Description:** This error occurs when the parser encounters a token that is unexpected based on the current context. The error message specifies the token and the line where the issue is located.
  
**Unexpected End of File:**
   - **Error Message:** "Unexpected end of file. Expected more tokens to complete the syntax."
   - **Description:** This error is raised when the parser reaches the end of the file but expects additional tokens to complete a syntactic structure. The message indicates an unexpected termination.

**Mismatched Types:**
   - **Error Message:** "Type mismatch: Expected {expected_type}, but found {actual_type} at line {print(line)}."
   - **Description:** This error occurs when there is a mismatch between expected and actual data types. The message specifies the expected and actual types, along with the error location.

**Invalid Syntax:**
   - **Error Message:** "Invalid syntax at line {print(line)}. Unable to parse the provided code."
   - **Description:** This generic error indicates that the parser encountered a syntax that doesn't conform to the language's grammar rules. The message communicates the location of the syntax error.

**Redundant Tokens:**
   - **Error Message:** "Redundant tokens found at line {print(line)}. Remove or correct the extra tokens."
   - **Description:** This error signals the presence of extra or redundant tokens in the code. The message advises removing or correcting the surplus tokens at the specified location.

**Undefined label:**
   - **Error Message:** "Undefined {label} '{name}' at line {print(line)}."
   - **Description:** When the parser encounters an undeclared label, this error is raised. The message indicates the type (variable or identifier) and the name of the undefined entity.

**Duplicate label:**
   - **Error Message:** "Duplicate {label} '{name}' at line {print(line)}."
   - **Description:** This error occurs when the parser encounters a duplicate label. The message specifies the type (variable or identifier) and the name of the duplicate entity.

**Invalid Operand:**
   - **Error Message:** "Invalid operand '{operand}' at line {print(line)}."
   - **Description:** This error indicates that the parser encountered an invalid operand. The message specifies the operand and the location of the error.

---




### Semantic analysis
Semantic analysis ensures the computer comprehends the intended meaning behind assembly code, going beyond mere rule-following.

**Meaningful Understanding:**
   - It ensures the computer grasps the intended meaning of the code, aligning everyone on the same page

**Correct Usage of Instructions:**
   - Like a wise friend correcting language misuse, semantic analysis checks for correct assembly instruction usage

**Operands Compatibility:**
   - Similar to preventing illogical comparisons, semantic analysis ensures compatible operands, avoiding confusion for the computer

**Preventing Confusion:**
   - By understanding the code's meaning, semantic analysis prevents confusion, ensuring correct execution

For semantically incorrect assembly programs, the program will:
   - Provide detailed error messages specifying the nature and location of semantic errors.
   - Halt program execution to prevent undefined behavior.
   - Avoid compromising subsequent instructions' integrity with corrective actions.


### Code generation
The AST is translated into an intermediate representation or machine code.
Each assembly language instruction is mapped to corresponding C functions or operations.


- **Assembly Code Size:** Each instruction in the assembly code is in 32-bit format.
- **Instruction Width:** Every instruction is 64 bits wide.
- **Data Storage:** Data is stored in little-endian format.

#### Instruction format
- **Opcode (Byte 1):** The first byte signifies the opcode of the instruction.
- **Register (Byte 2):** The second byte represents the register.
- **Data Bytes (Bytes 3-6):** The third, fourth, fifth, and sixth bytes collectively encode the data associated with the instruction.

**Opcodes**  

|**Instruction**| **Opcode** |
|-----------|----------------|
|MOV R1, 0X332| 0x10         |
|MOV A1, adress|0x11         |
|MOV R1, R2|    0x12         | 
|-|       -                  |
|ADD R1, R2|    0x20         |
|ADD R1, 0X332 |0x22         |
|SUB R1, R2|    0x21         |
|SUB R1, 0X332 |0x23         |
|MUL R1, R2|    0x30         |
|MUL R1, 0X332| 0x31         |
|DIV R1, R2    |0x40         |
|DIV R1, 0X332|0x41         |
|-|          -               |
|.label|       0x99          |
|END|          0x98          |
|RET|          0x97          |
|CALL|         0x96          |
|-|            -             |
|CMP R1, R2|   0x50          |
|CMP R1, 0X332|0x51          |
|-|       -                  |
|JMP .label|   0x60          |
|JE .label|    0x61          |
|JNE .label|   0x62          |
|JG .label|    0x63          |
|JGE .label|   0x64          |
|JL .label|    0x65          |
|JLE .label|   0x66          |
|-|-                         | 
|AND R1, R2|   0x70          |
|AND R1, 0X332|0x71          |
|XOR R1, R2|   0x72          |
|XOR R1, 0X332|0x73          |
|OR R1, R2|    0x74          |
|OR R1, 0X332| 0x75          |
|NOT R1|       0x76          |
|GAD R1|       0x77          |
|-|       -                  |
|**General Register**|       |
|R1 |          0x01          | 
|R2 |          0x02          | 
|R3 |          0x03          | 
|R4 |          0x04          | 
|**Adress register** |       | 
|A1 |          0x11          | 
|A2 |          0x12          | 
|A3 |          0x13          |
|A4 |          0x14          |
       


**Example of MOV instruction**

|0x12| 0x01| 0x00| 0x00| 0x00| 0x02|
|----|-----|-----|-----|-----|-----|
|MOV | R1  | Unused| Unused| Unused| R2|
|OPCODE| REGISTER | DATA | DATA | DATA | DATA |


|0x10| 0x01| 0x00| 0x00| 0x19| 0x23|
|----|-----|-----|-----|-----|-----|
|MOV | R1  | Unused| Unused| 25 | 35 |
|OPCODE| REGISTER | DATA | DATA | DATA | DATA |



### Virtual processor

In this section, we're constructing a virtual machine (VM) with its own instruction set to serve as the target platform for our interpreter's code generation phase. Similar to the JVM and bytecode concept, but in a much simpler form.

#### Internal Components of a Computer

We focus on three main components: CPU, registers, and memory. Instructions, represented as binary data, reside in memory. The CPU retrieves and executes instructions sequentially, and the machine's running state is stored in registers.

#### Memory
- Memory stores data, including code and other information.
- Segments: `text` (code), `data` (initialized data), `bss` (uninitialized data), `stack` (function call states), `heap` (dynamic memory allocation).
- For simplicity, we merge `data` and `bss`, using `data` for string literals.

#### Registers
- `PC` (Program Counter): Stores the memory address of the next instruction.
- `SP` (Stack Pointer): Points to the top of the stack, used for function calls.
- `BP` (Base Pointer): Points to elements on the stack, aiding function calls.
- `AX`: General register storing instruction results.
- `cycle`: Virtual machine cycle count.


## VIII. Syntax and Structure

### Folder structure

```
📦2023-2024-project-3-virtual-processor
└── 📁.github
|    └── 📁ISSUE_TEMPLATE
|    |   └── 📄 bug_report.yml
└── 📁Documents
|    └── 📁Appendices
|    └── 📝 ProjectCharter.md
|    └── 📝 TechnicalSpecifications.md
|    └── 📝 FunctionalSpecifications.md
|    └── 📝 TestPlan.md
|    └── 📁QaArtefacts 
|    └── 📁ManagementArtefacts 
└── 📁Src
|    └── 📄 vm.h
|    └── 📄 lexical.h
|    └── 📄 parser.h
|    └── 📄 global.h
|    └── 📄 assemblyCode.asm2
|    └── 📄 interpreter.c
└── 📄 .gitignore
└── 📄 LICENSE
└── 📝 README.MD 
```

**vm.h** - Header file for the virtual processor

**lexical.h** - Header file for the lexical analysis

**parser.h** - Header file for the parser

**global.h** - Header file for the global variables and centralised point for all the header files import

**assemblyCode.asm2** - Assembly code file

**interpreter.c** - Main file for the interpreter

### Program file structure 

1. **Prologue:**
   - Start the file with a prologue describing the purpose of objects (functions, data declarations, etc.)
   - *Optionally include author(s), revision control information, references, etc*

2. **Header Files:**
   - Include any necessary header files, such as `#include <stdio.h>`
   - The "system includes" must precede "user includes" for clarity
   - Comment on non-obvious inclusions, if any

3. **Defines and Typedefs:**
   - Define constants first, followed by function macros, typedefs, and enums

4. **Global Data Declarations:**
   - Order global data declarations as follows:
      - Externs
      - Non-static globals
      - Static globals

5. **Functions:**
   - Arrange functions in a meaningful order, considering a "breadth-first" approach
   - Group similar functions together for clarity
   - Consider alphabetical order for large sets of independent utility functions


### Function declaration 

Each function should be preceded by a block comment prologue that gives a short description of what the function does.


### Naming

- **File names**: should be in camelCase
- **`#define`:** constants should be in all CAPS
- **Enum constants**: are in all CAPS
- **Function**, **typedef**, and **variable names**, as well as **struct**, **union**, and **enum tag names**, should be in camelCase
- **Macro "functions"** are in all CAPS
- **Typedef** names should have "`_t`" appended to their name


### Comments 

- Putting comments at the top of a 3-10 line section telling what it does
```
/*
* Here is a block comment.
* The comment text should be tabbed or spaced over uniformly.
* The opening slash-star and closing star-slash are alone on a line.
*/ 
```


## IX. Code Design Principles

The following are the coding design principles: 

 - No use of third-party libraries
 - Emphasise improved algorithmic complexity over micro-optimisation 
 - Use unit tests to ensure correctness during development


## X. Ideas and Hypotheses
//TODO
### Unproven hypotheses
//TODO
### Proven Hypotheses
//TODO

## XI. Challenges

- Developing a robust lexer and parser for precise assembly code tokenisation, and managing diverse language constructs, poses a significant challenge
- Enforcing correct usage of assembly instructions and operands through semantic analysis requires careful consideration to detect and prevent potential runtime errors
- Implementing parsing by string comparison is relatively straightforward; the true challenge lies in the conversion to machine code
- Handling labels and function calls within the assembly code introduces an additional challenge, requiring effective management of addresses, offsets, and the intricacies of control flow



## XII. Possible Bugs

- The system may not be able to handle large assembly programs
- The system may not be able to handle complex assembly programs
- The system takes too long to execute
- The system may have trouble translating the assembly code into machine code and it can result in an incorrect result
- The system may not be able to detect major errors for instance: overflow, underflow, division by zero, etc
- We assume that the user will not comment until the end of the line, if it does, the system may not be able to detect it


## XIII. Development Process

//todo



## XIV. Glossary

- **breadth-first approach** -  A breadth-first approach is a graph traversal method that starts at the root node and visits all the neighboring nodes. Then for each of those nearest nodes, it visits their unexplored neighbor nodes, and so on, until it finds the goal.
-  **Virtual processor** - A vCPU is a processor simulated within a virtual machine, allowing the execution of one processor thread. These vCPUs are allocated from the physical CPU resources of the host machine.
-  **Lexical analysis** - lexical analysis is the process of converting a sequence of characters (such as in a computer program or web page) into a sequence of tokens (strings with an identified "meaning").




