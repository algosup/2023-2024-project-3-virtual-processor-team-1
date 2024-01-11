# Project Charter - Virtual Processor [Team 1]

| **Document Name**  | Project Charter           |
|--------------------|---------------------------|
| **Document Owner** | DELILLE Elone             |

## Table of content
- [Project Charter - Virtual Processor](#project-charter---virtual-processor-team-1)
  - [Table of content](#table-of-content)
  - [Project Overview](#project-overview)
  - [Project Scope](#project-scope)
  - [Team Members](#team-members)
  - [RACI](#raci)
  - [Stakeholders](#stakeholders)
  - [Milestones](#milestones)
  - [Deliverables](#deliverables)
  - [Budget](#budget)
- [Glossary](#glossary)

## Project Overview
The aim of the project is to design both a **virtual processor**[^1] and an **interpreter**[^2] capable of executing **assembly code**[^3], coded by us during the project. It will be developed in pure, portable **C language**[^4], relying solely on [standard C](https://en.wikipedia.org/wiki/C_standard_library) **libraries**[^5], to the exclusion of any external **dependencies**[^6].

## Project Scope
The project begins on Monday, January 8, 2024, and ends on Friday, February 23, 2024. We must recreate in C language, a virtual processor as well as a code interpreter in which we will have to run Assembler code with the rules imposed by the client.
We will use the following tools to complete this task:
- Visual Studio Code **IDE**[^7] (Integrated Development Environment)
- The GCC **compiler**[^8] (GNU Compiler Collection)
- C programming language

<br>
The Assembler code that we need to write should be as follows:

1. Storing an immediate value into a **register**[^9].
1. Copying the value of a register into another register.
1. Reading the value of the **memory at the address**[^10] contained by a register and storing it into another register.
1. Storing the value of a register into memory at the address contained by another register.
1. Comparing the contents of registers.
1. **Jumping unconditionally**[^11] to a **label**[^12].
1. **Jumping conditionally**[^13] to a label.
1. Calling a **subroutine**[^14].
1. Returning from a subroutine

## Team Members

When the word "We" is used, it refers to all the members of Team 1. This team is made up of the following members:
| **Photo** | **Name** | **Role** | **GitHub and LinkedIn** |
|---|---|---|---|
| <img src="https://ca.slack-edge.com/T06BWRNMW3X-U06C7TXB9PE-g35ba02d7e83-64"> | CUREL Clémentine | Project Manager | [GitHub](https://github.com/Clementine951) \| [LinkedIn](https://www.linkedin.com/in/clementine-curel/) |
| <img src="https://ca.slack-edge.com/T06BWRNMW3X-U06CNHASLBS-gd0f64565afd-64"> | DELILLE Elone | Program Manager | [GitHub](https://github.com/HiNett) \| [LinkedIn](https://www.linkedin.com/in/elonedelille/) |
| <img src="https://ca.slack-edge.com/T019N8PRR7W-U02EY24GTT8-ge73464278d5-64"> | PLANCHARD Thomas | Technical Leader | [GitHub](https://github.com/thomas-planchard) \| [LinkedIn](https://www.linkedin.com/in/thomas-planchard-461782221/) |
| <img src="https://ca.slack-edge.com/T06BWRNMW3X-U06BZPTBDV0-g00cd520ab1f-64"> | LASSELIN Alexis | Software Engineer | [GitHub](https://github.com/AlexisLasselin) \| [LinkedIn](https://www.linkedin.com/in/alexis-lasselin-318649251/) |
| <img src="https://ca.slack-edge.com/T06BWRNMW3X-U06CMQRP3D4-gfbb2631ed2b-64"> | NAMIR Salaheddine | Software Engineer | [GitHub](https://github.com/T3rryc) \| [LinkedIn](https://www.linkedin.com/in/salaheddine-namir-3402471b8/) |
| <img src="https://ca.slack-edge.com/T06BWRNMW3X-U06C1D5D9RT-g2a7db03edc5-64"> | BAVAROIS Séréna | Quality Assurance | [GitHub](https://github.com/NanaChocolat) \| [LinkedIn](https://www.linkedin.com/in/s%C3%A9r%C3%A9na-bavarois-619975218/) |

## RACI

Here's the breakdown of the RACI roles:

- **R** stands for `Responsible` indicating the person responsible for executing the task.
- **A** stands for `Accountable` indicating the person ultimately accountable for the task's success.
- **C** stands for `Consulted` meaning individuals who provide input and expertise but are not directly responsible for the task's completion.
- **I** stands for `Informed` indicating individuals that need to be informed about task progress but have no direct responsibility for it.

> The letter **X** means that we have not yet determined who will be assigned to the task.

| Task | CUREL Clémentine | DELILLE Elone | PLANCHARD Thomas | LASSELIN Alexis | NAMIR Salaheddine | BAVAROIS Séréna |
|-|-|-|-|-|-|-|
|Project Charter | A | R | C | I | I | I |
|Functional Specifications | A | R/A | C | I | I | I |
|Technical Specifications | A | C | R/A | C | C | I |
|Architecture Diagram | A | C | R/A | C | C | I |
|Test Plan | A | I | C | C | C | R/A |
|Database of Bug | A | I | C | C | R/A |
|Unit Tests | A | C | C | R/A | R/A | C |
|Working Prototype | A | C | C | R/A | R/A | C |
|Final Product | A | C | C | R/A | R/A | C |
|Presentation | R/A | R/A | R/A | R/A | R/A | R/A |

## Stakeholders

| Role | Representative | Expectations |
| :-: | :-: | :-: |
| Client | Mr. JEANNIN Franck | The customer expects from us an assembly language written and produced by hand, a functional code interpreter as well as a virtual processor in order to be able to read the code in assembly language, all within the allotted time. |

## Milestones

The client imposes on us the following dates for the key stages of the project:

| Milestone | Due Date |
| :-: | :-: |
| Project Charter | 8 January 2024 |
| Functional Specifications | 30 January 2024, 5pm |
| Technical Specifications | 9 February 2024, 5pm |
| Test Plan | 16 February 2024, 5pm |
| Final Product | 23 February 2024, 5pm |
| Presentation | 1 March 2024 |

## Deliverables

As written in the milestones, we have to deliver the following deliverables :

- Final Product
- Functional Specifications
- Technical Specifications
- Test Plan
- Database of Bug
- Unit Tests
- Architecture Diagram
- Weekly Reports and Management Planning

And we have to present the project to the client, Mr. Franck Jeannin, on the 1st of March 2024 at 9am.

## Budget

There is no financial budget for this project because we only use free software and free resources.
However, we have a **manpower**[^15] budget of 6 persons for 8 weeks. Each person works 14 hours per week, so we have a total of 672 hours of work.

## Work management environment



# Glossary
[^1]: **Virtual Processor**: A virtual processor refers to a simulated or emulated computing unit designed to execute instructions and perform operations, typically in a software environment. It mimics the behavior of a physical processor, allowing for testing and development without the need for actual hardware.
[^2]: **Interpreter**: An interpreter is a software component that reads and executes source code or scripts in real-time, without the need for prior compilation. It translates and executes the code line by line, making it suitable for scripting languages and dynamic environments.
[^3]: **Assembly Code**: Assembly code, also known as assembly language, is a low-level programming language that represents instructions in a human-readable form, closely resembling the architecture of a computer's central processing unit (CPU). It is used for direct hardware manipulation and optimization.
[^4]: **C Language**: The C language is a high-level, general-purpose programming language renowned for its efficiency, portability, and expressive power. It serves as a versatile tool for software development and system programming.
[^5]: **Libraries**: Libraries are collections of pre-written code modules or functions that provide reusable and standardized functionality to simplify software development. They are commonly used to extend the capabilities of a programming language.
[^6]: **Dependencies**: Dependencies are external software components or libraries that a program relies on to function correctly. They must be present and correctly configured for the program to operate as intended.
[^7]: **IDE** (Integrated Development Environment): An Integrated Development Environment is a comprehensive software tool that provides developers with a unified platform for coding, debugging, testing, and managing software projects. It often includes text editors, compilers, and debugging tools.
[^8]: **Compiler**: A compiler is a software program that translates high-level source code into machine code or an intermediate form, making it suitable for execution by a computer's CPU. It is a key component in the software development process.
[^9]: **Register**: A register is a small, high-speed storage location within a computer's CPU. It is used to temporarily hold data and instructions during program execution, enhancing processing speed and efficiency.
[^10]: **Memory at the address**: "Memory at the address" refers to the content or data stored in the computer's memory (RAM) at a specific location or memory address. Memory addresses are numerical identifiers assigned to each storage location in the computer's memory, allowing programs to read, write, or manipulate data stored at those addresses.
[^11]: **Jumping Unconditionally**: Jumping unconditionally, in the context of programming, refers to a control flow statement that directs the program to transition to a specified location or label within the code without considering any conditions or constraints.
[^12]: **Label**: A label is a symbolic name or identifier assigned to a specific location or point in a program's source code. It is often used in conjunction with control flow statements, such as jumps or branches.
[^13]: **Jumping Conditionally**: Jumping conditionally, in the context of programming, involves directing the program's flow to a specified location or label within the code based on specific conditions or criteria. Conditional jumps allow programs to make decisions and execute different code paths depending on the evaluation of conditions.
[^14]: **Subroutine**: A subroutine, also known as a function or method, is a self-contained and reusable block of code within a program. It performs a specific task or operation and can be called from various parts of the program to achieve code modularity and reusability.
[^15]: **Manpower**:Manpower refers to the collective human resources or labor force available for a project or task. It encompasses the skills, expertise, and effort contributed by individuals or teams to accomplish specific goals or objectives.