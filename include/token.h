#pragma once
typedef enum
{
    NUMBER,
    // *
    STAR,
    // /
    FORWARDSLASH,
    // -
    HYPHEN,
    // +
    PLUS,
    // placeholder / sentinal value
    EMPTY,
    BANG,
    GREATERTHAN,
    LESSTHAN,
    BANGEQUAL,
    GREATERTHANEQUAL,
    LESSTHANEQUAL,
    EQUAL,
    EQUALEQUAL
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