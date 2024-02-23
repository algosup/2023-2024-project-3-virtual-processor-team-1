#ifndef GLOBAL_H
#define GLOBAL_H
#define MAX_LINES 100
#define MAX_PROGRAM_LENGTH 53
#define MAX_TOKENS 3
extern int error;
void incrementError();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "lexical.h"
#include "parser.h"
#include "mc.h"
#include "vm.h"
#endif