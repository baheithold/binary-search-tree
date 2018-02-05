/*
 *  File:   bst.c
 *  Author: Brett Heithold
 *  Description: This is the implementation file for the bst(binary search tree)
 *  module.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"


/*
 *  Type:   BSTNODE
 *  Description: This is the node structure to be used in the BST class.
 */
struct BSTNODE {
    void *value;
    BSTNODE *left;
    BSTNODE *right;
    BSTNODE *parent;
};


/*
 *  Constructor: newBSTNODE
 *  Usage:  BSTNODE *n = newBSTNODE(value);
 *  Description: This is the constructor used to instantiate a new
 *  BSTNODE object.
 */
BSTNODE *newBSTNODE(void *v) {
    BSTNODE *n = malloc(sizeof(BSTNODE));
    assert(n != 0);
    n->value = v;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}


/*
 *  Method: getBSTNODEvalue
 *  Usage:  void *v = getBSTNODEvalue(n);
 *  Description: This method returns the value held by a BSTNODE object.
 */
void *getBSTNODEvalue(BSTNODE *n) {
    assert(n != 0);
    return n->value;
}


/*
 *  Method: setBSTNODEvalue
 *  Usage:  setBSTNODEvalue(n, v);
 *  Description: This method sets the value held by a BSTNODE object.
 */
void setBSTNODEvalue(BSTNODE *n, void *value) {
    assert(n != 0);
    n->value = value;
}


/*
 *  Method: getBSTNODEleft
 *  Usage:  BSTNODE *left = getBSTNODEleft(n);
 *  Description: This method returns the left pointer of a BSTNODE.
 */
BSTNODE *getBSTNODEleft(BSTNODE *n) {
    assert(n != 0);
    return n->left;
}


/*
 *  Method: setBSTNODEleft
 *  Usage:  setBSTNODEleft(n);
 *  Description: This method sets the left pointer of a BSTNODE.
 */
void setBSTNODEleft(BSTNODE *n, BSTNODE *replacement) {
    assert(n != 0);
    n->left = replacement;
}


/*
 *  Method: getBSTNODEright
 *  Usage:  BSTNODE *right = getBSTNODEright(n);
 *  Description: This method returns the right pointer of a BSTNODE.
 */
BSTNODE *getBSTNODEright(BSTNODE *n) {
    assert(n != 0);
    return n->right;
}


/*
 *  Method: setBSTNODEright
 *  Usage:  setBSTNODEright(n);
 *  Description: This method sets the right pointer of a BSTNODE.
 */
void setBSTNODEright(BSTNODE *n, BSTNODE *replacement) {
    assert(n != 0);
    n->right = replacement;
}


/*
 *  Method: getBSTNODEparent
 *  Usage:  BSTNODE *parent = getBSTNODEparent(n);
 *  Description: This method returns the parent pointer of a BSTNODE.
 */
BSTNODE *getBSTNODEparent(BSTNODE *n) {
    assert(n != 0);
    return n->parent;
}


/*
 *  Method: setBSTNODEparent
 *  Usage:  setBSTNODEparent(n);
 *  Description: This method sets the parent pointer of a BSTNODE.
 */
void setBSTNODEparent(BSTNODE *n, BSTNODE *replacement) {
    assert(n != 0);
    n->parent = replacement;
}


/*
 *  Method: freeBSTNODE
 *  Usage:  freeBSTNODE(n, freeINTEGER);
 *  Description: If the freeing function is not NULL, then the method should
 *  free its generic value before freeing the node itself.
 */
void freeBSTNODE(BSTNODE *n, void (*free)(void *)) {
    // TODO: Do I work correctly?
    assert(n != 0); // TODO: Should I assert here?
    if (free != NULL) {
        free(n->value);
    }
    free(n);
}


/*
 *  Type:   BST
 *  Description: This is the struct definition for the BST class.
 */
struct BST {
    BSTNODE *root;
    int size;
    
    // Public Methods
    void (*display)(void *, FILE *);
    int (*comparator)(void *, void *);
    void (*swapper)(BSTNODE *, BSTNODE *);
    void (*free)(void *);
};


BST *newBST(void (*d)(void *, FILE *),
            int (*c)(void *, void *),
            void (*s)(BSTNODE *, BSTNODE *),
            void (*f)(void *)) {
    BST *b = malloc(sizeof(BST));
    b->root = NULL;
    b->size = 0;
    b->display = d;
    b->comparator = c;
    b->swapper = s;
    b->free = f;
}


/****************************** Private Methods ******************************/
