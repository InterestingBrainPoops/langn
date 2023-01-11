#include "lexer.h"
Tokens lex(char* input) {
    // split by spaces
    int idx = 0;
    Token* out = malloc(sizeof(Token) * 10);
    while (input[idx] != 0) {
        switch (input[idx])
        {
        case '+':
            
            break;
        
        default:
            break;
        }
    }
    
}

Tokens* new_tokens(int size) {
    Tokens* out = (Tokens*)malloc(sizeof(Tokens));
    out-> size = 0;
    out-> maximum = size;
    out-> inner = (enum Token*)malloc(sizeof(Token) * size);

    return out;
}
void cleanup(Tokens* tokens) {
    free(tokens->inner);
    free(tokens);
}
void push_back(Tokens* tokens, Token item) {

}