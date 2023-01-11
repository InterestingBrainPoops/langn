#ifndef LEXER
#define LEXER
#include "token.h"
#include "stdlib.h"
typedef struct {
    int size;
    int maximum;
    Token* inner;
} Tokens;

struct Tokens lex(char* input);

struct Tokens* new_tokens(int size) {
    struct Tokens out = 
    return *Tokens {
        0,
        size,
        (Tokens*)malloc(size * sizeof(Token))

    };
}

void push_back(struct Tokens* tokens, Token item) {
    // if 
}
#endif