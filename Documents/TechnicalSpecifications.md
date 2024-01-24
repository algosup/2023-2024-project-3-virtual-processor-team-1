
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
    - [Input data](#input-data)
    - [Output data](#output-data)
    - [Non-requirements / Out of scope](#non-requirements--out-of-scope)
    - [Operating requirements](#operating-requirements)
    - [Key functions, operations, and algorithms](#key-functions-operations-and-algorithms)
    - [Algorithms](#algorithms)
  - [VIII. Syntax and Structure](#viii-syntax-and-structure)
    - [1. Folder structure](#1-folder-structure)
    - [2. Program file structure](#2-program-file-structure)
    - [3. Function declaration](#3-function-declaration)
    - [4. Naming](#4-naming)
    - [5. Comments](#5-comments)
  - [IX. Code Design Principles](#ix-code-design-principles)
  - [X. Challenge](#x-challenge)
  - [XI. Possible Bugs](#xi-possible-bugs)
  - [XII. Development Process](#xii-development-process)
  - [XIII. Glossary](#xiii-glossary)

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
- Write a small assembly program conceptually similar to unit tests to showcase that everything is working 


## V. Nice to have

- Have a built-in debugger
- I/O operations inside the virtual terminal


## VI. Priorities

1.  Smooth performance, each assembly instruction should be executed in the same amount of time
2. Correctness, the program should be able to run any semantically correct assembly program


## VII. Technical Architecture

### 1. Technology stack

- Operating System: Any modern, widely used operating system with support for C development (e.g., Linux, Windows, macOS)
- Programming Language: C17 (the most recent standard version)
- Compiler: GCC 14.0.0
- Integrated Development Environment (IDE): Visual Studio Code
- No additional libraries can be used besides C standard libraries


### Input data

One file on the command line.
- Arg[0] -  The input data will be a text file containing a program written in the assembly language. The program will be read by the interpreter and executed on the virtual processor.


### Output data

The output data will be the result of the execution of the assembly program. The result will be displayed in the virtual terminal.


### Non-requirements / Out of scope

- Graphical debugger with visual representations of the register, data, and instruction memory
- Implementation of flags
- 

### Operating requirements

- The program should be able to run on any modern operating system with support for C development (e.g., Linux, Windows, macOS)
- The program should be able to run on any modern computer with a 64-bit processor.



### Key functions, operations, and algorithms

Some of the key operations that the software will perform and that need to be represented via functions are: 

- **Lexical Analysis (Tokenization):**
   - Breaking down assembly code into tokens (instructions, registers, operands)
   - Removing whitespace and comments
- **Syntax Analysis (Parsing):**
   - Analyzing tokens and verifying adherence to assembly language grammar
   - Constructing an abstract syntax tree (AST) representing code structure
- **Code Generation:**
   - Translate AST into machine code
   - Mapping assembly instructions to corresponding C functions or operations
- **Virtual Processor Execution:**
   - Implementing a virtual processor with registers, memory, and an execution pipeline
   - Executing generated machine code
- **System Calls and I/O:**
   - Defining and implementing the system calls for virtual terminal interaction
   - Enable assembly code for text display. 




### Algorithms  

// TODO



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
    └── 📄 assemblyCode.algoasm
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


## X. Challenge 

- Developing a robust lexer and parser for precise assembly code tokenization, and managing diverse language constructs, poses a significant challenge
- Enforcing correct usage of assembly instructions and operands through semantic analysis requires careful consideration to detect and prevent potential runtime errors
- Implementing parsing by string comparison is relatively straightforward; the true challenge lies in the conversion to machine code
- Handling labels and function calls within the assembly code introduces an additional challenge, requiring effective management of addresses, offsets, and the intricacies of control flow.
## XI. Possible Bugs

- The system may not be able to handle large assembly programs
- The system may not be able to handle complex assembly programs
- The system takes too long to execute


## XII. Development Process

//todo



## XIII. Glossary

- **breadth-first approach** -  A breadth-first approach is a graph traversal method that starts at the root node and visits all the neighboring nodes. Then for each of those nearest nodes, it visits their unexplored neighbor nodes, and so on, until it finds the goal.
-  **Virtual processor** - A vCPU is a processor simulated within a virtual machine, allowing the execution of one processor thread. These vCPUs are allocated from the physical CPU resources of the host machine.
-  **Lexical analysis** - lexical analysis is the process of converting a sequence of characters (such as in a computer program or web page) into a sequence of tokens (strings with an identified "meaning").




