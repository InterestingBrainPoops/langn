#pragma once
#include "token.h"
typedef enum
{
    UNARY_OP,
    BINARY_OP,
    VALUE,
} Node_t;

typedef struct Node
{
    Node_t type;
    union
    {
        // BINARY_OP
        struct
        {
            struct Node *left;
            Token_t binary_operator;
            struct Node *right;
        };

        // UNARY_OP
        struct
        {
            struct Node *item;
            Token_t unary_operator;
        };

        // VALUE
        int value;
    };
} Node;

void cleanup_ast(Node *root);