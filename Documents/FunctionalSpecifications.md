# Functional Specifications

## Table of content
- [Functional Specifications](#functional-specifications)
  - [Table of content](#table-of-content)
  - [I. Document control](#i-document-control)
    - [1. Document information](#1-document-information)
    - [2. Document approval](#2-document-approval)
  - [II. Introduction](#ii-introduction)
    - [1. Project Overview](#1-project-overview)
    - [2. Project Definition](#2-project-definition)
      - [2.1 Our vision](#21-uour-visionu)
      - [2.2 Objectives](#22-uobjectivesu)
      - [2.3 Scope](#23-uscopeu)
      - [2.4 Deliverables](#24-udeliverablesu)
    - [3. Project Organisation](#3-uproject-organisationu)
      - [3.1 Project representation](#31-uproject-representationu)
      - [3.2 Stakeholders](#32-ustakeholdersu)
      - [3.3 Project roles](#33-uproject-rolesu)
      - [3.4 Project reviewers](#34-uproject-reviewersu)
    - [4. Project Plan](#4-project-plan)
      - [4.1 Retroplanning](#41-uretroplanningu)
      - [4.2 Milestones](#42-umilestonesu)
      - [4.3 Dependencies](#43-udependenciesu)
      - [4.4 Resources/Financial plan](#44-uresourcesfinancial-planu)
      - [4.5 Assumptions/Constraints](#45-uassumptionsconstraintsu)
  - [III. Functional Requirements](#iii-functional-requirements)
  - [IV. Non-Functional Requirements](#iv-non-functional-requirements)
  - [V. Glossary](#v-glossary)

## I. Document control
### 1. Document Information
| **Document Name**  | Functional Specifications |
|--------------------|---------------------------|
| **Document Owner** | DELILLE Elone             |

### 2. Document Approval
| **Role** | **Name** | **Signature**  | **Date** |
|---|---|----------------|---|
| Project Manager | CUREL Clémentine |                | |
| Program Manager | DELILLE Elone | ✅              | |
| Technical Leader | PLANCHARD Thomas |                | |
| Software Engineer | LASSELIN Alexis |                | |
| Software Engineer | NAMIR Salaheddine |                | |
| Quality Assurance | BAVAROIS Séréna |                | |

## II. Introduction
### 1. Project Overview
The aim of the project is to design both a **virtual processor**[^1] and an **interpreter**[^2] capable of executing **assembly code**[^3], coded by us during the project. It will be developed in pure, portable **C language**[^4], relying solely on [standard C](https://en.wikipedia.org/wiki/C_standard_library) **libraries**[^5], to the exclusion of any external **dependencies**[^6].

### 2. Project Definition
#### 2.1 <u>Our vision</u>
- We have to create our own assembly language and run it using a code interpreter that we will create in the C programming language. We must be able to run a programme that meets the requirements of the customer, JEANNIN Franck.
#### 2.2 <u>Objectives</u>

#### 2.3 <u>Scope</u>

| **In scope**                                                                                                |
|-------------------------------------------------------------------------------------------------------------|
| Storing an immediate value in a register.                                                                   |
| Copying the contents of one register to another.                                                            |
| Reading memory data from the address stored in a register and placing it in another register.               |
| Storing the value from a register into memory using the address in another register.                        |
| Comparing the contents of registers.                                                                        |
| Performing an unconditional jump to a labeled instruction.                                                  |
| Performing a conditional jump to a labeled instruction.                                                     |
| Executing a subroutine call.                                                                                |
| Returning from a subroutine.                                                                                |
| Performing the four fundamental arithmetic operations: addition, subtraction, multiplication, and division. |
| Performing the four fundamental logical operations: OR, AND, XOR, and NOT.                                  |

| **Out of scope**                                                                                |
|-------------------------------------------------------------------------------------------------|
| Shift operations are out of scope as they involve bitwise manipulation which is not covered     |                                                                                                |
| Malloc and memory management are beyond the scope, as they pertain to dynamic memory allocation |
| Complex data structure management is not included as it goes beyond the basic operations listed |

| Nice to have         |
|----------------------|
| Debugger             |
| PUSH, POP            |
| Increment, Decrement |
| LEAQ                 |


#### 2.4 <u>Deliverables</u>
| Deliverables              | Type                | Deadline         | Access to the document |
|---------------------------|---------------------|------------------|------------------------|
| Weekly Reports            | Document (Markdown) | Every Friday     | Link                   |
| Functional Specifications | Document (Markdown) | 30 January 2024  | Link                   |
| Technical Specifications  | Document (Markdown) | 9 February 2024  | Link                   |
| Architecture Diagram      | Document            | 9 February 2024  | Link                   |
| Test Plan                 | Document (Markdown) | 16 February 2024 | Link                   |
| Database of Bug           | Document (Markdown) | 16 February 2024 | Link                   |
| Unit Tests                | Program             | 22 February 2024 | Link                   |
| Final Product             | Program             | 23 February 2024 | Link                   |
### 3. <u>Project Organisation</u>

#### 3.1 <u>Project representation</u>

| **Project Owner** | **Represented by**                                 |
|----------------|----------------------------------------------------|
| JEANNIN Franck | Represented by himself                             |
| CUREL Clémentine | Represented by **DELILLE Elone** (Program Manager) |



#### 3.2 <u>Stakeholders</u>

| **Stakeholder**      | **Might have/find an interest in...**                                                    |
|----------------------|------------------------------------------------------------------------------------------|
| **JEANNIN Franck**   | Having students learning C, the operation of an interpreter and a virtual processor      |
| **ALGOSUP Students** | Learn C, understand how a code interpreter and a virtual processor work, gain experience |

#### 3.3 <u>Project roles</u>
| **Name**          | **Role**                              | **Description**                                                                                                                                                                         |
|-------------------|---------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Project Manager   | CUREL Clémentine                      | Assumes responsibility for project organization, planning, and budgeting. <br>Endeavors to maintain team motivation at a high level.                                                    |
| Program Manager   | DELILLE Elone                         | Ensures that the project aligns with expectations. <br>Takes charge of project design. <br>Holds responsibility for crafting the Functional Specifications.                             |
| Technical Leader  | PLANCHARD Thomas                      | Exercises authority in making technical decisions within the project.<br>Translates the Functional Specification into Technical Specifications.<br>Conducts comprehensive code reviews. |
| Software Engineer | LASSELIN Alexis <br>NAMIR Salaheddine | Engages in the development of code.<br>Creates and maintains documentation.<br>Actively participates in the technical design process.                                                   |
| Quality Assurance | BAVAROIS Séréna                       | Conducts thorough testing of all product functionalities to identify bugs and issues.<br>Carefully documents identified bugs and issues.<br>Formulates the test plan.<br>Verifies the resolution of issues and ensures their closure. |

#### 3.4 <u>Project reviewers</u>
The project owner has designated external project reviewers to meticulously examine our specifications and furnish us with constructive feedback.

### 4. Project Plan

#### 4.1 <u>Milestones</u>


#### 4.2 <u>Dependencies</u>

#### 4.3 <u>Resources/Financial Plan</u>

#### 4.4 <u>Assumptions/Constraints</u>
<!-- constraints : language c, only native lib,
assumptions : no technical issue with computers -->
## III. Functional Requirements
We need to create our own assembler. To do this, we'll base ourselves on most existing assembler code, with the simple exception that we'll use different names for certain actions. Our assembler will be 32-bit based, which is easily adaptable to today's computers.<br>
We won't be using the entire x86 architecture, as we don't need as much memory space for this project. Also, the 32-bit architecture is easily usable on any of today's computers, and is more suitable for this project.

### 1. Registers
#### 1.1 <u>General registers</u>
We use 4 general registers to store data. These are 32-bit general-purpose registers.<br>
`RA`, `RB`, `RC`, `RD`

#### 1.2 <u>Address registers</u>
Address registers, are essential components of a processor, each capable of storing the memory address of another general-purpose register. These address registers enable the processor to efficiently access different areas of memory using the addresses stored in these registers, thus facilitating data management and the execution of operations in a computing environment.<br>
`RAA`, `RAB`, `RAC`, `RAD`

### 2. Operands
#### 2.1 <u>Addition - ADD</u>
The "ADD" (Addition) instruction is used in programming languages to add two values, or to add a value to a specified destination. In our assembly code, the "ADD" operation instruction uses the syntax :<br>
> `ADD DESTINATION, SOURCE`<br>
`DESTINATION` represents the location where the result of the addition will be stored.<br>
`SOURCE` represents the value to be added to the final destination.

**Applications:**<br>
Let's assume that the `RA` general register has a value of 10. We therefore add the value 15 to this register. To carry out this operation, we can proceed as follows:<br>
`ADD RA, 15` | Here, we `ADD` to `RA`, the value `15`.<br>
`Result : RA = 25`

We can also add the value of one register to another, provided that both registers contain the same data types. We have `RC`, which contains the value 5 and `RD`, which contains the value 25. We want `RD` to add the value of `RC` to the value already assigned to it. We must therefore indicate `RD` as `DESTINATION` and `RC` as `SOURCE`. To carry out this operation, we can proceed as follows: <br>
`ADD RD, RC` | Here, we `ADD` to `RD`, the value of `RC`<br>
`Result : RD = 30`

**What not to do:**<br>
Let's imagine that our `RA` register contains the string "Hello, World!" and that our `RC` register contains the value 20. You can't do an `ADD`, as the program will try to understand that "Hello, World!" is a numerical value.<br>
You'll get a compilation error.

#### 2.2 <u>Subtraction - SUB</u>
The "SUB" (Subtraction) instruction is used in programming languages to subtract one value from another, or to subtract a value from a specified destination. In our assembly code, the "SUB" operation instruction uses the following syntax:<br>
> `SUB DESTINATION, SOURCE`<br>
`DESTINATION` represents the location where the result of the subtraction will be stored.<br>
`SOURCE` represents the value to be subtracted from the destination.

**Applications:**<br>
Let's assume that the general register `RA` contains a value of 20. We want to subtract the value 8 from this register. To perform this operation, we can proceed as follows:<br>
`SUB RA, 8` | Here, we use the `SUB` instruction to subtract `8` from `RA`.<br>
`Result : RA = 12`

We can also subtract the value of one register from another, provided that both registers contain the same data type. Imagine we have `RC`, which contains the value 10, and `RD`, which contains the value 4. We want `RD` to subtract the value of `RC` from the value already assigned to it. To perform this operation, we can proceed as follows:<br>
`SUB RD, RC` | Here, we use the `SUB` instruction to subtract the value of `RC` from `RD`.<br>
`Result : RD = 6`

**What not to do:**<br>
Imagine that our register `RA` contains the string "Hello, World!" and our register `RC` contains the value 5. You cannot use the "SUB" instruction in this case, as the program will attempt to interpret "Hello, World!" as a numerical value. <br>This will result in a compilation error.

#### 2.3 <u>Multiplication - MUL</u>
The "MUL" (Multiplication) instruction is used in programming languages to multiply two values together, or to multiply a value by another and store the result in a specified destination. In our assembly code, the "MUL" operation instruction uses the following syntax:<br>
> `MUL DESTINATION, SOURCE`<br>
`DESTINATION` represents the location where the result of the multiplication will be stored.<br>
`SOURCE` represents the value to be multiplied with the destination.

**Applications:**<br>
Let's assume that the `RA` general register contains a value of 10. We want to multiply this value by 5 and store the result in `RA`. To perform this operation, we can proceed as follows:<br>
`MUL RA, 5` | Here, we use the "MUL" instruction to multiply the value in `RA` by 5.<br>
`Result : RA = 50`

You can also multiply the value of one register by another, provided that both registers contain the same data types. Imagine we have `RC`, which contains the value 6, and `RD`, which contains the value 8. We want `RD` to multiply the value of `RC` and store the result in `RD`. To perform this operation, we can proceed as follows:<br>
`MUL RD, RC` | Here, we use the "MUL" instruction to multiply the value in `RC` by the value in `RD` and store the result in `RD`.<br>
`Result : RD = 48`

**What not to do:**<br>
Imagine that our `RA` register contains the string "Hello, World!" and our `RC` register contains the value 20. You cannot use the "MUL" instruction in this case, as the program will attempt to interpret "Hello, World!" as a numerical value.<br>
You'll get a compilation error.

#### 2.4 <u>Division - DIV</u>
The "DIV" (Division) instruction is used in programming languages to divide one value by another, or to divide a value by another and store the result in a specified destination. In our assembly code, the "DIV" operation instruction uses the following syntax:<br>
> `DIV DESTINATION, SOURCE`<br>
`DESTINATION` represents the location where the result of the division will be stored.<br>
`SOURCE` represents the value by which the destination will be divided.

**Applications:**<br>
Let's assume that the `RA` general register contains a value of 50. We want to divide this value by 5 and store the result in `RA`. To perform this operation, we can proceed as follows:<br>
`DIV RA, 5` | Here, we use the "DIV" instruction to divide the value in `RA` by 5.<br>
`Result : RA = 10`

You can also divide the value of one register by another, provided that both registers contain the same data types. Imagine we have `RC`, which contains the value 40, and `RD`, which contains the value 8. We want `RD` to divide the value of `RC` and store the result in `RD`. To perform this operation, we can proceed as follows:<br>
`DIV RD, RC` | Here, we use the "DIV" instruction to divide the value in `RC` by the value in `RD` and store the result in `RD`.<br>
`Result : RD = 5`

**What not to do:**<br>
Imagine that our `RA` register contains the string "Hello, World!" and our `RC` register contains the value 20. You cannot use the "DIV" instruction in this case, as the program will attempt to interpret "Hello, World!" as a numerical value.<br>
You'll get a compilation error.

Attempting to divide by zero (0) is not allowed. If you attempt to divide any value by zero, including a constant or the content of a register, it will result in an error or undefined behavior in most programming languages and assembly instructions. For example, `DIV RA, 0` where RA contains any value will result in an error or an exception, and the program may crash or behave unpredictably. It's important to ensure that the divisor (the value after the "DIV" instruction) is not zero to avoid such issues.

### 3. Functions

Functions in assembly language serve as blocks of code that can be called upon to perform specific tasks. They allow for modular and structured programming. Here's a general structure for defining functions in assembly:

```assembly
function:
    ; Some context and description of the function
    ; OPERANDS Setup: DESTINATION, SOURCE

    ; Function body (code that performs the task)
    
    ; Return value (if any)
    
end;
```

**Example of a Function:**

Let's say we want to create a function that adds two numbers and returns the result.

```assembly
add_numbers:
    ; Description: Adds two numbers and returns the result
    ; Input:      OPERANDS Setup: DESTINATION, SOURCE (values to be added)

    ; Code to add the two numbers
    ADD DESTINATION, SOURCE
    
    ; Return to the calling code
    RET
end;
```

In this example, `add_numbers` is the function name, and it takes one parameter (`SOURCE`) as input. It calculates the sum of this parameter and stores the result in `DESTINATION`.

### 4. Subroutines

Subroutines in assembly are similar to functions, but they are often used for smaller, reusable tasks within a larger program. They typically don't have their own return values but can modify existing variables or registers.<br>
> `CALL subroutineName;`

Here's a general structure for defining subroutines in assembly:

```assembly
function:
    ; Some context and description of the function
    ; OPERANDS Setup: DESTINATION, SOURCE

    CALL subroutineName;  ; Call the subroutine

    ; More code for the main function

end;

subroutineName:
    ; Some context and description of the subroutine
    ; OPERANDS Setup: DESTINATION, SOURCE (if needed)

    ; Subroutine body (code that performs a specific task)

    RET ; Return to the calling code
```

**Example of a Subroutine:**

Let's say we have a main function that calculates the square of a number and a separate subroutine that multiplies two numbers. Here's how it could be structured:

```assembly
calculate_square:
    ; Description: Calculates the square of a number
    ; Input:      OPERANDS Setup: DESTINATION, SOURCE (the number to be squared)

    ; Code to calculate the square using a subroutine
    CALL multiply_numbers ; Call the multiply_numbers subroutine
    MOV DESTINATION, ReturnValue ; Store the result in DESTINATION
    
    ; Return to the calling code
    RET

multiply_numbers:
    ; Description: Multiplies two numbers
    ; Input:      OPERANDS Setup: DESTINATION, SOURCE (values to be multiplied)

    ; Code to multiply the two numbers
    MUL DESTINATION, SOURCE
    
    ; Return to the calling code
    RET

main:
    ; Main function code

    ; Call the calculate_square function
    CALL calculate_square
    
    ; Continue with the main function code

end;
```

In this example, `calculate_square` is the main function, and it uses the `multiply_numbers` subroutine to calculate the square of a number. The `multiply_numbers` subroutine performs the multiplication and returns the result in `DESTINATION`. The main function then continues with its code after calling `calculate_square`.

## 5. Variables

In our assembly language, you can declare variables using different instructions specific to each variable type. The basic syntax for declaring variables is as follows:

```assembly
variableName defineVariableType value
```

Here's how to declare variables of different types:

### 5.1. DVI (Define Variable Integer)

The "DVI" instruction is used to declare integer variables. It follows this syntax:
```assembly
variableName dvi 1
```
- `variableName` is the variable name.
- `dvi` specifies the integer variable type.
- `1` is the initial value of the integer variable.

Example:
```assembly
; Declare an integer variable with an initial value of 1
myIntegerVariable dvi 1
```

### 5.2. DVC (Define Variable Char)

The "DVC" instruction is used to declare character variables. It follows this syntax:
```assembly
variableName2 dvc "World! Hello."
```
- `variableName2` is the variable name.
- `dvc` specifies the character variable type.
- `"World! Hello."` is the initial value of the character variable.

Example:
```assembly
; Declare a character variable with an initial value of "World! Hello."
myCharVariable dvc "World! Hello."
```

### 5.3. DVN (Define Variable Negative)

The "DVN" instruction is used to declare integer variables with negative values. It follows this syntax:
```assembly
variableName3 dvn -6
```
- `variableName3` is the variable name.
- `dvn` specifies the integer variable type with a negative value.
- `-6` is the initial value of the integer variable with a negative value.

Example:
```assembly
; Declare an integer variable with a negative initial value of -6
myNegativeVariable dvn -6
```

These instructions allow you to define variables of different types to store data in your assembly language program.

Example usage:
```assembly
; Variable declarations
myIntegerVariable dvi 1
myCharVariable dvc "World! Hello."
myNegativeVariable dvn -6

; Using the variables in the code
...
```

This allows you to define variables of different types to store data in your assembly language program.


### 6. Printing Values

In assembly language, printing values to the output or display is a common task. How you print a value depends on whether it's a string, a number, or a register. We use different methods for each:

- To print a **string**, you can use the `DISP "VALUE"` instruction, where `"VALUE"` represents the string you want to display.

- To print a **number**, you can use the `DISP VALUE` instruction, where `VALUE` is the numerical value you want to display.

- To print the **contents of a register**, you can use the `DISP REGISTERNAME` instruction, where `REGISTERNAME` is the name of the register you want to display.

**Examples:**

1. Printing a String:
   ```assembly
   DISP "Hello, World!"
   ```

   This code will display the string "Hello, World!" to the output.

2. Printing a Number:
   ```assembly
   DISP 42       ; Display the value 42
   ```

   This code will display the number 42 to the output.

3. Printing the Contents of a Register:
   ```assembly
   MOV RB, 100   ; Load a value into register RB
   DISP RB       ; Display the contents of register RB
   ```

   If the value in register RB is 100, this code will display the number 100 to the output.

### 7. Instructions

In this section, we will look at the instructions that we have decided to implement in our Assembly language. These instructions are used to manipulate registers.

#### 7.1 <u>Instruction MOV</u>
The "MOV" (Move) instruction is used to copy the value from one register to another. It's commonly used for data transfer between registers. The syntax for the "MOV" instruction is as follows:
> `MOV DESTINATION, SOURCE`<br>
> `DESTINATION` represents the location where the result of the division will be stored
> <br>`SOURCE` represents the value by which the destination will be divided

Certainly, let's explain each of the "MOV" instruction examples one by one:

#### 7.1.1 `MOV RA, RC`

The instruction `MOV RA, RC` is used to copy the value from register RC to register RA.

- `RA` is the destination register where the value will be copied.
- `RC` is the source register from which the value is taken.

Example:
```assembly
MOV RA, RC
```

In this example, the value currently stored in register RC is copied into register RA. This instruction performs a straightforward data transfer between registers.

#### 7.1.2 `MOV RD, #2`

The instruction `MOV RD, #2` is used to directly load the value `2` into register RD.

- `RD` is the destination register where the value will be placed.
- `#2` represents the immediate value `2` that is loaded directly into RD.

Example:
```assembly
MOV RD, #2
```

In this example, the value `2` is immediately loaded into register RD. This instruction does not involve copying from another register but directly assigns the value.

#### 7.1.3 `MOV RA, "WORLD ! Hello."`

The instruction `MOV RA, "WORLD ! Hello."` is used to load a string, in this case, `"WORLD ! Hello."`, into register RA.

- `RA` is the destination register where the string will be stored.
- `"WORLD ! Hello."` is the string value that will be placed in RA.

Example:
```assembly
MOV RA, "WORLD ! Hello."
```

In this example, the string `"WORLD ! Hello."` is stored in register RA. This instruction is used for initializing a register with a string value.

Certainly, I'll add the additional "MOV" instruction examples and the message regarding what not to do. Here's the updated section:

#### 7.1.4 `MOV myTextVariable, "My text"`

The instruction `MOV myTextVariable, "My text"` is used to load a string, in this case, `"My text"`, into the variable `myTextVariable`. 

- `myTextVariable` is the destination variable where the string will be stored.
- `"My text"` is the string value that will be placed in `myTextVariable`.

Example:
```assembly
MOV myTextVariable, "My text"
```

In this example, the string `"My text"` is stored in the variable `myTextVariable`. This is a common way to initialize a string variable.

#### 7.1.5 `MOV myIntegerVariable, 12`

The instruction `MOV myIntegerVariable, 12` is used to assign the integer value `12` to the variable `myIntegerVariable`.

- `myIntegerVariable` is the destination variable where the integer value will be stored.
- `12` is the immediate integer value that will be placed in `myIntegerVariable`.

Example:
```assembly
MOV myIntegerVariable, 12
```

In this example, the integer value `12` is assigned to the variable `myIntegerVariable`. This is a common way to initialize an integer variable.

#### 7.1.6 What Not to Do

It's important to follow proper syntax and conventions when using the "MOV" instruction. Avoid the following incorrect usage:

```assembly
MOV 2, "My text"
```

In this incorrect example, the instruction attempts to move a string into the value `2`, which is not a valid variable name or destination. It's crucial to specify a valid destination, such as a register or a named variable, when using the "MOV" instruction. Trying to move data into an invalid destination can result in compilation errors or unexpected behavior.

## IV. Non-Functional Requirements
<!-- run -->

## V. Glossary
[^1]: **Virtual Processor**: A virtual processor refers to a simulated or emulated computing unit designed to execute instructions and perform operations, typically in a software environment. It mimics the behavior of a physical processor, allowing for testing and development without the need for actual hardware.
[^2]: **Interpreter**: An interpreter is a software component that reads and executes source code or scripts in real-time, without the need for prior compilation. It translates and executes the code line by line, making it suitable for scripting languages and dynamic environments.
[^3]: **Assembly Code**: Assembly code, also known as assembly language, is a low-level programming language that represents instructions in a human-readable form, closely resembling the architecture of a computer's central processing unit (CPU). It is used for direct hardware manipulation and optimization.
[^4]: **C Language**: The C language is a high-level, general-purpose programming language renowned for its efficiency, portability, and expressive power. It serves as a versatile tool for software development and system programming.
[^5]: **Libraries**: Libraries are collections of pre-written code modules or functions that provide reusable and standardized functionality to simplify software development. They are commonly used to extend the capabilities of a programming language.
[^6]: **Dependencies**: Dependencies are external software components or libraries that a program relies on to function correctly. They must be present and correctly configured for the program to operate as intended.