# Tests Cases

## Overview

A test case is a defined format for software testing, required to check if any particular feature of our program if working or not. It consists of a set of instructions that need to be check to test our program.

## Test Case template 

|ID|T0|
|--|--|
|Test Case Name|Name|
|Test Case Pre-condition|Pre-condition|
|Test Case Description|Description|
|Step of the Test Case|Steps|
|Expected Result|Expected result|
|Priority|None Low Medium High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 1. Test Case: Register storing and copying

|ID|T1|
|--|--|
|Test Case Name|Register storing and copying|
|Test Case Pre-condition|The program should run.|
|Test Case Description|Immediate values can be stored in registers and contents can be copied from one register to another.|
|Step of the Test Case|1. Store an immediate value in register `R1`. <br>2. Copy the contents of `R1` to register `R2`. <br>3. Check if the value in `R2` matches the original value stored in `R1`.
|Expected Result|The value in `R2` should be identical to the value initially stored in `R1`.|
|Priority|High|
|Test Case Status|Passed |

## 2. Test Case: Arithmetic operation

|ID|T2|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform arithmetic operations (Addition (`ADD`), Substration (`SUB`), Multiplication (`MUL`), Division (`DIV`)).|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`. <br>2. Perform `Arithmetic operands` `R1`, `R2` (like `ADD` `R1`, `R2`).|
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`.|
|Priority|High|
|Test Case Status|Not implement|

## 3. Test Case: Logical operation

|ID|T3|
|--|--|
|Test Case Name|Logical operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly execute logical operations (`OR`, `AND`, `XOR` and `NOT`).|
|Step of the Test Case|1. Store binary values in registers `R1` and `R2`. <br>2. Perform `Logical operands` `R1`, `R2` (like `XOR` `R1`, `R2`). |
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 4. Test Case: Unconditionnal jump

|ID|T4|
|--|--|
|Test Case Name|Unconditionnal jump |
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly performs an unconditional jump. |
|Step of the Test Case| 1. Implement a simple loop using `JMP` instruction. <br>2. Verify that the loop executes as expected.|
|Expected Result|The program should jump to the label called.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 5. Test Case: Conditionnal jump

|ID|T5|
|--|--|
|Test Case Name|Conditionnal jump|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly perform conditional jumps based on specified conditions (`JE`, `JNE`, `JG`, `JGE`, `JL`, `JLE`).|
|Step of the Test Case|1. Use a `CMP` instruction to compare two values. <br>2. Based on this condition use a `conditionnal jump` instruction to direct the program into a called function. <br>3. Verify that the loop executes as expected.|
|Expected Result|The program should jump only when the conditions are fullfiled.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 6. Test Case: Function and subroutine

|ID|T6|
|--|--|
|Test Case Name|Function and subroutine|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should execute correctly subroutines, and functions.|
|Step of the Test Case|Test Steps for Function: <br>1. Define a function that performs a specific operation. <br>2. Call the function from the main program. <br>3. Verify the result of the function. <br><br>Test Steps for Subroutine: <br>1. Define a subroutine that performs a task. <br>2. Call the subroutine from within a function. <br>3. Verify that the subroutine has performed its task correctly.|
|Expected Result|The program should run correctly subroutines and functions when they are called.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 7. Test Case: Basic assembly instruction *(like MOV, CMP, and basic memory operations)*

|ID|T7|
|--|--|
|Test Case Name|Basic assembly instruction|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly execute these instructions, and the results should match the expected outcomes.|
|Step of the Test Case|1. Write `Operand` `Destination` `Source`. <br>2. Verify that the operands has performed its task correctly.|
|Expected Result|The program should execute correclty the instruction.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 8. Test Case: Syntactical error

|ID|T8|
|--|--|
|Test Case Name|Syntactical error|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should provide clear error messages indicating the nature and location of syntactical errors.|
|Step of the Test Case|1. Deliberatly introduce syntactical error in the assembly code. <br> 2. Execute the program. <br>3. Check the error message. |
|Expected Result|The program should show an error message like this "Line number of the error + Code on the line + Too many parameters have been added. Syntax should be : "`ARGUMENT` `PARAM1`, `PARAM2`".|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 9. Test Case: Semantical error

|ID|T9|
|--|--|
|Test Case Name|Semantical error|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should provide clear error messages indicating the nature and location of semantical errors.|
|Step of the Test Case|1. Deliberatly introduce semantical error in the assembly code. <br> 2. Execute the program. <br>3. Check the error message.|
|Expected Result|The program should show an error message like this "Line number of the error + Code on the line + The operator or instruction does not exist.".|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 10. Test Case: File cleaner 

|ID|T10
|--|--|
|Test Case Name|File cleaner|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should cleans the file involves removing comments and whitespaces to facilitate easier reading.|
|Step of the Test Case|1. Write a code, with "`Operand` `destination`, `source`" and comment.<br> 2. Verify that the program cleans the file by removing comments and whitespaces.|
|Expected Result|We should receive the same code whithout comments and whitespaces. <br>Example:<br><br>*non-cleaned code:*<br><br>MOV R1, #1 <br>MOV R2, #2 <br>; This is a comment <br> ADD R3, R1<br> <br>*cleaned code:*<br><br>arrayFile[3][nbrLines]= {<br>{"MOV", "R1", "#1"},<br>{"MOV", "R2", "#2"},<br>{"ADD", "R3", "R1"}<br>}|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

## 11. Test Case: Tokenisation
|ID|T1|
|--|--|
|Test Case Name|Logical operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should breaking down the assembly code into manageable units called tokens.|
|Step of the Test Case|1. Transform a cleaned code into a tokenised code by create a token with the right type and value according to the word.|
|Expected Result|We should received the same code in tokenised form like: {Token("type of the token", "value of the token", "line, where the token is located", "column where the token is located")}  from a cleaned code. <br> Example: <br><br>*cleaned code:*<br><br> {"MOV", "R1", "#1"} <br> <br>*tokenised code:* <br><br>{Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "1", 1, 3)}|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |
