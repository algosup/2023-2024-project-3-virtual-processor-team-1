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
    astNode_t *labelParent = root;
    int stackTop = 0;
    parentStack[stackTop] = root;

    bool inCall = false;
    astNode_t *lastCallNode = NULL;
    int lastInstructionRow = -1;

    for (int i = 0; i < numTokens; i++) {
        astNode_t *currentNode = createNode(tokens[i]);

        if (strcmp(tokens[i].type, "LABEL") == 0 && inCall) {
            addChild(lastCallNode, currentNode);
            addChild(lastCallNode, createNode((token_t){"REGISTER", "VOID", 0, 0})); // Add a VOID register
            inCall = false;
            currentParent = parentStack[--stackTop]; // Close the children
        } else if (strcmp(tokens[i].type, "LABEL") == 0) {
            addChild(currentParent, currentNode);
            addChild(currentParent, createNode((token_t){"REGISTER", "VOID", 0, 0})); // Add a VOID register
            parentStack[++stackTop] = currentNode;
            currentParent = currentNode;
            labelParent = currentNode;
        } else if (strcmp(tokens[i].value, "RET") == 0 || strcmp(tokens[i].value, "END") == 0) {
            addChild(labelParent, currentNode);
            currentParent = parentStack[--stackTop]; // Close the children
        } else {
            if (tokens[i].column == 1 && tokens[i].row != lastInstructionRow) {
                currentParent = parentStack[stackTop];
            }
            addChild(currentParent, currentNode);
            if (strcmp(tokens[i].type, "INSTRUCTION") == 0) {
                lastInstructionRow = tokens[i].row;
                if (strcmp(tokens[i].value, "CALL") == 0) {
                    inCall = true;
                    lastCallNode = currentNode;
                } else {
                    currentParent = currentNode;
                }
            }
        }
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
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 &&
                           strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
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
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 &&
                           strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error line %d: First argument of ADD must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of ADD cannot be VOID.\n", secondArg->token.row);
                }
                else if (strcmp(firstArg->token.value,secondArg->token.value)==0 ) 
                {
                    printf("Error line %d: First and second argument of ADD cannot be the same.\n", secondArg->token.row);
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
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 &&
                           strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error line %d: First argument of SUB must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of SUB cannot be VOID.\n", secondArg->token.row);
                }
                else if (strcmp(firstArg->token.value,secondArg->token.value)==0 ) 
                {
                    printf("Error line %d: First and second argument of SUB cannot be the same.\n", secondArg->token.row);
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
                else if (strcmp(firstArg->token.value,secondArg->token.value)==0 ) 
                {
                    printf("Error line %d: First and second argument of MUL cannot be the same.\n", secondArg->token.row);
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
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 &&
                           strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error line %d: First argument of DIV must be a REGISTER or ADDRESS_REGISTER.\n", firstArg->token.row);
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error line %d: Second argument of DIV cannot be VOID.\n", secondArg->token.row);
                }
                else if (strcmp(firstArg->token.value,secondArg->token.value)==0 ) 
                {
                    printf("Error line %d: First and second argument of DIV cannot be the same.\n", secondArg->token.row);
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
        } }}
        else if(strcmp(node->token.value,"JMP") == 0 ) // TODO Check all jump statements
        {
            if(node->numChildren != 2) 
            {
                if(node->children[1]->token.type != "VOID")
                {
                    printf("Error line %d: JMP instruction must have exactly 1 argument.\n", node->token.row);
                    printf("Parent Token(\"%s\", \"%s\", %d, %d)\n", node->token.type, node->token.value, node->token.row, node->token.column);
                    printf("child1 Token(\"%s\", \"%s\", %d, %d)\n", node->children[0]->token.type, node->children[0]->token.value, node->children[0]->token.row, node->children[0]->token.column);
                    printf("child2 Token(\"%s\", \"%s\", %d, %d)\n", node->children[1]->token.type, node->children[1]->token.value, node->children[1]->token.row, node->children[1]->token.column);
                }
            }
            else if(strcmp(node->children[0]->token.type, "LABEL") == 0 ||strcmp(node->children[0]->token.type, "ROOT") == 0)
            {
                printf("Error line %d: JMP instruction must have a LABEL as an argument.\n", node->token.row);
            }
            else if(node->children[0]->token.type == "VOID")
            {
                printf("Error line %d: JMP instruction must have a LABEL as an argument.\n", node->token.row);
            }
          
            
        }
           // ********LOGICAL OPERATOR
    else if (strcmp(node->token.value,"AND")== 0||strcmp(node->token.value,"OR")== 0||
    strcmp(node->token.value,"XOR")== 0 || strcmp(node->token.value,"NOT")== 0)
    {
        astNode_t *firstArg = node->children[0];
        astNode_t *secondArg = node->children[1];
        if(node->numChildren !=2)
        {
            printf("Error line %d: Logical operator must have exactly 2 arguments.\n"
            , node->token.row);
        }
        else if (strcmp(firstArg->token.type,"VOID")==0)
        {
                printf("Error line %d: First argument of logical operator cannot be VOID.\n"
                , node->children[0]->token.row);
        }
        else if(strcmp(secondArg->token.type,"VOID")==0)
        {
            printf("Error line %d: Second argument of logical operator cannot be VOID.\n"
            , node->children[1]->token.row);
        }
        else if(strcmp(firstArg->token.type,"REGISTER")!=0)
        {
            printf("Error line %d: First argument of logical operator must be a REGISTER.\n"
            , node->children[0]->token.row);
        }
        else if (strcmp(secondArg->token.type,"REGISTER")!=0
        && strcmp(secondArg->token.type,"IMMEDIATE")!=0)
        {
            printf("Error line %d: Second argument of logical operator must be a REGISTER or IMMEDIATE.\n"
            , node->children[1]->token.row);
        }
        
    }
    //**********
         else {
            printf("Error line %d: Unsupported instruction: %s\n",node->token.row ,node->token.value);
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