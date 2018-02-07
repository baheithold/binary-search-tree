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

    printf("Finding a node...\n");
    BSTNODE *n = findBST(t, newINTEGER(9));
    if (n != NULL) {
        printf("The value of the node is %d\n", getINTEGER(getBSTNODEvalue(n)));
    }
    else printf("The value was not found!\n");

    return 0;
}
