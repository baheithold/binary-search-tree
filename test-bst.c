/*
 *  File:   test-bst.c
 *  Author: Brett Heithold
 *  Description: This is a tester file for the bst module.
 */

#include "integer.h"
#include "bst.h"

int main(void) {

    BSTNODE *n = newBSTNODE(newINTEGER(2));
    setBSTNODEleft(n, newBSTNODE(newINTEGER(1)));
    setBSTNODEright(n, newBSTNODE(newINTEGER(3)));
    fprintf(stdout, "Left: %d\n", getINTEGER(getBSTNODEvalue(getBSTNODEleft(n))));
    fprintf(stdout, "Center: %d\n", getINTEGER(getBSTNODEvalue(n)));
    fprintf(stdout, "Right: %d\n", getINTEGER(getBSTNODEvalue(getBSTNODEright(n))));

    freeBSTNODE(n, freeINTEGER);
    return 0;
}
