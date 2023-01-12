#include "parser.h"
#include <stdio.h>
int main()
{

    Tokens *tokens = lex("3+4");

    print_tokens(tokens);

    Parser* parser = malloc(sizeof(Parser));
    parser->current = 0;
    parser->tokens = tokens;


    Node *ast = generate_ast(parser);
    free(parser);
    cleanup_tokens(tokens);
    print_ast(ast);
    cleanup_ast(ast);
}