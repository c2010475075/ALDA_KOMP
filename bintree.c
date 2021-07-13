//
//  bintree.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//


#include "bintree.h"

binTree *t_init(){
    binTree *tmp = (binTree *)malloc(sizeof(binTree));
    tmp->root = NULL;
    tmp->size = 0;
    return tmp;
}

node*rightRotate(node*y){
    node *x = y->left;
    node *T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    // Update heights
    y->bk = max(height(y->left), height(y->right))+1;
    x->bk = max(height(x->left), height(x->right))+1;


    return x;
}


node *leftRotate(node *x)
{
    node *y = x->right;
    node *T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    //  Update heights
    x->bk = max(height(x->left), height(x->right))+1;
    y->bk = max(height(y->left), height(y->right))+1;


    return y;
}
int height(node *start)
{
    if (start == NULL)
        return 0;
    return start->bk;
}
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int getBalance(node *start)
{
    if (start == NULL)
        return 0;
    return height(start->left) - height(start->right);
}

// TODO: double pointer einführen oder über return Werte lösen
node *insertNode(node *start, int key, const char *data){
    node *newNode;
    if (start == NULL) {
        newNode = (node *) malloc(sizeof(node));

        if (newNode != NULL) {
            newNode->data = (char*) malloc(strlen(data)+1);
            strcpy(newNode->data, data);
            newNode->key = key;
            newNode->right = newNode->left = NULL;
            newNode->bk = 1;
        }
        return newNode;
    }


    if (key < start->key) {
        start-> left = insertNode(start->left, key, data);

    } else {
       start->right = insertNode(start->right, key, data);

    }
   start->bk = 1 + max(height(start->left),
                       height(start->right));
    int balance=getBalance(start);

    if (balance > 1 && key < start->left->key)
        return rightRotate(start);

    // Right Right Case
    if (balance < -1 && key > start->right->key)
        return leftRotate(start);

    // Left Right Case
    if (balance > 1 && key > start->left->key)
    {
        start->left =  leftRotate(start->left);
        return rightRotate(start);
    }

    // Right Left Case
    if (balance < -1 && key < start->right->key)
    {
        start->right = rightRotate(start->right);
        return leftRotate(start);
    }



    return start;

}



node *insert(binTree *t, int key, const char *data){
    node *newNode;
    newNode = insertNode(t->root, key, data);
    if (t->root == NULL) t->root = newNode;
    if (newNode != NULL) t->size++;
    return newNode;
}



int treeDepth(node *start){
    if (start == NULL) {
        return 0;
    }
    else {
        return 1 +  max(treeDepth(start->left),
                        treeDepth(start->right));
    }
}
void preOrder(node *start)
{
    if(start != NULL)
    {
        printf("%d ", start->key);
        preOrder(start->left);
        preOrder(start->right);
    }
}
//start->bk = treeDepth(start->right) - treeDepth(start->left);

//quellen:https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/
// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
//https://www.guru99.com/avl-tree.html