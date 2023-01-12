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
void cleanup_tokens(Tokens *tokens);
void print_tokens(Tokens *tokens);

Token get_at(Tokens *tokens, int idx);