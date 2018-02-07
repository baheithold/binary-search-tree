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
    int (*compare)(void *, void *);
    void (*swap)(BSTNODE *, BSTNODE *);
    void (*free)(void *);
};


/*
 *  Constructor: newBST
 *  Usage:  BST *t = newBST(displayINT, compareINT, swapINT, freeINT);
 *  Description: This is the constructor used to instantiate a new
 *  BST object.
 */
BST *newBST(void (*d)(void *, FILE *),
            int (*c)(void *, void *),
            void (*s)(BSTNODE *, BSTNODE *),
            void (*f)(void *)) {
    // TODO: Fix swapper handling
    BST *t = malloc(sizeof(BST));
    t->root = NULL;
    t->size = 0;
    t->display = d;
    t->compare = c;
    t->swap = s;
    t->free = f;
    return t;
}


/*
 *  Method: getBSTroot
 *  Usage:  BSTNODE *root = getBSTroot(t);
 *  Description: This method returns the root NODE of a tree.
 */
BSTNODE *getBSTroot(BST *t) {
    assert(t != NULL);
    return t->root;
}


/*
 *  Method: setBSTroot
 *  Usage:  setBSTroot(t, replacement);
 *  Description: This method updates the root pointer of a BST object. This 
 *  method runs in constant time.
 */
void setBSTroot(BST *t, BSTNODE *replacement) {
    assert(t != 0);
    t->root = replacement;
}


/*
 *  Method: setBSTsize
 *  Usage:  setBSTsize(t, size);
 *  Description: This method sets the size of a BST object.
 */
void setBSTsize(BST *t, int s) {
    assert(t != 0);
    t->size = s;
}


/*
 *  Method: insertBST
 *  Usage:  BSTNODE *n = insertBST(tree, value);
 *  Description:
 */
BSTNODE *insertBST(BST *t, void *value) {
    BSTNODE *n = newBSTNODE(value);
    BSTNODE *p = NULL;
    BSTNODE *x = t->root;
    while (x != NULL) {
        p = x;
        if (t->compare(value, getBSTNODEvalue(x)) < 0) {
            // Traverse left
            x = getBSTNODEleft(x);
        }
        else {
            // Traverse right
            x = getBSTNODEright(x);
        }
    }
    setBSTNODEparent(n, p);
    if (p == NULL) {
        setBSTroot(t, n);
    }
    else if (t->compare(value, getBSTNODEvalue(p)) < 0) {
        // Set the new node to be the left child of p
        setBSTNODEleft(p, n);
    }
    else {
        // Set the new node to be the right child of p
        setBSTNODEright(p, n);
    }
    return n;
}


/*
 *  Method: sizeBST
 *  Usage:  int s = sizeBST(t);
 *  Description: This method returns the number of nodes in a BST object.
 */
int sizeBST(BST *t) {
    assert(t != 0);
    return t->size;
}


/*
 *  Method: statisticesBST
 *  Usage:  statisticsBST(t, stdout);
 *  Description: This method displays the number of nodes in the tree as well
 *  as the minimum and maximum heights of the tree. The minimum depth of a tree
 *  is the minimum number of steps from the root to a node with a NULL child. 
 *  The maximum depth of a tree is the maximum number of steps from the root 
 *  to a node with a NULL child. The depths of an empty tree are -1. 
 *  This method runs in linear time.
 *  Example Output:
 *                  Nodes: 8
 *                  Minimum depth: 2
 *                  Maximum depth: 4
 */
void statisticsBST(BST *t, FILE *fp) {
    assert(t != 0);
    fprintf(fp, "Nodes: %d\n", t->size);
    fprintf(fp, "Minimum depth: IMPLEMENT ME!\n");
    fprintf(fp, "Maximum depth: IMPLEMENT ME!\n");
}


/****************************** Private Methods ******************************/
