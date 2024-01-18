
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
  - [VIII. Naming and Convention](#viii-naming-and-convention)
    - [1. Program file structure](#1-program-file-structure)
    - [2. Function declaration](#2-function-declaration)
    - [3. Naming](#3-naming)
    - [4. Comments](#4-comments)
  - [IX. Code Design Principles](#ix-code-design-principles)
  - [X. Possible Bugs](#x-possible-bugs)
  - [XI. Development Process](#xi-development-process)
  - [XII. Glossary](#xii-glossary)

</details>


## I. Audience

This document is primarily intended for:

* Software developer - to understand the user and technical requirements, and to guide decision-making and planning. Help them understand risks and challenges, customer requirements, and additional technical requirements and choices made.  
  
Secondary audiences
* Program manager - to validate against the functional specification, and the client expectations.
* QA - to aid in preparing the test plan and to use it for validating issues.
* Project manager - to help identify risks and dependencies.


## II. Deliverable 

 The goal of the project is to create a virtual processor and an interpreter for running assembly code on that processor

## III. Details 

The project will be developed in plain, portable, C language without using any external library besides C standard libraries. 

## IV. Requirements 

-  Create a minimal assembly language (This requirement is fully described in the [functional specification](./FunctionalSpecifications.md.md))
-  Write a program that can read a text file containing a program written in the aforementioned assembly language and run it
	- The program should also check if the assembly program is semantically correct and detect syntactical errors 
- Implement a virtual system call for displaying text in a virtual terminal, that can be accessed from the assembly code  
- Write a small assembly program conceptually similar to unit tests to showcase that everything is working 


## V. Nice to have

- Display the content of assembly registers 
- Have a built-in debugger

// TODO: Add more details



## VI. Priorities

- 


## VII. Technical Architecture

### 1. Technology stack

- Operating System: Any modern, widely used operating system with support for C development (e.g., Linux, Windows, macOS).
- Programming Language: C17
- Compiler: GCC 14.0.0
- Integrated Development Environment (IDE): Visual Studio Code
- No additional libraries can be used besides C standard libraries



## VIII. Naming and Convention

### 1. Program file structure 

1. **Prologue:**
   - Start the file with a prologue describing the purpose of objects (functions, data declarations, etc.).
   - Optionally include author(s), revision control information, references, etc.

2. **Header Files:**
   - Include any necessary header files, such as `#include <stdio.h>`.
   - The "system includes" must precede "user includes" for clarity.
   - Comment on non-obvious inclusions, if any.

3. **Defines and Typedefs:**
   - Define constants first, followed by function macros, typedefs, and enums.

4. **Global Data Declarations:**
   - Order global data declarations as follows:
      - Externs
      - Non-static globals
      - Static globals

5. **Functions:**
   - Arrange functions in a meaningful order, considering a "breadth-first" approach.
   - Group similar functions together for clarity.
   - Consider alphabetical order for large sets of independent utility functions.


### 2. Function declaration 

Each function should be preceded by a block comment prologue that gives a short description of what the function does.

Moreover, if the function should return nothing; you should use the keyword **void** instead of **int**

### 3. Naming

- **`#define`:** constants should be in all CAPS
- **Enum constants**: are in all CAPS
- **Function**, **typedef**, and **variable names**, as well as **struct**, **union**, and **enum tag names**, should be in camelCase
- **Macro "functions"** are in all CAPS
- **Typedef** names should have "`_t`" appended to their name.


### 4. Comments 

- Putting comment at the top of a 3-10 line section telling what it does
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
 - Use unit tests to ensure correctness during development.

## X. Possible Bugs

## XI. Development Process

1. **Lexical Analysis (Tokenization):**
   - Implement a lexer to break down assembly code into tokens (instructions, registers, operands).
   - Handle whitespace and comments during tokenization.

2. **Syntax Analysis (Parsing):**
   - Develop a parser to analyze tokens and verify adherence to assembly language grammar.
   - Construct an abstract syntax tree (AST) representing code structure.

3. **Semantic Analysis:**
   - Implement semantic analysis to check assembly code validity.
   - Ensure correct usage of instructions and operand types.

4. **Code Generation:**
   - Translate AST into intermediate representation or machine code.
   - Map assembly instructions to corresponding C functions or operations.

5. **Virtual Processor Execution:**
   - Implement virtual processor with registers, memory, and execution pipeline.
   - Execute generated machine code in a controlled environment.

6. **System Calls and I/O:**
   - Define and implement system calls for virtual terminal interaction.
   - Enable assembly code for text display and I/O operations.

7. **Error Handling and Debugging:**
   - Develop robust error handling for syntax and semantic errors.
   - Implement a built-in debugger for step-by-step execution and variable inspection.

8. **Unit Testing:**
   - Create unit tests for virtual processor and interpreter.
   - Include tests for various instructions, edge cases, and error scenarios.

9. **Integration and System Testing:**
   - Integrate all components and conduct comprehensive system tests.
   - Validate assembly program execution against expected outcomes.

10. **Optimization:**
    - Optimize code and algorithms for improved performance.
    - Fine-tune the virtual processor's execution efficiency.



## XII. Glossary

- **breadth-first approach** -  A breadth-first approach is a graph traversal method that starts at the root node and visits all the neighboring nodes. Then for each of those nearest nodes, it visits their unexplored neighbor nodes, and so on, until it finds the goal.
-  **Virtual processor** - A vCPU is a processor simulated within a virtual machine, allowing the execution of one processor thread. These vCPUs are allocated from the physical CPU resources of the host machine.
