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
        if (strcmp(tokens[i].type, "VOID") == 0) continue;
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

void labelLastChild(astNode_t* node)
{
    int i = node->numChildren-1;
    int trig = 0;
    if(strcmp(node->children[i]->token.value,"RET")== 0 ||strcmp(node->children[i]->token.value,"END")== 0)
    {
        for(int j; j<= node->numChildren; i++)
        {
            char* last = node->children[i]->token.value;
            if(strcmp(node->children[i]->token.value,"END")== 0 && strcmp(node->children[j]->token.value,"CALL") ==0)
            {
                trig++;
            }
            else if (j == i-1 && trig == 0 )
            {
                printf("error line %d: END token must has a CALL token on the same LABEL\n",node->children[i]->token.row);
            }
        }
    
    }
    else
    {
        printf("error line %d: LABEL must finish with RET or END token\n",node->children[i]->token.row);
    }
}

// Traverse the AST to check the syntax
void checkSyntax(astNode_t* node) 
{
    // If the node is NULL, return
    if (node == NULL) 
    {
        return;
    }
    // Check the syntax of current node and of the children of the current node
    for(int i = 0; i < node->numChildren; i++)
    {
        // c=child, p=parent
        char* pType = node->token.type; // parent node type
        char* pValue = node->token.value; // parent node value
        int pNumb = node->numChildren; // parent node number of children
        char* cType = node->children[i]->token.type; // child node type
        char* cValue = node->children[i]->token.value; // child node value
        int cNumb = node->children[i]->numChildren; // child node number of children
        
        if (strcmp(pType,"ROOT")== 0 && pNumb >=0)
        {
            if (strcmp(cType,"LABEL")== 0 ||strcmp(cType,"INSTRUCTION")== 0)
            {
                
            }
            else
            {
                printf("error line %d: invalide ROOT syntax\n",node->children[i]->token.row);
            }
        }
        else if (strcmp(pType,"LABEL")== 0 && pNumb >=1)
        {
            if (strcmp(cType,"LABEL")==0||strcmp(cType,"INSTRUCTION")==0)
            {
                labelLastChild(node);
            }
            else
            {
                printf("error line %d: invalide LABEL syntax\n",node->children[i]->token.row);
            }
        }

    }
    for(int i = 0; i < node->numChildren; i++)
    {
        checkSyntax(node->children[i]);
    }
}