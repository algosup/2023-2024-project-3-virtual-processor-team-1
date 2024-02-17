#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

i32 littleEndianToRealValue(i32 value){
    i32 result = 0; 
    while(value != 0){
        result = (result << 8) | (value & 0xFF);
        value = value >> 8;
    }
    return result;
}




