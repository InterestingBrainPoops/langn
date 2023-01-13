#include "tokens.h"
#include "stdlib.h"
#include <stdio.h>
Tokens *new_tokens(int size)
{
    Tokens *out = (Tokens *)malloc(sizeof(Tokens));
    out->size = 0;
    out->maximum = size;
    out->inner = (Token *)malloc(sizeof(Token) * size);

    return out;
}
void cleanup_tokens(Tokens *tokens)
{
    free(tokens->inner);
    free(tokens);
}

void push_back(Tokens *tokens, Token *item)
{
    if (tokens->size == tokens->maximum)
    {
        tokens->maximum += 10;
        tokens->inner = realloc(tokens->inner, tokens->maximum + 10);
        if (tokens->inner == NULL)
        {
            perror("push_back failed on resize");
            exit(2);
        }
    }
    tokens->inner[tokens->size] = *item;
    tokens->size += 1;
    free(item);
}