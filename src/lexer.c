#include "lexer.h"
#include "stdio.h"
#include <stdbool.h>
int ctoi(char x)
{
    switch (x)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;

    default:
        exit(-1);
        break;
    }
}
void print_tokens(Tokens *tokens)
{
    for (int x = 0; x < tokens->size; x++)
    {
        print_token(&tokens->inner[x]);
    }
    printf("\n");
}
bool contains(int size, char *items, char to_check)
{
    for (int x = 0; x < size; x++)
    {
        if (items[x] == to_check)
        {
            return true;
        }
    }
    return false;
}
Tokens *lex(char *input)
{
    // split by spaces
    int idx = 0;

    Tokens *out = new_tokens(30);
    while (input[idx] != '\0')
    {
        Token *token = (Token *)malloc(sizeof(Token));
        token->token = EMPTY;
        bool trip = false;
        switch (input[idx])
        {
        case '+':
            token->token = PLUS;
            idx += 1;
            break;
        case '-':
            token->token = HYPHEN;
            idx += 1;

            break;
        case '/':

            token->token = FORWARDSLASH;
            idx += 1;

            break;
        case '*':

            token->token = STAR;
            idx += 1;

            break;
        case ' ':
            trip = true;
            idx += 1;

            break;
        default:
            /*
            if character is int
                create a storage variable that holds that int
                while character is an int
                    conver it to an integer
                    storage += above * 10;
            */
            if (contains(10, "0123456789", input[idx]))
            {
                int storage = 0;
                while (input[idx] != '\0' && contains(10, "0123456789", input[idx]))
                {
                    storage = storage * 10 + ctoi(input[idx]);
                    idx += 1;
                }
                token->token = NUMBER;
                token->value = storage;
                break;
            }
            else
            {

                trip = true;
                idx += 1;

                break;
            }
            break;
        }
        if (!trip)
        {
            push_back(out, token);
        }
        else
        {
            free(token);
        }
    }

    return out;
}

Tokens *new_tokens(int size)
{
    Tokens *out = (Tokens *)malloc(sizeof(Tokens));
    out->size = 0;
    out->maximum = size;
    out->inner = (Token *)malloc(sizeof(Token) * size);

    return out;
}
void cleanup(Tokens *tokens)
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
}