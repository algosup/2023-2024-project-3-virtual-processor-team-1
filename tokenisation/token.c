#include "fileCleaner.h"

/*
Input:
{"MOV", "R1", "#5"}

Output:
{Token("instruction", "MOV", 1, 1), Token("register", "R1", 1, 2), Token("immediate", "#5", 1, 3)},
*/