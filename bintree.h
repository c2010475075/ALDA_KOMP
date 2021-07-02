//
//  bintree.h
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#ifndef bintree_h
#define bintree_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_ {
    int key;
    char *data;
    struct node_ *left;
    struct node_ *right;
} node;

typedef struct binTree_ {
    int size;
    node *root;
} binTree;

// Funktionsprototypen

binTree *t_init(void);
node *insertNode(node *, int, const char *);
node *insert(binTree *, int, const char *);
int treeDepth(node *);

// TODO: Rotationsprototypen

#endif /* bintree_h */
