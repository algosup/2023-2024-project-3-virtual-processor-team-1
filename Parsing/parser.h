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
        // if (strcmp(tokens[i].type, "VOID") == 0) continue;
        astNode_t *currentNode = createNode(tokens[i]);

        if (strcmp(tokens[i].type, "LABEL") == 0 && inCall) {
            addChild(lastCallNode, currentNode);
            inCall = false;
        } else if (strcmp(tokens[i].type, "LABEL") == 0) {
            addChild(currentParent, currentNode);
            parentStack[++stackTop] = currentNode;
            currentParent = currentNode;
            labelParent = currentNode;
        } else if (strcmp(tokens[i].value, "RET") == 0 || strcmp(tokens[i].value, "END") == 0) {
            addChild(labelParent, currentNode);
            currentParent = parentStack[--stackTop];
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
                    printf("Error: First argument of MOV cannot be VOID.\n");
                } else if (strcmp(firstArg->token.type, "IMMEDIATE") == 0) {
                    printf("Error: First argument of MOV cannot be an IMMEDIATE.\n");
                } else if (strcmp(firstArg->token.type, "REGISTER") != 0 &&
                           strcmp(firstArg->token.type, "ADDRESS_REGISTER") != 0) {
                    printf("Error: First argument of MOV must be a REGISTER or ADDRESS_REGISTER.\n");
                }
                
                // Check the second argument
                astNode_t *secondArg = node->children[1];
                if (strcmp(secondArg->token.type, "VOID") == 0) {
                    printf("Error: Second argument of MOV cannot be VOID.\n");
                }
            }
        } else if (strcmp(node->token.value, "CALL") == 0){
            if (node->numChildren > 1){
                printf("Error : CALL Instruction can only have 1 argument.\n");
            } else {
            }
        } else {
            printf("Error: Unsupported instruction: %s\n", node->token.value);
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