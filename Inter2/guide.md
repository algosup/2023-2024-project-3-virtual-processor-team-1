**Opcodes**
|**Instruction**| **Opcode** |
|-----------|----------------|
  |MOV R1, 0X332| 0x10|
  |#MOV R1, adress| 0x11|
  |#MOV R1, R2| 0x12|
  |-| - |
  |ADD R1, R2|0x20 |
  |#ADD R1, 0X332 |0x22|
  |SUB R1, R2|0x21|
  |#SUB R1, 0X332 |0x23|
  |MUL R1, R2| 0x30|
  |#MUL R1, 0X332| 0x31|
  |DIV R1, R2 |0x40|
  |#DIV R1, 0X332  |0x41|
  |-|-|
  |.label| 0x99 |
  |End| 0x98 |
  |RET| 0x97 |
  |CALL| 0x96 |
  |-|-|
  |CMP R1, R2|0x50|
  |#CMP R1, 0X332|0x51|
  |-|-|
  |JMP .label| 0x60|
  |JE .label|0x61|
  |JNE .label|0x62|
  |JG .label|0x63|
  |JGE .label|0x64|
  |JL .label|0x65|
  |JLE .label|0x66|
  |-|-|
  |AND R1, R2|0x70|
  |#AND R1, 0X332|0x71|
  |XOR R1, R2|0x72|
  |#XOR R1, 0X332|0x73|
  |OR R1, R2| 0x74|
  |#OR R1, 0X332| 0x75|
  |NOT R1| 0x76|
  |GAD R1|0x77|
  |-|-|
  |**General Register**||
  | R1 |0x01|
  |R2 |0x02|
  |R3 |0x03|
  |R4 |0x04|
  |**Adress register** ||
  |A1 |0x11|
  |A2 |0x12|
  |A3  |0x13|
  |A4  |0x14|
  
**Example of MOV instruction**
|0x00| 0x01| 0x00| 0x00| 0x00| 0x01|
|----|-----|-----|-----|-----|-----|
|MOV | R1  | Unused| Unused| Unused| 1|
|OPCODE| REGISTER | DATA | DATA | DATA | DATA |
|0x00| 0x01| 0x00| 0x00| 0x20| 0x33|
|----|-----|-----|-----|-----|-----|
|MOV | R1  | Unused| Unused| | |
|OPCODE| REGISTER | DATA | DATA | DATA | DATA |