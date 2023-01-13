#pragma once
typedef enum
{
    // Any integer value (inherently unsigned)
    INTEGER_VALUE,
    // *
    STAR,
    // /
    // /
    FORWARDSLASH,
    // -
    // -
    HYPHEN,
    // +
    // +
    PLUS,
    // placeholder / sentinal value
    // placeholder / sentinal value
    EMPTY,
    // !
    BANG,
    // >
    GREATER_THAN,
    // <
    LESS_THAN,
    // !=
    BANG_EQUAL,
    // >=
    GREATER_THAN_EQUAL,
    // <=
    LESS_THAN_EQUAL,
    // =
    EQUAL,
    // ==
    EQUAL_EQUAL,
    // (
    OPEN_PAREN,
    // )
    CLOSE_PAREN,
} Token_t;

typedef struct
{
    Token_t token;
    union
    {
        int value;
    };

} Token;

void print_token(Token *token);