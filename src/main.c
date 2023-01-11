#include "lexer.h"
#include <stdio.h>
int main()
{

    Tokens *tokens = lex("+/*- 101-3");

    print_tokens(tokens);
}