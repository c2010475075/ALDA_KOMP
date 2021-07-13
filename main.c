//
//  main.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//


#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include <stdbool.h>


int main(){
    struct node *start = NULL;


    /* Constructing tree given in the above figure */
    start = insertNode(start, 3,"f" );
    start = insertNode(start, 2,"f" );
    start = insertNode(start, 1,"f" );
    start = insertNode(start, 10,"f" );
    start = insertNode(start, 15,"f" );

    // test your implementation here
    // no test cases will be provided this time!
    preOrder(start);
}
