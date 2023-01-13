#include "parser.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool is_at_end(Parser *parser)
{
    return parser->current == parser->tokens->size;
}
Token current(Parser *parser)
{
    return get_at(parser->tokens, parser->current);
}
Token previous(Parser *parser)
{
    return get_at(parser->tokens, parser->current - 1);
}
Token peek(Parser *parser)
{
    return get_at(parser->tokens, parser->current + 1);
}
Token advance(Parser *parser)
{
    parser->current += 1;
    return previous(parser);
}
bool matches(Parser *parser, int n, Token_t pattern[])
{
    if (is_at_end(parser))
    {
        return false;
    }
    for (int x = 0; x < n; x++)
    {
        if (pattern[x] == current(parser).token)
        {
            advance(parser);
            return true;
        }
    }
    return false;
}

Node *primary(Parser *parser)
{
    Node *out = malloc(sizeof(Node));

    switch (current(parser).token)
    {
    case NUMBER:
        out->type = VALUE;
        out->value = advance(parser).value;
        return out;

    default:
        printf("Unreachable code reached\n");
        printf("Reached: ");
        Token temp = current(parser);
        exit(2);
        break;
    }
    return out;
}

Node *unary(Parser *parser)
{
    if (matches(parser, 1, (Token_t[]){HYPHEN}))
    {
        Node *out = malloc(sizeof(Node));

        out->type = UNARY_OP;
        out->item = primary(parser);
        out->unary_operator = previous(parser).token;
    }
    return primary(parser);
}

Node *factor(Parser *parser)
{
    Node *node = unary(parser);
    while (matches(parser, 2, (Token_t[]){STAR, FORWARDSLASH}))
    {
        Node *replace = malloc(sizeof(Node));
        replace->type = BINARY_OP;
        replace->left = node;
        replace->binary_operator = previous(parser).token;
        Token temp = previous(parser);
        replace->right = unary(parser);
        node = replace;
    }
    return node;
}

Node *term(Parser *parser)
{
    Node *node = factor(parser);
    while (matches(parser, 2, (Token_t[]){PLUS, HYPHEN}))
    {
        Node *replace = malloc(sizeof(Node));
        replace->type = BINARY_OP;
        replace->binary_operator = previous(parser).token;
        Token temp = previous(parser);
        replace->left = node;

        replace->right = factor(parser);
        node = replace;
    }
    return node;
}

Node *generate_ast(Parser *parser)
{
    return term(parser);
}
void print_operator(Token_t token)
{
    switch (token)
    {
    case PLUS:
        printf("+");
        break;
    case STAR:
        printf("*");
        break;
    case FORWARDSLASH:
        printf("/");
        break;
    case HYPHEN:
        printf("-");
        break;
    default:
        break;
    }
}

void print_type(Node *node)
{
    switch (node->type)
    {
    case UNARY_OP:
        printf("UNARY_OP");
        break;
    case BINARY_OP:
        printf("BINARY_OP");
        break;
    case VALUE:
        printf("VALUE");
        break;

    default:
        break;
    }
}
void print_ast(Node *node)
{
    switch (node->type)
    {
    case UNARY_OP:
        printf("Unary Operator: \n");

        print_operator(node->unary_operator);

        print_ast(node->item);
        break;
    case BINARY_OP:
        printf("Binary Operator: ");
        print_operator(node->binary_operator);
        printf("\n");
        printf("left: \n");
        print_ast(node->left);
        printf("right: \n");
        print_ast(node->right);
        break;
    case VALUE:
        printf("Value: %d \n", node->value);
        break;
    default:
        break;
    }
}
