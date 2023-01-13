#include "token.h"
#include "stdio.h"
void print_token(Token *token)
{
    printf("Token { token:");
    switch (token->token)
    {
    case PLUS:
        printf("PLUS");
        break;
    case FORWARDSLASH:
        printf("FORWARDSLASH");
        break;
    case HYPHEN:
        printf("HYPHEN");
        break;
    case INTEGER_VALUE:
        printf("NUMBER, Value: %d", token->value);
        break;
    case STAR:
        printf("STAR");
        break;
    case EMPTY:
        printf("EMPTY");
        break;
    default:
        break;
    }
    printf(" }\n");
}

Token new_int_token(int number)
{
    Token out;
    out.token = INTEGER_VALUE;
    out.value = number;
    return out;
}