#include "ast.h"
#include "stdlib.h"
void cleanup_ast(Node* root) {
    switch (root->type)
    {
    case UNARY_OP:
        cleanup_ast(root->item);
        free(root);
        break;
    case BINARY_OP:
        cleanup_ast(root->left);
        cleanup_ast(root->right);
        free(root);
        break;
    case VALUE:
        free(root);
    default:
        break;
    }
}