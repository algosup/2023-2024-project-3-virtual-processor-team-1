#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

i32 littleEndianToRealValue(i32 value){
    i32 result = 0;
    result |= (value & 0x000000FF) << 24;
    result |= (value & 0x0000FF00) << 8;
    result |= (value & 0x00FF0000) >> 8;
    result |= (value & 0xFF000000) >> 24;
    return result;
}
i64 searchLabel(i32 label){
	for(i64 i = 0; i < arrayTableLenght; i++){
		i64 temp = littleEndianToRealValue(labelTable[i]);
		if(temp == label){
			return addressTable[i];
		}
	}
	return -1;
}





