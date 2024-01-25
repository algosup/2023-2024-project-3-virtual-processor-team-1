
**Technical Specification - Virtual Processor and Interpreter**

*Document Version: 1.0*

---

# DEADLINE 9/2 5pm  

<details>
<summary>Table of Contents</summary>

- [DEADLINE 9/2 5pm](#deadline-92-5pm)
  - [I. Audience](#i-audience)
  - [II. Deliverable](#ii-deliverable)
  - [III. Details](#iii-details)
  - [IV. Requirements](#iv-requirements)
  - [V. Nice to have](#v-nice-to-have)
  - [VI. Priorities](#vi-priorities)
  - [VII. Technical Architecture](#vii-technical-architecture)
    - [1. Technology stack](#1-technology-stack)
    - [2. Input data](#2-input-data)
    - [3. Output data](#3-output-data)
    - [4. Non-requirements / Out of scope](#4-non-requirements--out-of-scope)
    - [5. Operating requirements](#5-operating-requirements)
    - [6. Key functions, operations, and algorithms](#6-key-functions-operations-and-algorithms)
    - [7. Algorithms](#7-algorithms)
    - [1. File cleaning and reading](#1-file-cleaning-and-reading)
    - [2. Lexical analysis (Tokenization)](#2-lexical-analysis-tokenization)
    - [3. Syntax analysis (Parsing)](#3-syntax-analysis-parsing)
    - [4. Semantic analysis](#4-semantic-analysis)
    - [5. Code generation](#5-code-generation)
    - [6. Virtual processor](#6-virtual-processor)
  - [VIII. Syntax and Structure](#viii-syntax-and-structure)
    - [1. Folder structure](#1-folder-structure)
    - [2. Program file structure](#2-program-file-structure)
    - [3. Function declaration](#3-function-declaration)
    - [4. Naming](#4-naming)
    - [5. Comments](#5-comments)
  - [IX. Code Design Principles](#ix-code-design-principles)
  - [X. Ideas and Hypotheses](#x-ideas-and-hypotheses)
    - [1. Unproven hypotheses](#1-unproven-hypotheses)
    - [2. Proven Hypotheses](#2-proven-hypotheses)
  - [XI. Challenges](#xi-challenges)
  - [XII. Possible Bugs](#xii-possible-bugs)
  - [XIII. Development Process](#xiii-development-process)
  - [XIV. Glossary](#xiv-glossary)

</details>


## I. Audience

This document is primarily intended for:

* Software developer - to understand the user and technical requirements, and to guide decision-making and planning. Help them understand risks and challenges, customer requirements, and additional technical requirements and choices made.  
  
Secondary audiences
* Program manager - to validate against the functional specification, and the client expectations.
* QA - to aid in preparing the test plan and to use it for validating issues.
* Project manager - to help identify risks and dependencies.


## II. Deliverable 

 The goal of the project is to create a virtual processor and an interpreter for running assembly code on that processor.

## III. Details 

The project will be developed in plain, portable, C language without using any external library besides C standard libraries. 

## IV. Requirements 

-  Create a minimal assembly language (This requirement is fully described in the [functional specification](./FunctionalSpecifications.md.md))
-  Write a program that can read a text file containing a program written in the aforementioned assembly language and run it
	- The program should also check if the assembly program is semantically correct and detect syntactical errors 
- Implement a virtual system call for displaying text in a virtual terminal, that can be accessed from the assembly code  
- Implement a virtual processor that can execute the assembly code
- Write a small assembly program conceptually similar to unit tests to showcase that everything is working 


## V. Nice to have

- Have a built-in debugger
- I/O operations inside the virtual terminal
- Have a wiki page with a detailed description of the more complex algorithms used in the project


## VI. Priorities

1. Smooth performance, each assembly instruction should be executed in the same amount of time
2. Correctness, the program should be able to run any semantically correct assembly program


## VII. Technical Architecture

### 1. Technology stack

- Operating System: Any modern, widely used operating system with support for C development (e.g., Linux, Windows, macOS)
- Programming Language: C17 (the most recent standard version)
- Compiler: GCC 14.0.0
- Integrated Development Environment (IDE): Visual Studio Code
- No additional libraries can be used besides C standard libraries


### 2. Input data

One file on the command line.
- Arg[0] -  The input data will be a text file containing a program written in the assembly language. The program will be read by the interpreter and executed on the virtual processor.


### 3. Output data

The output data will be the result of the execution of the assembly program. The result will be displayed in the virtual terminal.


### 4. Non-requirements / Out of scope

- Graphical debugger with visual representations of the register, data, and instruction memory
- Implementation of flags  

### 5. Operating requirements

- The program should be able to run on any modern operating system with support for C development (e.g., Linux, Windows, macOS)
- The program should be able to run on any modern computer with a 64-bit processor.



### 6. Key functions, operations, and algorithms

Some of the key operations that the software will perform and that need to be represented via functions are: 

- **Lexical Analysis (Tokenization):**
   - Breaking down assembly code into tokens (instructions, registers, operands)
   - Removing whitespace and comments
- **Syntax Analysis (Parsing):**
   - Analyzing tokens and verifying adherence to assembly language grammar
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
   - Mimicking the behavior of a physical processor


### 7. Algorithms  

The following section describes the algorithms described above in depth. Furthermore, it describes the skeleton of the program and the order in which the algorithms will be implemented.

### 1. File cleaning and reading

Cleaning the file of any comments and whitespaces will make the reading of the file easier. The file will be read line by line without being parasitized by comments and whitespaces.

![diagram](/Documents/Appendices/cleanFile.png)

Basically, the program will read the file line by line and will check either if it's a carriage return or a line feed and remove it. Then, the program will remove the comments by checking if a ";" is present in the line and if it is, it will remove everything after it. Finally, this new file will be stored in a 2D array and will be used for the next step.

**Input data**
      
   ```
   MOV R1, #1
   MOV R2, #2

   ; This is a comment
   ADD R3, R1
   ```

**Output data**

   ```
   arrayFile[3][10]= {
      {"MOV", "R1", "#1"},
      {"MOV", "R2", "#2"},
      {"ADD", "R3", "R1"}
   }
   ```

The size of the array should be dynamic and should be able to store any size of the assembly program.
 

### 2. Lexical analysis (Tokenization)

Tokenization plays a crucial role by breaking down the assembly code into manageable units called tokens. Think of tokens as building blocks or Lego pieces that make up the code. Each token represents a specific element, like an instruction, register, or operand.

1. **Organization:**
   - Tokens help organize the code into meaningful parts, making it easier for the computer to understand and process

2. **Simplification:**
   - It simplifies the code for analysis. Imagine reading a sentence without spaces; it would be challenging to grasp the meaning. Similarly, tokens create structure in the code

3. **Error Detection:**
   - Tokenization aids in spotting errors early on. By breaking the code into tokens, we can quickly identify where issues might arise

4. **Efficient Parsing:**
   - It makes parsing, or understanding the code's structure, more efficient. Parsing is like decoding a language, and tokens provide a clear guide

eg. 

```
// Assembly code
MOV R1, #1
MOV R2, #2
ADD R3, R1
```

```
// Tokenized assembly code
[(instruction, MOV), (register, R1), (immediate, #1)]
[(instruction, MOV), (register, R2), (immediate, #2)]
[(instruction, ADD), (register, R3), (register, R1)]
```



### 3. Syntax analysis (Parsing)

The parser acts like a language detective. It takes the tokens, which are like the words of our assembly code, and figures out the rules that govern their arrangement. Think of it as a grammar expert for computers.

1. **Understanding Structure:**
   - The parser helps the computer understand the structure of the assembly code. It's like teaching it the rules of the language so it can follow along.

2. **Error Checking:**
   - Just like a teacher correcting grammar mistakes, the parser checks if the code follows the correct assembly language rules. If there's a mistake, it raises a flag.

3. **Creating a Plan:**
   - Once the parser understands the code structure, it creates a plan or a roadmap for the computer on how to execute the instructions. It's like giving directions for a task.

4. **Efficient Execution:**
   - By having a parser, the computer doesn't have to guess what the code means. It follows the parsed instructions step by step, ensuring efficient and accurate execution.

In a nutshell, the parser is like a language teacher and an instruction manual combined. It ensures the computer understands the code's structure, checks for mistakes, and creates a clear plan for smooth execution. In our project, having a reliable parser is key to making the virtual processor and interpreter work seamlessly.

```
// Tokenized assembly code
[(instruction, MOV), (register, R1), (immediate, #1)]
[(instruction, MOV), (register, R2), (immediate, #2)]
[(instruction, ADD), (register, R3), (register, R1)]
```

```
// Parse tree
MOV(instruction)
               ├── R1(register)
               └── #1(immediate)
MOV(instruction)
               ├── R2(register)
               └── #2(immmediate)
ADD(instruction)
               ├── R3(register)
               └── R1(register)

```


### 4. Semantic analysis

Semantic analysis is like having a wise friend who not only understands what you say but also ensures you're making sense. It helps the computer not just follow the rules but also understand the meaning behind the assembly code.

1. **Meaningful Understanding:**
   - Semantic analysis ensures that the computer doesn't just mechanically process code; it grasps the intended meaning. It's like making sure everyone is on the same page.

2. **Correct Usage of Instructions:**
   - Just as our wise friend corrects us if we use a word in the wrong context, semantic analysis checks if we're using assembly instructions correctly. It ensures the code makes logical sense.

3. **Operands Compatibility:**
   - It's like our friend making sure we don't compare apples to oranges. Semantic analysis checks if the operands used in instructions are compatible, avoiding confusion for the computer.

4. **Preventing Confusion:**
   - By understanding the meaning of the code, semantic analysis prevents confusion. It ensures the computer doesn't get lost in translation and executes the instructions correctly.

Semantic analysis is crucial for a computer to go beyond just following rules. It ensures the code makes sense, uses instructions correctly, and avoids any confusion during execution. 







### 5. Code generation
The AST is translated into an intermediate representation or machine code.
Each assembly language instruction is mapped to corresponding C functions or operations.

### 6. Virtual processor






## VIII. Syntax and Structure

### 1. Folder structure

```
📦2023-2024-project-3-virtual-processor
└── 📁.github
    └── 📁ISSUE_TEMPLATE
        └── 📄 bug_report.yml
└── 📁Documents
    └── 📁Appendices
    └── 📝 ProjectCharter.md
    └── 📝 TechnicalSpecifications.md
    └── 📝 FunctionalSpecifications.md
    └── 📝 TestPlan.md
    └── 📁QaArtefacts 
    └── 📁ManagementArtefacts 
└── 📁Src
    └── 📄 vm.h
    └── 📄 lexical.h
    └── 📄 parser.h
    └── 📄 global.h
    └── 📄 assemblyCode.asm2
    └── 📄 interpreter.c
└── 📄 .gitignore
└── 📄 LICENSE
└── 📝 README.MD 
```

### 2. Program file structure 

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


### 3. Function declaration 

Each function should be preceded by a block comment prologue that gives a short description of what the function does.

Moreover, if the function should return nothing; you should use the keyword **void** instead of **int**

eg.

```
int MyFunction(str input) {
    // ----snip----
    return -1;  // The "-1" is merely a placeholder for function exit and is unrelated to the intended data processing.
}

// Use the keyword "void" instead of "int". It will enhance the comprehension of the code and not create confusion in the intended data processing. 

void MyFunction(str input){
    // ----snip----
    return;
}
```

### 4. Naming

- **File names**: should be in camelCase
- **`#define`:** constants should be in all CAPS
- **Enum constants**: are in all CAPS
- **Function**, **typedef**, and **variable names**, as well as **struct**, **union**, and **enum tag names**, should be in camelCase
- **Macro "functions"** are in all CAPS
- **Typedef** names should have "`_t`" appended to their name


### 5. Comments 

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
 - Emphasize improved algorithmic complexity over micro-optimization 
 - Use unit tests to ensure correctness during development


## X. Ideas and Hypotheses
//TODO
### 1. Unproven hypotheses
//TODO
### 2. Proven Hypotheses
//TODO

## XI. Challenges

- Developing a robust lexer and parser for precise assembly code tokenization, and managing diverse language constructs, poses a significant challenge
- Enforcing correct usage of assembly instructions and operands through semantic analysis requires careful consideration to detect and prevent potential runtime errors
- Implementing parsing by string comparison is relatively straightforward; the true challenge lies in the conversion to machine code
- Handling labels and function calls within the assembly code introduces an additional challenge, requiring effective management of addresses, offsets, and the intricacies of control flow.



## XII. Possible Bugs

- The system may not be able to handle large assembly programs
- The system may not be able to handle complex assembly programs
- The system takes too long to execute
- The system may have trouble translating the assembly code into machine code and it can result in an incorrect result
- The system may not be able to detect major errors for instance: overflow, underflow, division by zero, etc.


## XIII. Development Process

//todo



## XIV. Glossary

- **breadth-first approach** -  A breadth-first approach is a graph traversal method that starts at the root node and visits all the neighboring nodes. Then for each of those nearest nodes, it visits their unexplored neighbor nodes, and so on, until it finds the goal.
-  **Virtual processor** - A vCPU is a processor simulated within a virtual machine, allowing the execution of one processor thread. These vCPUs are allocated from the physical CPU resources of the host machine.
-  **Lexical analysis** - lexical analysis is the process of converting a sequence of characters (such as in a computer program or web page) into a sequence of tokens (strings with an identified "meaning").




