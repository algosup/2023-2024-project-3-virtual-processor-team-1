typedef struct astNode {
    token_t token;
    struct astNode **children;
    int numChildren;
} astNode_t;

astNode_t *createNode(token_t token) {
    astNode_t *node = malloc(sizeof(astNode_t));
    node->token = token;
    node->children = NULL;
    node->numChildren = 0;
    return node;
}

void addChild(astNode_t *parent, astNode_t *child) {
    parent->children = realloc(parent->children, sizeof(astNode_t *) * (parent->numChildren + 1));
    parent->children[parent->numChildren] = child;
    parent->numChildren++;
}

astNode_t *buildAST(token_t *tokens, int numTokens) {
    astNode_t *root = createNode((token_t){"ROOT", "ROOT", 0, 0});
    astNode_t *currentParent = root;
    astNode_t **parentStack = malloc(sizeof(astNode_t *) * numTokens);
    int stackTop = 0;
    parentStack[stackTop] = root;

    bool inCall = false;
    bool inLabel = false;
    astNode_t *labelNode = NULL;
    int numArgs = 0;
    int lastInstructionRow = -1;

    for (int i = 0; i < numTokens; i++) {
        astNode_t *currentNode = createNode(tokens[i]);
        token_t token = tokens[i];

        if (token.column == 1 && token.row != lastInstructionRow) {
            inCall = false;
            numArgs = 0; 
                if (!inLabel) {
                currentParent = root;
            }
        }

        if (strcmp(token.type, "INSTRUCTION") == 0) {
            if (strcmp(token.value, "CALL") == 0 || strcmp(token.value, "JMP") == 0) {
                inCall = true;
                addChild(currentParent, currentNode);
                parentStack[++stackTop] = currentParent;
                currentParent = currentNode;
            } else if (strcmp(token.value, "END") == 0) {
                addChild(currentParent, currentNode);
                if (inLabel) {
                    inLabel = false;
                    currentParent = parentStack[stackTop--];
                    labelNode = NULL;
                }
            } else {
                addChild(currentParent, currentNode);
                if (inLabel) {
                    parentStack[++stackTop] = currentParent;
                    currentParent = currentNode;
                } else {
                    parentStack[++stackTop] = currentParent;
                    currentParent = currentNode;
                }
                numArgs = 0;
            }
        } else if (strcmp(token.type, "LABEL") == 0) {
            if (!inCall) {
                inLabel = true;
                labelNode = currentNode;
                addChild(root, currentNode);
                parentStack[++stackTop] = currentParent;
                currentParent = currentNode;
            } else {
                addChild(currentParent, currentNode);
            }
        } else {
            addChild(currentParent, currentNode);
            numArgs++;
            if (numArgs == 2 && inLabel) {
                currentParent = labelNode;
            }
        }

        lastInstructionRow = token.row;
    }

    free(parentStack);
    return root;
}

void printAST(astNode_t *node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("Token(\"%s\", \"%s\", %d, %d)\n", node->token.type, node->token.value, node->token.row, node->token.column);

    for (int i = 0; i < node->numChildren; i++) {
        printAST(node->children[i], depth + 1);
    }
}

void freeAST(astNode_t *node) {
    if (node == NULL) return;

    for (int i = 0; i < node->numChildren; i++) {
        freeAST(node->children[i]);
    }

    free(node->children);
    free(node);
}

void syntaxCheck(astNode_t* node, int depth) {
    if (node == NULL) return;

    // Perform syntax checks based on the type of node
    if (strcmp(node->token.type, "INSTRUCTION") == 0) {
        // Check instruction syntax
        if (strcmp(node->token.value, "MOV") == 0) {
            // Check for MOV instruction syntax
            if (node->numChildren != 2) {
                printf("Error: MOV instruction must have exactly 2 arguments.\n");
            } else {
                // Check the first argument
                astNode_t *firstArg = node->children[0];
                if (strcmp(firstArg->token.type, "VOID") == 0) {
                    printf("Error line %d: First argument of MOV cannot be VOID.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "IMMEDIATE") == 0) {
                    printf("Error line %d: First argument of MOV cannot be an IMMEDIATE.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 && strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error line %d: First argument of MOV must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of MOV cannot be VOID.\n", secondArg->token.row);
                }
                else if (strcmp(firstArg->token.value,secondArg->token.value)==0 ) 
                {
                    printf("Error line %d: First and second argument of MOV cannot be the same.\n", secondArg->token.row);
                }
            }
        } else if(strcmp(node->token.value, "ADD") == 0){
            // Check for ADD instruction syntax
            if (node->numChildren != 2) {
                printf("Error: ADD instruction must have exactly 2 arguments.\n");
            } else {
                // Check the first argument
                astNode_t *firstArg = node->children[0];
                if (strcmp(firstArg->token.type, "VOID") == 0) {
                    printf("Error line %d: First argument of ADD cannot be VOID.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "IMMEDIATE") == 0) {
                    printf("Error line %d: First argument of ADD cannot be an IMMEDIATE.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 && strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error line %d: First argument of ADD must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of ADD cannot be VOID.\n", secondArg->token.row);
                }
            }
        } else if(strcmp(node->token.value, "SUB") == 0){
            // Check for SUB instruction syntax
            if (node->numChildren != 2) {
                printf("Error: SUB instruction must have exactly 2 arguments.\n");
            } else {
                // Check the first argument
                astNode_t *firstArg = node->children[0];
                if (strcmp(firstArg->token.type, "VOID") == 0) {
                    printf("Error line %d: First argument of SUB cannot be VOID.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "IMMEDIATE") == 0) {
                    printf("Error line %d: First argument of SUB cannot be an IMMEDIATE.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 && strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error line %d: First argument of SUB must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of SUB cannot be VOID.\n", secondArg->token.row);
                }
            }
        } else if(strcmp(node->token.value, "MUL") == 0){
            // Check for MUL instruction syntax
            if (node->numChildren != 2) {
                printf("Error: MUL instruction must have exactly 2 arguments.\n");
            } else {
                // Check the first argument
                astNode_t *firstArg = node->children[0];
                if (strcmp(firstArg->token.type, "VOID") == 0) {
                    printf("Error line %d: First argument of MUL cannot be VOID.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "IMMEDIATE") == 0) {
                    printf("Error line %d: First argument of MUL cannot be an IMMEDIATE.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 && strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    
                    printf("Error line %d: First argument of MUL must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of MUL cannot be VOID.\n", secondArg->token.row);
                }
            }
        } else if(strcmp(node->token.value, "DIV") == 0){
            // Check for DIV instruction syntax
            if (node->numChildren != 2) {
                printf("Error: DIV instruction must have exactly 2 arguments.\n");
            } else {
                // Check the first argument
                astNode_t *firstArg = node->children[0];
                if (strcmp(firstArg->token.type, "VOID") == 0) {
                    printf("Error line %d: First argument of DIV cannot be VOID.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "IMMEDIATE") == 0) {
                    printf("Error line %d: First argument of DIV cannot be an IMMEDIATE.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 && strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error line %d: First argument of DIV must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of DIV cannot be VOID.\n", secondArg->token.row);
                }
            }
        } else if(strcmp(node->token.value, "CMP") == 0){
            // Check for CMP instruction syntax
            if (node->numChildren != 2) {
                printf("Error: CMP instruction must have exactly 2 arguments.\n");
            } else {
                // Check the first argument
                astNode_t *firstArg = node->children[0];
                if (strcmp(firstArg->token.type, "VOID") == 0) {
                    printf("Error line %d: First argument of CMP cannot be VOID.\n", firstArg->token.row);
                } else if (strcmp(firstArg->token.type, "IMMEDIATE") == 0) {
                    printf("Error line %d: First argument of CMP cannot be an IMMEDIATE.\n", firstArg->token.row);
        } }
        } else if(strcmp(node->token.value, "JMP") == 0){
            if(node->numChildren >= 3 || node->numChildren == 0){
                printf("Error: JMP instruction must have 1 argument.\n");
            } else {
                astNode_t* firstArg = node->children[0];
                if(strcmp(firstArg->token.type, "VOID") == 0){
                    printf("Error line %d: First argument of JMP cannot be VOID.\n", firstArg->token.row);
                } else if(strcmp(firstArg->token.type, "IMMEDIATE") == 0){
                    printf("Error line %d: First argument of JMP cannot be an IMMEDIATE.\n", firstArg->token.row);
                } else if(strcmp(firstArg->token.type, "REGISTER") == 0 && strcmp(firstArg->token.type, "ADDRESS_REGISTER") == 0){
                    printf("Error line %d: First argument of JMP cannot be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                if(strcmp(firstArg->token.value, "CALL") == 0){
                    printf("Error line %d: First argument of JMP cannot be CALL.\n", firstArg->token.row);
                }

                astNode_t* secondArg = node->children[1];
                if(strcmp(secondArg->token.type, "VOID") != 0){
                    printf("Error line %d: There is only one argument in a JMP.\n", secondArg->token.row);
                }
            }
        }
        else if(strcmp(node->token.value, "CALL") == 0){
            if(node->numChildren >= 3 || node->numChildren == 0){
                printf("Error: CALL instruction must have 1 argument.\n");
            } else {
                astNode_t* firstArg = node->children[0];
                if(strcmp(firstArg->token.type, "VOID") == 0){
                    printf("Error line %d: First argument of CALL cannot be VOID.\n", firstArg->token.row);
                } else if(strcmp(firstArg->token.type, "IMMEDIATE") == 0){
                    printf("Error line %d: First argument of CALL cannot be an IMMEDIATE.\n", firstArg->token.row);
                } else if(strcmp(firstArg->token.type, "REGISTER") == 0 || strcmp(firstArg->token.type, "ADDRESS_REGISTER") == 0){
                    printf("Error line %d: First argument of CALL cannot be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }

                astNode_t* secondArg = node->children[1];
                if(strcmp(secondArg->token.type, "VOID") != 0){
                    printf("Error line %d: There is only one argument in a CALL.\n", secondArg->token.row);
                }
            }
        }
        else if(strcmp(node->token.value, "END") == 0){
            if(node->numChildren != 0){
                printf("Error: END instruction must have 0 argument.\n");
            }
        }
    }


    for (int i = 0; i < node->numChildren; i++) {
        syntaxCheck(node->children[i], depth + 1);
    }
}

void root()
{
}

void label()
{
}

void instruction()
{
}

void registers()
{  
}

void immediate()
{
}

void negative()
{
}

void string()
{
}

void call()
{
}

void ret()
{
}

void end()
{
}

void disp()
{
}