#pragma once
typedef enum
{
    NUMBER,
    STAR,
    FORWARDSLASH,
    HYPHEN,
    PLUS,
    EMPTY,
} Token_t;

typedef struct
{
    Token_t token;
    union
    {
        int value;
    };

} Token;

Token new_int_token(int number);

void print_token(Token *token);