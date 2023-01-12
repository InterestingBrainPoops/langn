#include "parser.h"
#include <stdbool.h>
bool is_at_end(Parser *parser)
{
    return parser->current == parser->tokens->size - 1;
}
Token current(Parser *parser)
{
    return parser->tokens->inner[parser->current];
}
Token previous(Parser *parser)
{
    return parser->tokens->inner[parser->current - 1];
}
Token peek(Parser *parser)
{
    return parser->tokens->inner[parser->current + 1];
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

    switch (peek(parser).token)
    {
    case NUMBER:
        out->type = VALUE;
        out->value = advance(parser).value;
        return out;

    default:
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
        replace->right = unary(parser);
        replace->binary_operator = previous(parser).token;
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
        replace->left = node;
        replace->right = factor(parser);
        replace->binary_operator = previous(parser).token;

        node = replace;
    }
    return node;
}

Node *generate_ast(Parser *parser)
{
    return term(parser);
}
