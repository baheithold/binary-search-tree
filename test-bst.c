/*
 *  File:   test-bst.c
 *  Author: Brett Heithold
 *  Description: This is a tester file for the bst module.
 */

#include "integer.h"
#include "bst.h"

int main(void) {

    BSTNODE *n = newBSTNODE(newINTEGER(17));

    freeBSTNODE(n, freeINTEGER);
    return 0;
}
