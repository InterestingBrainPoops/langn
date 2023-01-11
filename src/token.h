#pragma once

typedef enum {
    NUMBER,
    STAR,
    BACKSLASH,
    HYPHEN,
    PLUS
} Token_t;

typedef struct {
    Token_t token;
    union
    {
        int value;
    };
    
} Token;