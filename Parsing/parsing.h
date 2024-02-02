#ifndef PARSING_H
#define PARSING_H
#include "token.h"


typedef struct node
{
    token_t tokens;
    struct node *left;
    struct node *right;
}node_t;

node_t* newNode(token_t token) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->tokens = token;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t* createTree(token_t* tokens, int numTokens) {
    if (numTokens == 0) {
        return NULL;
    }

    node_t* root = newNode(tokens[0]);

    // Create left and right subtrees from the rest of the tokens
    root->left = createTree(tokens + 1, numTokens / 2);
    root->right = createTree(tokens + numTokens / 2 + 1, numTokens - numTokens / 2 - 1);

    return root;
}

void printNode(node_t* node) {
    if (node == NULL) {
        return;
    }

    printf("Token: %s \t %s \t %d \t %d \n", node->tokens.type, node->tokens.value, node->tokens.row, node->tokens.column);
    
    printNode(node->left);
    
    printNode(node->right);
}



#endif






