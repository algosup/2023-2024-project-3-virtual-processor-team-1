# Test Cases

## Overview

A test case is a defined format for software testing, required to check if any particular feature of our program is working or not. It consists of a set of instructions that need to be check to test our program.

## Test Case template 

|ID|T0|
|--|--|
|Test Case Name|Name|
|Test Case Pre-condition|Pre-condition|
|Test Case Description|Description|
|Step of the Test Case|Steps|
|Expected Result|Expected result|
|Priority|None Low Medium High|
|Test Case Status|Not implement, In progress, Failed, Passed|

## 1. Test Case: Register storing and copying

|ID|T1|
|--|--|
|Test Case Name|Register storing and copying|
|Test Case Pre-condition|The program should run.|
|Test Case Description|Immediate values can be stored in registers and contents can be copied from one register to another.|
|Step of the Test Case|1. Store an immediate value in register `R1`. <br>2. Copy the contents of `R1` to register `R2`. <br>3. Check if the value in `R2` matches the original value stored in `R1`.
|Expected Result|The value in `R2` should be identical to the value initially stored in `R1`.|
|Priority|High|
|Test Case Status|Passed|

## 2. Test Case: Arithmetic operation
### 2.1 Addition: `ADD`
#### 2.1.1 Add a immediate value

|ID|T2.1.1|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic addition (`ADD`) between two immediate values.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2`<br>2. Perform `ADD` `R1`, `#3` .|
|Expected Result|`R1` should contents the result of the addition between `R1` and `#3`. It should be 5.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.2 Add two values of two registers

|ID|T2.1.2|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic addition (`ADD`) between two immediate values stored in two registers.|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `#3` <br>2. Perform `ADD` `R1`, `R2` .|
|Expected Result|`R1` should contents the result of the addition between `R1` and `R2`. It should be 5.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.3 Add a negative number

|ID|T2.1.2.3|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic addition (`ADD`) with negative values.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#10`<br>2. Perform `ADD` `R1`, `-5` .|
|Expected Result|`R1` should contents the result of the addition between `R1` and `-5`. It should be 5.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.4 Add a negative number stored into a register

|ID|T2.1.4|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an rithmetic addition (`ADD`) between two registers that contains negatives values.|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`: <br> `MOV` `R1`, `-2` <br> `MOV` `R2`, `-3` <br>2. Perform `ADD` `R1`, `R2` .|
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`. It should be -5.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.5 Add an overflow

|ID|T2.1.5|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform arithmetic addition (`ADD`) when we have an overflow.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2` <br> 2. Perform `ADD` `R1`, `#65535` .|
|Expected Result|`R1` should show an errors message due to an overflow. "The programme was halted due to an overflow." |
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.6 Add a string stored in a register

|ID|T2.1.6|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic addition (`ADD`) with a string.|
|Step of the Test Case|1. Store values in registers `R1` and `R2`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `Hello` <br>2. Perform `ADD` `R1`, `R2` .|
|Expected Result|`R1` should show an error due of a missmatched type errors. "Line number of the error + Code on the line + The operands are not of the same type."|
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.7 Add a string

|ID|T2.1.7|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic addition (`ADD`) with a string.|
|Step of the Test Case|1. Store values in registers `R1`: <br> `MOV` `R1`, `#2` <br>2. Perform `ADD` `R1`, `Hello` .|
|Expected Result|`R1` should show an error due of a missmatched type errors. "Line number of the error + Code on the line + The operands are not of the same type."
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.8 Add an address

|ID|T2|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic addition (`ADD`) with an address.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2` <br> 2. Perform `ADD` `R1`, `A1` .|
|Expected Result|`R1` should show an error.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.9 Add just one register

|ID|T2.1.9|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic addition (`ADD`) between when we put only one register and nothing after.|
|Step of the Test Case|1. Perform `ADD` `R1`|
|Expected Result| The program should show an error due to a missing instruction.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.1.10 Add three registers or more

|ID|T2.1.10|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic operations addition (`ADD`) between more than two values.|
|Step of the Test Case|1. Store immediate values in registers `R1`, `R2` and `R3`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `#3` <br> `MOV` `R3`, `#2`<br>2. Perform `ADD` `R1`, `R2`,`R3`.|
|Expected Result|The program should show an error.|
|Priority|High|
|Test Case Status|Not implement|

### 2.2 Multiplication: `MUL`
#### 2.2.1 Multiplicate a immediate value

|ID|T2.2.1|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic multiplication (`MUL`) between two immediate values.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2`<br>2. Perform `MUL` `R1`, `#3` .|
|Expected Result|`R1` should contents the result of the multiplication between `R1` and `#3`. It should be 6.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.2 Multiplicate two values of two registers

|ID|T2.2.2|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic multiplication (`MUL`) between two immediate values stored in two registers.|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `#3` <br>2. Perform `MUL` `R1`, `R2` .|
|Expected Result|`R1` should contents the result of the multiplication between `R1` and `R2`. It should be 6.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.3 Multiplicate a negative number

|ID|T2.2.3|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic multiplication (`MUL`) with negative values.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#10`<br>2. Perform `MUL` `R1`, `-5` .|
|Expected Result|`R1` should contents the result of the addition between `R1` and `-5`. It should be -50.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.4 Multiplicate a negative number stored into a register

|ID|T2.2.4|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic multiplication (`MUL`) between two registers that contains negatives values.|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`: <br> `MOV` `R1`, `-2` <br> `MOV` `R2`, `-3` <br>2. Perform `MUL` `R1`, `R2` .|
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`. It should be -6.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.5 Multiplicate an overflow

|ID|T2.2.5|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic multiplication (`MUL`) when we have a overflow.|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`: <br> `MOV` `R1`, `#2` <br> 2. Perform `MUL` `R1`, `#65535` .|
|Expected Result|`R1` should show an errors due to an overflow. "The programme was halted due to an overflow." |
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.6 Multiplicate a string

|ID|T2.2.6|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic multiplication (`MUL`) with a string.|
|Step of the Test Case|1. Store values in registers `R1` and `R2`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `"Hello"` <br>2. Perform `MUL` `R1`, `R2` .|
|Expected Result|`R1` should show an error due of a instruction errors.  "Line number of the error + Code on the line + The operands are not of the same type."|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.7 Multiplicate a string stored in a register

|ID|T2.2.7|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic multiplication (`MUL`) with a string.|
|Step of the Test Case|1. Store values in registers `R1`: <br> `MOV` `R1`, `#2` <br>2. Perform `MUL` `R1`, `"Hello"` .|
|Expected Result|`R1` should show an error due of a instruction errors. "Line number of the error + Code on the line + The operands are not of the same type."|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.8 Multiplicate an address

|ID|T2.2.8|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic multiplication (`MUL`) with an address.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2` <br> 2. Perform `MUL` `R1`, `A1` .|
|Expected Result|`R1` should show an error.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.9 Multiplicate one register

|ID|T2.2.9|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic multiplication (`MUL`) between when we put only one register and nothing after.|
|Step of the Test Case|1. Perform `MUL` `R1`|
|Expected Result| The program should show an error due to a missing instruction.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.2.10 Multiplicate R1 R2 R3

|ID|T2.2.10|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic operations multiplication (`MUL`) between 3 values.|
|Step of the Test Case|1. Store immediate values in registers `R1`, `R2` and `R3`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `#3` <br> `MOV` `R3`, `#2`<br>2. Perform `MUL` `R1`, `R2`,`R3`.|
|Expected Result|The program should show an error.|
|Priority|High|
|Test Case Status|Not implement|

### 2.3 Division: `DIV`
#### 2.3.1 Divide a immediate value

|ID|T2.3.1|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic division (`DIV`) between two immediate values.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2`<br>2. Perform `DIV` `R1`, `#6` .|
|Expected Result|`R1` should contents the result of the multiplication between `R1` and `#6`. It should be 3.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.2 Divide two values of two registers

|ID|T2.3.2|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic division (`DIV`) between two immediate values stored in two registers.|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `#4` <br>2. Perform `DIV` `R1`, `R2` .|
|Expected Result|`R1` should contents the result of the multiplication between `R1` and `R2`. It should be 2.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.3 Divide a negative number

|ID|T2.3.3|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic division (`DIV`) with negative values.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#10`<br>2. Perform `DIV` `R1`, `-5` .|
|Expected Result|`R1` should contents the result of the addition between `R1` and `-5`. It should be -2.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.4 Divide a negative number stored into a register

|ID|T2.3.4|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly perform an arithmetic division (`DIV`) between two registers that contains negatives values.|
|Step of the Test Case|1. Store immediate values in registers `R1` and `R2`: <br> `MOV` `R1`, `-6` <br> `MOV` `R2`, `-3` <br>2. Perform `DIV` `R1`, `R2` .|
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`. It should be 2.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.5 Divide by zero

|ID|T2.3.5|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic division (`DIV`) by zero.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2` <br> 2. Perform `DIV` `R1`, `#0` .|
|Expected Result|`R1` should show an errors. //|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.6 Divide a string

|ID|T2.3.6|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic division (`DIV`) with a string.|
|Step of the Test Case|1. Store values in registers `R1` and `R2`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `"Hello"` <br>2. Perform `DIV` `R1`, `R2` .|
|Expected Result|`R1` should show an error due of a instruction errors. "Line number of the error + Code on the line + The operands are not of the same type."|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.7 Multiplicate a string stored in a register

|ID|T2.3.7|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic division (`DIV`) with a string.|
|Step of the Test Case|1. Store values in registers `R1`: <br> `MOV` `R1`, `#2` <br>2. Perform `DIV` `R1`, `"Hello"` .|
|Expected Result|`R1` should show an error due of a instruction errors. "Line number of the error + Code on the line + The operands are not of the same type."|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.8 Divide an address

|ID|T2.3.8|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic division (`DIV`) with an address.|
|Step of the Test Case|1. Store immediate values in registers `R1`: <br> `MOV` `R1`, `#2` <br> 2. Perform `DIV` `R1`, `A1` .|
|Expected Result|`R1` should show an error.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.9 Divide one register

|ID|T2.3.9|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic division (`DIV`) between when we put only one register and nothing after.|
|Step of the Test Case|1. Perform `DIV` `R1`|
|Expected Result| The program should show an error due to a missing instruction.|
|Priority|High|
|Test Case Status|Not implement|

#### 2.3.10 Divide R1 R2 R3

|ID|T2.3.10|
|--|--|
|Test Case Name|Arithmetic operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should not perform an arithmetic operations division (`DIV`) between 3 values.|
|Step of the Test Case|1. Store immediate values in registers `R1`, `R2` and `R3`: <br> `MOV` `R1`, `#2` <br> `MOV` `R2`, `#3` <br> `MOV` `R3`, `#2`<br>2. Perform `DIV` `R1`, `R2`,`R3`.|
|Expected Result|The program should show an error.|
|Priority|High|
|Test Case Status|Not implement|

## 3. Test Case: Logical operation
### 3.1 OR

|ID|T3.1|
|--|--|
|Test Case Name|Logical operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly execute logical `OR`|
|Step of the Test Case|1. Store binary values in registers `R1` and `R2`:<br>`MOV` `R1`, `#6` ; Set R1 to binary 0110<br>`MOV` `R2`, `#3` ; Set R2 to binary 0011  <br>2. Perform `OR`:<br>`OR` `R1`, `R2` ; Perform OR operation: R1 = 0110 OR 0011 = 0111 (7 in decimal)|
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`. Here, 7.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

#### 3.2 AND

|ID|T3.2|
|--|--|
|Test Case Name|Logical operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly execute logical `AND`.|
|Step of the Test Case|1. Store binary values in registers `R1` and `R2`: <br> MOV R1, #5     ; Set R1 to binary 0101 <br> MOV R2, #3     ; Set R2 to binary 0011 <br> 2. Perform `AND`: <br> AND R1, R2    ; Perform AND operation: R1 = 0101 AND 0011 = 0001 (1 in decimal)|
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`. Here, it's 1.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

#### 3.3 XOR

|ID|T3.3|
|--|--|
|Test Case Name|Logical operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly execute logical `XOR`.|
|Step of the Test Case|1. Store binary values in registers `R1` and `R2`: <br> MOV R1, #6     ; Set R1 to binary 0110 <br> MOV R2, #3     ; Set R2 to binary 0011 <br> 2. Perform `XOR`: <br> XOR R1, R2    ; Perform XOR operation: R1 = 0110 XOR 0011 = 0101 (5 in decimal)|
|Expected Result|`R1` should contents the result of the operation between `R1` and `R2`. Here it's 5|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

#### 3.4 NOT

|ID|T3.4|
|--|--|
|Test Case Name|Logical operation|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The assembly program should correctly execute logical `NOT`.|
|Step of the Test Case|1. Store binary values in registers `R1` and `R2`: <br> MOV R1, #5     ; Set R1 to binary 0101 <br> 2. Perform `NOT`: <br> NOT R1        ; Perform NOT operation: R1 = NOT 0101 = 1010 (10 in decimal)|
|Expected Result|`R1` should contents the result of the operation. Here it's 10|
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

 //
## 5. Test Case: Conditionnal jump

### 5.1 Jump Equal

|ID|T5|
|--|--|
|Test Case Name|Conditionnal jump|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly perform conditional jumps based on specified conditions. For `JE` Jump equal, it jumps only if two values is equal.|
|Step of the Test Case|1.  Move a value in a register to compare. <br><br> `MOV` `R1`, `#5`     ; Set R1 to 5 <br> <br> 2. Use a `CMP` instruction to compare two values. <br><br>  `CMP` `R1`, `#5`     ; Compare the value in R1 with 5 <br> <br>  3. Based on this condition use a `conditionnal jump` instruction to direct the program into a called function. <br> <br> `JE` `Label` ; Jump to Label if R1 equals 5|
|Expected Result|The program should jump only when the conditions are fullfiled.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

### 5.1 Jump Not Equal

|ID|T5|
|--|--|
|Test Case Name|Conditionnal jump|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly perform conditional jumps based on specified conditions. For `JNE` Jump not equal, it jumps only if two values is not equal.|
|Step of the Test Case|1.  Move a value in a register to compare. <br><br> `MOV` `R1`, `#5`     ; Set R1 to 5 <br> <br> 2. Use a `CMP` instruction to compare two values. <br><br>  `CMP` `R1`, `#5`     ; Compare the value in R1 with 5 <br> <br>  3. Based on this condition use a `conditionnal jump` instruction to direct the program into a called function. <br> <br> `JE` `Label` ; Jump to Label if R1 not equals 5|
|Expected Result|The program should jump only when the conditions are fullfiled.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

### 5.1 Jump Greater

|ID|T5|
|--|--|
|Test Case Name|Conditionnal jump|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly perform conditional jumps based on specified conditions. For `JG` Jump greater, it jumps only if one value is greater than another.|
|Step of the Test Case|1.  Move a value in a register to compare. <br><br> `MOV` `R3`, `#15`    ; Set `R3` to 15 <br> <br> 2. Use a `CMP` instruction to compare two values. <br><br> `CMP` `R3`, `#10`    ; Compare the value in R3 with 10 <br> <br>  3. Based on this condition use a `conditionnal jump` instruction to direct the program into a called function. <br> <br>`JG` `Label`    ; Jump to Label if R3 is greater than 10|
|Expected Result|The program should jump only when the conditions are fullfiled.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

### 5.1 JGE

|ID|T5|
|--|--|
|Test Case Name|Conditionnal jump|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly perform conditional jumps based on specified condition. For `JGE` Jumps greater or equal, it jumps only if one values is greater than or equal to a specified value|
|Step of the Test Case|1.  Move a value in a register to compare. <br><br> `MOV` `R3`, `#15`    ; Set `R3` to 15 <br> <br> 2. Use a `CMP` instruction to compare two values. <br><br> `CMP` `R3`, `#10`    ; Compare the value in R3 with 10 <br> <br>  3. Based on this condition use a `conditionnal jump` instruction to direct the program into a called function. <br> <br>`JGE` `Label`    ; Jump to Label if R3 is equal or greater than 10
|Expected Result|The program should jump only when the conditions are fullfiled.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

### 5.1 Jump Less

|ID|T5|
|--|--|
|Test Case Name|Conditionnal jump|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly perform conditional jumps based on specified conditions. For `JL` Jump less, it jumps only if one value is less than a specified value.|
|Step of the Test Case|1.  Move a value in a register to compare. <br><br> `MOV` `R3`, `#6`    ; Set `R3` to 6 <br> <br> 2. Use a `CMP` instruction to compare two values. <br><br> `CMP` `R3`, `#10`    ; Compare the value in R3 with 10 <br> <br>  3. Based on this condition use a `conditionnal jump` instruction to direct the program into a called function. <br> <br>`JL` `Label`    ; Jump to Label if R3 is less than 10|
|Expected Result|The program should jump only when the conditions are fullfiled.|
|Priority|High|
|Test Case Status|Not implement, In progress, Failed, Passed |

### 5.1 Jump Less Equal

|ID|T5|
|--|--|
|Test Case Name|Conditionnal jump|
|Test Case Pre-condition|The program should run.|
|Test Case Description|The program should correctly perform conditional jumps based on specified conditions. For`JLE` Jump Less Equal, it jumps only if one value is less than or equal to a specified value.|
|Step of the Test Case|1.  Move a value in a register to compare. <br><br> `MOV` `R3`, `#15`    ; Set `R3` to 15 <br> <br> 2. Use a `CMP` instruction to compare two values. <br><br> `CMP` `R3`, `#15`    ; Compare the value in R3 with 15 <br> <br>  3. Based on this condition use a `conditionnal jump` instruction to direct the program into a called function. <br> <br>`JLE` `Label`    ; Jump to Label if R3 is equal or less than 10|
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
