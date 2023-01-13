#pragma once
#include "lexer.h"
#include "ast.h"
typedef struct
{
    int current;
    Tokens *tokens;
} Parser;

Node *generate_ast(Parser *parser);

void print_ast(Node *node);
void print_operator(Token_t token);