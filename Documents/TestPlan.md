## Test Plan

## Table of Contents
- [Test Plan](#test-plan)
- [Table of Contents](#table-of-contents)
    - [I. Product Analysis](#i-product-analysis)
        - [1. Overview](#1-overview)
        - [2. Requirements](#2-requirements)
        - [3. Hardwares and softwares used](#3-hardwares-and-softwares-used)
    - [II. Strategy](#ii-strategy)
        - [1. Test Strategy](#1-test-strategy)
        - [2. In-Scope of testing](#2-in-scope-of-testing)
        - [3. Testing type](#3-testing-type)
            - [3.1 Unit test](#31-unit-test)
        - [4. Tests structure](#4-tests-structure)
        - [5. Test list](#5-test-list)
        - [6. Test cases](#6-test-cases)
        - [7. Monitoring and tools](#7-monitoring-and-tools)
            - [7.1 GitHub](#71-github)
            - [7.1.1 GitHub overview](#711-github-overview)
            - [7.1.2 GitHub Issues](#712-github-issues)
        - [8 Meeting reports](#8-meeting-reports)
    - [III. Test criteria](#iii-test-criteria)
        - [1. Suspension criteria](#1-suspension-criteria)
        - [2. Entry criteria](#2-entry-criteria)
        - [3. Exit criteria](#3-exit-criteria)
    - [IV. Allocated Ressources](#iv-allocated-ressources)
        - [1. People](#1-people)
        - [2. Testing environement requirements](#2-testing-environement-requirements)
    - [V. Test Deliverables](#v-test-deliverables)
        - [1. Task time estimation](#1-task-time-estimation)
    - [VI. Conclusion and acknowledgements](#vi-conclusion-and-acknowledgements)
    - [VII. Glossary](#vii-glossary)   
    - [VIII. Sources](#viii-sources)     

# I. Product Analysis
## 1. Overview

We were given the task by ALGOSUP, of designing at once a **virtual processor**[^1] and an **interpreter**[^2] that would be able to execute an **assembly code**[^3] that we have to code during the project. This project will be developed only in portable **C language**[^4] relying solely on **standard C libraries**[^5].

## 2. Requirements

For this project, we have some mandatory requirements:

1. Create a minimal assembly language containing the following instructions (this part is more fully developed in [the functional specification](./FunctionalSpecifications.md)):
    - Storing an immediate value in a register
    - Copying the contents of one register to another one
    - Reading memory data from the address contained by in a register and placing it in another register
    - Storing the value from a register into memory at the address contained by another register
    - Comparing the contents of registers
    - Performing an unconditional jump to a labeled instruction
    - Performing a conditional jump to a labeled instruction
    - Executing a subroutine call
    - Returning from a subroutine
    - Performing the four fundamental arithmetic operations: addition, subtraction, multiplication, and division
    - Performing the four fundamental logical operations: OR, AND, XOR, and NOT

2. Develop a C program that can read our assembly code from a text file, check for semantic correctness, detect syntactical errors, and then run it on the virtual processor.

3. Implement a virtual processor that can execute the assembly code.

4. In order to see that the assembly program is actually running, implement a virtual system call for 
displaying text in a virtual terminal, that can be accessed from the assembly code. 

5. Write a small assembly program conceptually similar to unit tests to prove that everything is working as expected.

## 3. Hardwares and softwares used

Since we are coding in **C programming language** for this project, we have chosen to use **GCC** as our compiler and **VSCode** as our IDE (Integrated Development Environment[^6]). So our **assembly language**, which we execute through our program, is written as a text file (.txt). Furthermore, since we are using different computers, our program needs to be adapted for Windows and MacOS systems.

**C programming language**:

The C programming language is a versatile, high-level computer language designed for developing software. It provides direct control over hardware, supports structured programming, allows portability to different platforms and is known for its efficiency, flexibility and use of pointers for more advanced memory operations.

**GCC**:

The GCC (GNU Compiler Collection) is an open source compiler developed by the GNU project. It compile the source code of several programming languages into machine code, making it easier to develop software on different platforms.

**VSCode**:

Visual Studio Code is a source-code editor made by Microsoft for Windows, Linux and macOS. The code source of Visual Studio Code is open source and published under the MIT license.

**Assembly language**:

Assembly, is a low-level language used to program a computer's processors directly. It lies between the machine code (binary) that the computer can understand and the high-level languages more human-readable.

# II. Strategy
## 1. Test Strategy

For our strategy we decided to work on iterative testing, which consists of testing all the things at the time they are pushed which allows rapid feedback and a better improvement of the tasks. To improve our strategy and our productivity we have [monitoring and tools](#6-monitoring-and-tools) to identify potentials bugs and ensure issues resolutions.

## 2. In-Scope of testing

Mainly, we need to test the documents and our program.

As far as our program is concerned, we need to test that there are no significants bugs, and that all the features presented in the functional specification operate as intended. Also as we work on different platforms (Windows and macOS) we have to check if all the features work correctly.

For our document it is important to ensure their quality of its content, provide a clear communication with our client, make sure all of them could understand all the documentation. We will also check grammatical and typography errors.

## 3. Testing type
### 3.1 Unit test

Unit testing is a method of testing individuals components of our program. It is typically done by *software engineers* and used to ensure that the individual units of the program are working as intended.

Advantages of unit testing:
- Identify bugs early and ensure that changes to the code do not introduce new bugs    
- Make the code more modular and easier to understand 
- Improve the quality and reliability of the software

## 4. Tests structure

Each test contains the following components:

- **The function**: Identify the function of the test
- **The expected result**: Identify the expected result, what we want to have as a result
- **The severity**: categorises the test in order of priority (none, low, medium, high and critical)

## 5. Test list

| Function | Expected result | Severity |
|--|--|--|
|Run the Assembly Program|The program should read the file without errors and prepare for further processing|High|
|Ensure the program performs semantic analysis[^7]|The program should detect and report any semantic errors|High|
|The virtual system call for displaying text in a virtual terminal|The assembly program should be able to use the virtual system call to display text in the virtual terminal|High|
|Perform arithmetic operation|The assembly program should correctly perform arithmetic operations *(Addition, Substration, Multiplication, Division)*|High|
|Perform logical operation|The assembly program should correctly execute logical operations *(OR, AND, XOR and NOT)*|High|
|Perform the unconditional and conditional jump instructions in the assembly language|The program should correctly performs unconditional and conditional jumps based on specified conditions *(JMP, JE, JNE, JG, JGE, JL, JLE)*|High|
|Verify if the assembly program can successfully call and return from subroutines|The program should execute subroutines, and the return should happen without errors|High|
Perform the basic assembly instructions *(like MOV, CMP, and basic memory operations)*|The program should correctly execute these instructions, and the results should match the expected outcomes|High|
|Check how the C program handles syntactical errors in the assembly code|The program should provide clear error messages indicating the nature and location of syntactical errors|Medium|
|Check how the C program handles semantic errors in the assembly code|The program should provide informative error messages for semantic issues, and it should prevent the execution of semantically incorrect programs|High|
|Evaluate the performance of the C program by running a large assembly program|The program should execute efficiently without significant delays or memory issues|Low|

## 6. Test cases

A test case is a defined format for software testing, required to check if any particular feature of our program if working or not. A test case consist of a set of instructions that need to be check to test our program.

For each test cases we use this pattern:

- **Date**: Date of the test case
- **Title**: Title the function or the feature of the test case tested
- **Test case description**: Add a clear and concise description of the test case
- **Step of test**: Mentione all the steps in detail and write in order in wich it requires to be executed
- **Expected result**: Explain what kind of result did you expect
- **Priority**: Test case priority (None, Low, Medium, High)
- **Status**: Test case status (Passed, Failed, In progress or Not implement)

To make QA's job easier, and to monitor the progress of our test cases, we use a [Test Case file](/Documents/TestCases.md). That facilate the job of the Quality Assurance and enable us to be aware of features that not working or have not been implement.

## 7. Monitoring and tools
### 7.1 GitHub
#### 7.1.1 GitHub overview

GitHub is a cloud-based collaborative development platform that allows users to host, share and collaborate on software projects, providing version control and collaboration features. 

We will also be using GitHub Issues to report bugs and errors to be fixed.

#### 7.1.2 GitHub issues

GitHub Issues is a sort of bug tracker in every repository.

It can be used for discussions which include a variety of things like reporting a bug on that repository, asking questions or even asking for a particular feature. It is a great place to keep a track of tasks and enhancements of the project.

**GitHub issue managing:**

1. Detailed Issues Description:
    - We add detailed and explicit description of our issues to provide context and understanding
    - Precise in which version of our sofware are you running
    - We include steps to reproduce bugs 
    - We specify your expect and actual result 

2. Labelisation:
    - We categorise each issues with labelisation
    - We define the level of severity with labels (None, Low, Medium, High)

3. Assignees:
    - We assign each issues to the appropriate team members

4. Use of template:
    - For each issues we use a template to report bugs and issues
    - This template include description of the issues, precisions about the enviromnent, the steps of the bugs, the actual and expected result and somes potentials solutions...

![BugReport](/Documents/Appendices/Screenshot%202024-01-26%20163148.png)

## 8. Meeting reports

We have decided to work in collaboration with the other project teams, which means that we meet regularly and report back.

# III. Test criteria

Establishing test criteria is crucial to guaranteed the quality of our program before it is released. This represents some standards to which our programme must conform before being sent to customers.

## 1. Suspension criteria

The aim of suspension criteria is to avoid wasting time. This means that when we can not longer continue our test session because of a defect, we must take the decision to suspend this criteria, in order to start again more efficiently. 

For this project we have two main suspension criteria:

- **Critical bugs** 

If, for some reasons, we encounter a critical bug that prevents our program from working properly, we must suspend testing and the implementation of new features in order to resolve the bug. 

- **Enviromnent issues**

When we encounter problems due to the hadwares and softwares used, we have to interrupt our tests until the problem is solved.

## 2. Entry criteria

Entry criteria is a set of conditions that must be met before start a testing session in order to create a favorable test environment. These criteria ensure the accurancy of testing process.

Our entry criteria for this project are:
- To have a testable code available
- Unit test ready 
- Test cases developped and ready
- The hardware and software enviremnent set up

## 3. Exit criteria

Exit criteria, as the name suggests, it is a set of conditions that defined when the testing process it is fulfilled. These criteria ensure that the program respond of all the requirements and has no bugs.

Our exit criteria for this project are:
- **Test cases coverage**:
    - Our test cases must be covered at minimum 80% for all our features and requierements to make sure all the conditions is fulfilled

- **No significant bugs**:
    - To have a valid program, it is important to fix all the bugs, or at least 90% of them and do not have any critical bugs 

- **Documents**:
    - All of our documents should be understandable, concise and precise. It means, understandable for all teams members

# IV. Allocated Ressources
## 1. People

For this project we have only one quality assurance on this team but we also work with the another Quality Assurances of the another teams:

- GUILLOUCHE Enzo - Quality Assurance of team 2 -
- LEMOINE Arthur - Quality Assurance of team 3 -
- THIZEAU Maxime - Quality Assurance of team 4 -
- AMIRI Atifa - Quality Assurance of team 5 -

## 2. Testing environement requirements

- Operating System: Windows and macOS
- Programming language: C17
- Compiler: GCC
- Integrated Development Environment: VisualStudioCode
- Authorised Librairies: only standards C libraries

# V. Test Deliverables
## 1. Task time estimation

| Task | Start Date | End Date | 
| ---- | ---------- | -------- |
|GitHub Issues |January 22, 2024|January 22, 2024|
|Unit Tests|Febuary 22, 2024|Febuary 23, 2024|
|Review the Documentation|January 22, 2024|Febuary 22, 2024|
|First QA Meeting|January 29, 2024|January 29, 2024|
|Test Plan Deadline|January 23, 2024|Febuary 14,2024|
|Test Cases|January 29, 2024|Febuary 15,2024|

# VI. Conclusion and acknowledgements

Delivering software that does not work or is buggy can damage our professional image and spoil the user experience. That is why the testing phase is so important. We have a duty to deliver a programme that meets as many different requirements as possible. The testing phase will guarantee the quality of our programme and ensure that it works as it should.

Within our team we would like to thank the software engineering team for their work.
We would also like to thank our Programme Manager and Technical Lead for all the information they shared with us on which the test plan is based.
Finally, we'd like to thank our project manager for leading the team towards our common goal.
And of course we would like to thank the QAs from the other teams we worked with. 

# VII. Glossary

[^1]: **Virtual Processor**: A virtual processor refers to a simulated or emulated computing unit designed to execute instructions and perform operations, typically in a software environment. It mimics the behavior of a physical processor, allowing for testing and development without the need for actual hardware.

[^2]: **Interpreter**: An interpreter is a software component that reads and executes source code or scripts in real-time, without the need for prior compilation. It translates and executes the code line by line, making it suitable for scripting languages and dynamic environments.

[^3]: **Assembly Code**: Assembly code, also known as assembly language, is a low-level programming language that represents instructions in a human-readable form, closely resembling the architecture of a computer's central processing unit (CPU). It is used for direct hardware manipulation and optimization.

[^4]: **C Language**: The C language is a high-level, general-purpose programming language renowned for its efficiency, portability, and expressive power. It serves as a versatile tool for software development and system programming.

[^5]: **Libraries**: Libraries are collections of pre-written code modules or functions that provide reusable and standardized functionality to simplify software development. They are commonly used to extend the capabilities of a programming language.

[^6]: **Integrated Development Environment (IDE)**: An IDE is a software application that provides a comprehensive set of tools for software development. It includes a code editor, compiler, debugger, and other features that make it easy to write, test, and debug code.

[^7]: **Semantic analysis**: Semantic analysis, in simple terms, is the process of understanding the deeper meaning of a computer program. It goes beyond just checking how words are arranged (syntax) to ensure that the program makes logical sense. 

# VIII. Sources

- [The Functional specification](/Documents/FunctionalSpecifications.md)
- [The Technical specification](/Documents/TechnicalSpecifications.md)
- [Guru99](https://www.guru99.com/download-sample-test-case-template-with-explanation-of-important-fields.html)