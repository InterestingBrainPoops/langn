#pragma once
#include "stdlib.h"
#include "token.h"
typedef struct
{
    int size;
    int maximum;
    Token *inner;
} Tokens;
Tokens *lex(char *input);

Tokens *new_tokens(int size);

void push_back(Tokens *tokens, Token *item);
void cleanup(Tokens *tokens);
void print_tokens(Tokens *tokens);