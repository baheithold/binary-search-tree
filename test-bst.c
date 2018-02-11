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
    root = insertBST(t, newINTEGER(4));
    root = insertBST(t, newINTEGER(10));
    root = insertBST(t, newINTEGER(2));
    root = insertBST(t, newINTEGER(5));
    root = insertBST(t, newINTEGER(9));
    root = insertBST(t, newINTEGER(12));
    root = insertBST(t, newINTEGER(8));

    displayBSTdebug(t, stdout);
    printf("Swapping...\n");
    BSTNODE *leaf = swapToLeafBST(t, getBSTroot(t));
    displayBSTdebug(t, stdout);

    freeBST(t);
    return 0;
}
