#include <stdio.h>
#include "lexer.h"
int main() {
    Tokens* x = (Tokens*)malloc(sizeof(Tokens));
    x = new_tokens(3);

    cleanup(x);
}