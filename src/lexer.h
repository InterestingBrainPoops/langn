#pragma once
#include "token.h"
#include "stdlib.h"
typedef struct {
    int size;
    int maximum;
    enum Token* inner;
} Tokens;
Tokens lex(char* input);

Tokens* new_tokens(int size);

void push_back(Tokens* tokens, Token item);
void cleanup(Tokens* tokens);