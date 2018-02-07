/*
 *  File:   test-bst.c
 *  Author: Brett Heithold
 *  Description: This is a tester file for the bst module.
 */

#include "integer.h"
#include "bst.h"

int main(void) {

    BST *t = newBST(displayINTEGER, compareINTEGER, NULL, freeINTEGER);
    BSTNODE *root = insertBST(t, newINTEGER(7));
    BSTNODE *left = insertBST(t, newINTEGER(5));
    BSTNODE *right = insertBST(t, newINTEGER(9));
    printf("Left: %d\t", getINTEGER(getBSTNODEvalue(getBSTNODEleft(root))));
    printf("Root: %d\t", getINTEGER(getBSTNODEvalue(getBSTNODEparent(left))));
    printf("Right: %d\n", getINTEGER(getBSTNODEvalue(getBSTNODEright(root))));

    return 0;
}
