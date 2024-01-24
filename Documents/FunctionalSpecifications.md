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
      - [2.2 Scope](#22-uscopeu)
      - [2.3 Deliverables](#23-udeliverablesu)
      - [2.4 Personas](#24-upersonasu)
      - [2.5 Test Cases](#25-utest-casesu)
    - [3. Project Organisation](#3-uproject-organisationu)
      - [3.1 Project representation](#31-uproject-representationu)
      - [3.2 Stakeholders](#32-ustakeholdersu)
      - [3.3 Project roles](#33-uproject-rolesu)
      - [3.4 Project reviewers](#34-uproject-reviewersu)
    - [4. Project Plan](#4-project-plan)
      - [4.1 Resources/Financial plan](#43-uresourcesfinancial-planu)
      - [4.2 Assumptions/Constraints](#44-uassumptionsconstraintsu)
  - [III. Functional Requirements](#iii-functional-requirements)
    - [1. Registers](#1-registers)
      - [1.1 General registers](#11-ugeneral-registersu)
      - [1.2 Address registers](#12-uaddress-registersu)
    - [2. Operands](#2-operands)
      - [2.1 Addition - ADD](#21-uaddition---addu)
      - [2.2 Subtraction - SUB](#22-usubtraction---subu)
      - [2.3 Multiplication - MUL](#23-umultiplication---mulu)
      - [2.4 Division - DIV](#24-udivision---divu)
    - [3. Functions](#3-functions)
      - [3.1 END; (End of Function)](#31-uend-end-of-functionu)
    - [4. Subroutines](#4-subroutines)
      - [4.1 RET (Return)](#41-uret-returnu)
    - [5. Variables](#5-variables)
      - [5.1. DVI (Define Variable Integer)](#51-udvi-define-variable-integeru)
      - [5.2. DVC (Define Variable Char)](#52-udvc-define-variable-charu)
      - [5.3. DVN (Define Variable Negative)](#53-udvn-define-variable-negativeu)
    - [6. Printing Values](#6-printing-values)
    - [7. Instructions](#7-instructions)
      - [7.1 Instruction MOV](#71-uinstruction-movu)
    - [8. Comparing Values](#8-comparing-values)
    - [9. Jump](#9-jump)
      - [9.1 Unconditional Jump](#91-uunconditional-jumpu)
      - [9.2 Conditional Jump](#92-uconditional-jumpu)
    - [10. Bitwise Operations](#10-bitwise-operations)
      - [10.1 AND (Logical AND)](#101-uand-logical-andu)
      - [10.2 XOR (Exclusive OR)](#102-uxor-exclusive-oru)
      - [10.3 NOT (Logical NOT)](#103-unot-logical-notu)
      - [10.4 OR (Logical OR)](#104-uor-logical-oru)
    - [11. Get Address (GAD)](#11-get-address-gad)
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

#### 2.2 <u>Scope</u>

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


#### 2.3 <u>Deliverables</u>
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

#### 2.4 <u>Personas</u>

![img.png](img.png)
![img_1.png](img_1.png)
![img_2.png](img_2.png)

#### 2.5 <u>Test Cases</u>

#### 2.5.1. Test Case: Register Storing and Copying
**Objective:** Verify that immediate values can be stored in registers and contents can be copied from one register to another.

**Test Steps:**
1. Store an immediate value in register `RA`.
2. Copy the contents of `RA` to register `RB`.
3. Check if the value in `RB` matches the original value stored in `RA`.

**Expected Result:** The value in `RB` should be identical to the value initially stored in `RA`.
<br><br>
#### 2.5.2 Test Case: Arithmetic Operations (ADD, SUB, MUL, DIV)
**Objective:** Ensure that the processor correctly performs basic arithmetic operations.

**Test Steps for ADD:**
1. Store values in registers `RA` and `RB`.
2. Perform `ADD RA, RB`.
3. Verify the result in `RA`.

**Expected Result for ADD:** The value in `RA` should be the sum of the original values in `RA` and `RB`.

**Repeat similar steps for SUB, MUL, and DIV operations with appropriate expected results.**
<br><br>
#### 2.5.3 Test Case: Jump Instructions (Unconditional and Conditional)
**Objective:** Test the unconditional and conditional jump instructions.

**Unconditional Jump Test:**
1. Implement a simple loop using `JMP` instruction.
2. Verify that the loop executes as expected.

**Conditional Jump Test:**
1. Use `CMP` instruction to compare two values.
2. Based on comparison, use `JE` or `JNE` to direct program flow.
3. Verify that the program follows the correct path.
   <br><br>
#### 2.5.4 Test Case: Bitwise Operations (AND, OR, XOR, NOT)
**Objective:** Validate the correct functionality of bitwise operations.

**Test Steps for AND:**
1. Load binary values into two registers.
2. Perform `AND` operation.
3. Verify the result.

**Repeat similar steps for OR, XOR, and NOT operations with appropriate binary values and expected results.**
<br><br>
#### 2.5.5 Test Case: Function and Subroutine Execution
**Objective:** Ensure that functions and subroutines are called and executed correctly.

**Test Steps for Function:**
1. Define a function that performs a specific operation (e.g., adding two numbers).
2. Call the function from the main program.
3. Verify the result of the function.

**Test Steps for Subroutine:**
1. Define a subroutine that performs a task (e.g., modifying a register value).
2. Call the subroutine from within a function.
3. Verify that the subroutine has performed its task correctly.
<br><br>
#### 2.5.6 Test Case: Variable Handling (DVI, DVC, DVN)
**Objective:** Test the declaration and usage of different variable types.

**Test Steps:**
1. Declare variables using `DVI`, `DVC`, and `DVN`.
2. Assign and modify values in these variables.
3. Verify that the variables hold the correct data.
<br><br>
#### 2.5.7 Test Case: Printing Values
**Objective:** Check that the processor can correctly display strings, numbers, and register contents.

**Test Steps:**
1. Use `DISP` instruction to print a string, a number, and the contents of a register.
2. Verify that the correct values are printed.

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

#### 4.1 <u>Resources/Financial Plan</u>

In our custom assembly language project, we emphasize a cost-effective approach with no financial dependencies required for its development. Our focus is on optimizing resource utilization and ensuring efficient progress.

**Resource Allocation:**

- **Project Duration:** The project is scheduled to span over a total of X weeks.

- **Personnel:** Our dedicated team consists of X skilled individuals who will actively contribute to different aspects of the project, including development, testing, and documentation.

**Work Hours:**

To maintain a balanced workload and ensure steady progress, we have allocated a total of X hours per week, distributed among team members as needed. This allocation is designed to optimize productivity while allowing for flexibility in addressing project challenges.

**Financial Independence**

We take pride in stating that our custom assembly language project requires no external financial investment, which means our total budget is 0€. We have efficiently organized our resources to ensure that all development activities can be carried out within the scope of our existing capabilities and infrastructure.

By following this resource allocation plan and maintaining our financial independence, our goal is to successfully develop and deliver our custom assembly language, while adhering to the project's objectives and timelines.

#### 4.2 <u>Assumptions/Constraints</u>

When working with assembly language programming, it's important to consider certain assumptions and constraints to ensure the smooth execution of your code:

**Assumptions:**
1. **No Technical Issues:** We assume that the target computer system does not encounter any significant technical issues during the execution of the assembly code. This includes factors such as hardware failures, memory corruption, or system instability.

2. **Compatible Hardware:** The assembly code is assumed to be executed on hardware that is compatible with the assembly language instructions used. Compatibility issues can lead to unexpected behavior or errors.

3. **Proper Assembler:** It is assumed that a proper assembler or assembly language development environment is used to translate the assembly code into machine code. The assembler should correctly interpret the assembly language syntax and generate executable code.

**Constraints:**
1. **Native Libraries:** The assembly code is constrained to utilize only native libraries and resources available on the target system. It should not rely on external libraries or resources that may not be present on the system.

2. **Low-Level Language:** Assembly language is inherently a low-level language, and as such, it may not offer the same level of abstraction and convenience as high-level programming languages. Developers should be prepared to work with raw memory, registers, and hardware interfaces.

3. **Minimal Abstraction:** Assembly language programming typically involves minimal abstraction, meaning that developers have to handle many low-level details themselves. This can make code more complex and require a deep understanding of the hardware architecture.

4. **Portability:** Assembly code is often not portable across different computer architectures. Code written for one architecture may not work on another without significant modifications.

5. **Manual Memory Management:** Assembly language programming often requires manual memory management, including allocation and deallocation of memory, which can be error-prone if not handled carefully.

6. **Limited High-Level Features:** Assembly language lacks many high-level features and abstractions found in modern programming languages, such as built-in data structures or complex control flow constructs.

7. **Limited Debugging Tools:** Debugging assembly code can be challenging, as it may have limited access to high-level debugging tools commonly available in higher-level languages.

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

#### 3.1 <u>END; (End of Function)</u>
The `END;` instruction is used to mark the end of a function. It signifies the conclusion of the function's code block and allows the program to continue with the main program or other functions. When the assembler encounters `END;` within a function, it understands that the function's code block has concluded, and control returns to the point in the main program where the function was originally called from.

Using `END;` is crucial in assembly language to properly terminate functions and ensure that control flow proceeds correctly within the program.

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

#### 4.1 <u>RET (Return)</u>
The "RET" (Return) instruction is used at the end of a subroutine to return control to the calling code. When a subroutine finishes its task, it uses "RET" to go back to the point in the main program where it was originally called from. This allows the main program to continue executing after the subroutine's task is completed.

Using "RET" is essential in assembly language to maintain program flow and ensure that control is transferred back to the appropriate location in the calling code.

## 5. Variables

In our assembly language, you can declare variables using different instructions specific to each variable type. The basic syntax for declaring variables is as follows:

```assembly
variableName defineVariableType value
```

Here's how to declare variables of different types:

### 5.1. <u>DVI (Define Variable Integer)</u>

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

### 5.2. <u>DVC (Define Variable Char)</u>

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

### 5.3. <u>DVN (Define Variable Negative)</u>

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

### 8. Comparing Values
The "CMP" (Compare) instruction is used to compare two values. It's essential for making decisions in your program based on the result of the comparison. The "CMP" instruction doesn't alter the values in the operands.

Here are the different forms of the "CMP" instruction:

- `CMP Registre, Variable` : This form compares the contents of a register with the value stored in a memory variable.

- `CMP Variable, Variable `: In this case, two memory variables are compared.

- `CMP Registre, Registre` : You can compare the contents of two registers using this form.

- `CMP DirectValue, DirectValue` : It's also possible to compare two immediate values directly.

**Example Usage:**

1. Comparing a Register with a Memory Variable:
   ```assembly
   MOV RA, 42       ; Load value 42 into register RA
   CMP RA, variable1   ; Compare the value in RA with the content of memory variable variable1
   ```
   The CMP is therefore stored in RAM until it is used. You can therefore perform a conditional jump at any time in the program, which will use this value (if no other CMP has been performed in the meantime in the program).

2. Comparing Two Memory Variables:
   ```assembly
   CMP variable2, variable3   ; Compare the contents of memory variables variable2 and variable2
   ```
   The "CMP" instruction compares the values in variable1 and variable2.

3. Comparing Two Registers:
   ```assembly
   MOV RA, 10       ; Load value 10 into register RA
   MOV RB, 20       ; Load value 20 into register RB
   CMP RA, RB       ; Compare the values in registers RA and RB
   ```

4. Comparing Immediate Values:
   ```assembly
   CMP 5, 10         ; Compare the immediate values 5 and 10
   ```
   The "CMP" instruction can directly compare two constants.

Example usage:
```assembly
myAge dvi 18           ; Declare a variable named myAge with an initial value of 18
myNewAge dvi 16        ; Declare a variable named myNewAge with an initial value of 16
myName dvc "Jean-Charles" ; Declare a variable named myName with a string value "Jean-Charles"
myFamilyName dvc "DUPONT" ; Declare a variable named myFamilyName with a string value "DUPONT"
actualYear dvi 2023     ; Declare a variable named actualYear with an initial value of 2023

randomFunction:
    ADD myNewAge, 2     ; Add 2 to the value of myNewAge
    CMP myAge, actualYear ; Compare the value of myAge with actualYear
    ; Here you can perform a conditional jump
    RET                 ; Return from the function (subroutine)

main:
    CALL randomFunction ; Call the randomFunction subroutine
    ; Here you can perform a conditional jump
end;    
```

### 9. Jump

#### 9.1 <u>Unconditional Jump</u>

**Syntax:**
```
JMP destination
```

The "Jump Unconditional" instruction, represented by `JMP`, transfers control to a different part of the program without any conditions.

**Example:**
```assembly
JMP LoopStart
```

In this example, the program unconditionally jumps to the label `LoopStart`, typically used for implementing loops in assembly.

#### 9.2 <u>Conditional Jump</u>

Conditional jumps in assembly allow you to change program flow based on the results of previous comparisons or conditions.

**Syntax:**
```
JXX destination
```

Here, `XX` represents a condition code that specifies the condition under which the jump will be taken.

#### 9.2.1 Jump Equal (JE)

**Syntax:**
```
JE destination
```

The "Jump Equal" (`JE`) instruction jumps to the specified destination if two values are equal.

**Example:**
```assembly
MOV RA, 5     ; Set RA to 5
CMP RA, 5     ; Compare the value in RA with 5
JE EqualLabel ; Jump to EqualLabel if RA equals 5
```

#### 9.2.2 Jump Not Equal (JNE)

**Syntax:**
```
JNE destination
```

The "Jump Not Equal" (`JNE`) instruction jumps to the specified destination if two values are not equal.

**Example:**
```assembly
MOV RB, 10    ; Set RB to 10
CMP RB, 5     ; Compare the value in RB with 5
JNE NotEqual  ; Jump to NotEqual if RB is not equal to 5
```

#### 9.2.3 Jump Greater (JG)

**Syntax:**
```
JG destination
```

The "Jump Greater" (`JG`) instruction jumps to the specified destination if one value is greater than another.

**Example:**
```assembly
MOV RC, 15    ; Set RC to 15
CMP RC, 10    ; Compare the value in RC with 10
JG Greater    ; Jump to Greater if RC is greater than 10
```

#### 9.2.4 Jump Greater or Equal (JGE)

**Syntax:**
```
JGE destination
```

The "Jump Greater or Equal" (`JGE`) instruction jumps to the specified destination if one value is greater than or equal to another.

**Example:**
```assembly
MOV RD, 20    ; Set RD to 20
CMP RD, 20    ; Compare the value in RD with 20
JGE GreaterOrEqual ; Jump to GreaterOrEqual if RD is greater than or equal to 20
```

#### 9.2.5 Jump Less (JL)

**Syntax:**
```
JL destination
```

The "Jump Less" (`JL`) instruction jumps to the specified destination if one value is less than another.

**Example:**
```assembly
MOV RA, 25    ; Set RA to 25
CMP RA, 30    ; Compare the value in RA with 30
JL Less       ; Jump to Less if RA is less than 30
```

#### 9.2.6 Jump Less or Equal (JLE)

**Syntax:**
```
JLE destination
```

The "Jump Less or Equal" (`JLE`) instruction jumps to the specified destination if one value is less than or equal to another.

**Example:**
```assembly
MOV RB, 5     ; Set RB to 5
CMP RB, 5     ; Compare the value in RB with 5
JLE LessOrEqual ; Jump to LessOrEqual if RB is less than or equal to 5
```

Conditional jumps are used to control program flow based on comparisons and conditions, allowing you to create branching logic in assembly programs.

### 10. Bitwise Operations

Bitwise operations in assembly manipulate individual bits of binary values.

#### 10.1 <u>AND (Logical AND)</u>

**Syntax:**
```
AND destination, source
```

The `AND` instruction performs a bitwise AND operation between the bits of the destination and source operands, setting the bits in the destination to 1 only if both corresponding bits in the source and destination are 1.

**Example:**
```assembly
MOV RA, 5     ; Set RA to binary 0101
MOV RB, 3     ; Set RB to binary 0011
AND RA, RB    ; Perform AND operation: RA = 0101 AND 0011 = 0001 (1 in decimal)
```

#### 10.2 <u>XOR (Exclusive OR)</u>

**Syntax:**
```
XOR destination, source
```

The `XOR` instruction performs a bitwise XOR operation between the bits of the destination and source operands, setting the bits in the destination to 1 if they differ in value between the source and destination.

**Example:**
```assembly
MOV RA, 6     ; Set RA to binary 0110
MOV RB, 3     ; Set RB to binary 0011
XOR RA, RB    ; Perform XOR operation: RA = 0110 XOR 0011 = 0101 (5 in decimal)
```

#### 10.3 <u>NOT (Logical NOT)</u>

**Syntax:**
```
NOT destination
```

The `NOT` instruction performs a bitwise NOT operation on the destination operand, inverting all of its bits (changing 0s to 1s and vice versa).

**Example:**
```assembly
MOV RA, 5     ; Set RA to binary 0101
NOT RA        ; Perform NOT operation: RA = NOT 0101 = 1010 (10 in decimal)
```

#### 10.4 <u>OR (Logical OR)</u>

**Syntax:**
```
OR destination, source
```

The `OR` instruction performs a bitwise OR operation between the bits of the destination and source operands, setting the bits in the destination to 1 if either the source or destination bit is 1.

**Example:**
```assembly
MOV RA, 6     ; Set RA to binary 0110
MOV RB, 3     ; Set RB to binary 0011
OR RA, RB     ; Perform OR operation: RA = 0110 OR 0011 = 0111 (7 in decimal)
```

Bitwise operations are commonly used for various tasks in assembly language, such as manipulating individual flags or data masks. These instructions allow you to work with the binary representation of data at the bit level.

Certainly! Here's an explanation, syntax, and example for the "GAD" (Get Address) instruction:

### 11. Get Address (GAD)

The "GAD" instruction, which stands for "Get Address," is used to obtain the memory address of a specific register and store it in one of the destination registers, which can be RAA, RAB, RAC, or RAD.

**Syntax:**
```
GAD DESTINATION, SOURCE
```

- `DESTINATION` represents one of the destination registers (RAA, RAB, RAC, or RAD).
- `SOURCE` represents the source register (e.g., RAD, RA, RB, RC, etc.) whose memory address you want to obtain.

**Example:**
```assembly
MOV RA, 10    ; Set RA to the value 10
GAD RAA, RA   ; Get the memory address of RA and store it in RAA
```

In this example, the `GAD RAA, RA` instruction retrieves the memory address of register `RA` and stores it in register `RAA`. Now, `RAA` contains the memory address of `RA`, allowing you to perform operations that involve the address of RA, such as indirect addressing or memory manipulation.

## IV. Non-Functional Requirements
> **Portability**<br>
   Objective: The software should be easily portable across different operating systems without significant modifications.

Details:<br>
**Platform Independence**: The code should rely on standard C libraries, avoiding system-specific dependencies.
<br>**Cross-Platform Compatibility**: Testing on different OS (Windows, Linux, macOS) to ensure compatibility.
<br><br>
> **<u>Reliability and Robustness</u>**<br>
   Objective: The system should handle errors gracefully and perform reliably under various conditions.

Details:<br>
**Error Handling**: Efficient handling of exceptional cases and errors in instruction execution.
<br>**System Stability**: Ensuring the system remains stable and performs reliably over extended periods.
> **Maintainability and Extensibility**<br>
   Objective: The design should facilitate easy maintenance and future enhancements.

Details:<br>
**Modular Design**: Code should be organized into modules for ease of understanding and modification.
<br>**Documentation**: Comprehensive documentation of the codebase and architecture for easier maintenance and updates.

> **Performance and Efficiency**<br>
Objective: The interpreter and virtual processor should be optimized for maximum efficiency without compromising performance.

Details:<br>
**Resource Usage**: The system should be optimized for low resource consumption (CPU, memory).
<br>**Optimized Code**: The interpreter should be written in a way that minimizes processing time and memory usage.
<br>**Scalability**: The system should maintain performance levels under varying loads.

## V. Glossary
[^1]: **Virtual Processor**: A virtual processor refers to a simulated or emulated computing unit designed to execute instructions and perform operations, typically in a software environment. It mimics the behavior of a physical processor, allowing for testing and development without the need for actual hardware.
[^2]: **Interpreter**: An interpreter is a software component that reads and executes source code or scripts in real-time, without the need for prior compilation. It translates and executes the code line by line, making it suitable for scripting languages and dynamic environments.
[^3]: **Assembly Code**: Assembly code, also known as assembly language, is a low-level programming language that represents instructions in a human-readable form, closely resembling the architecture of a computer's central processing unit (CPU). It is used for direct hardware manipulation and optimization.
[^4]: **C Language**: The C language is a high-level, general-purpose programming language renowned for its efficiency, portability, and expressive power. It serves as a versatile tool for software development and system programming.
[^5]: **Libraries**: Libraries are collections of pre-written code modules or functions that provide reusable and standardized functionality to simplify software development. They are commonly used to extend the capabilities of a programming language.
[^6]: **Dependencies**: Dependencies are external software components or libraries that a program relies on to function correctly. They must be present and correctly configured for the program to operate as intended.