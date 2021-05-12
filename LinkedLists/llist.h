#ifndef _LLIST_H
#define _LLIST_H


#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

// Makes a new node with the given value and NULL
// next and prev pointers.
node *node_make(int value);


// Your other function prototypes go here, between
// the #ifndef and the #endif.


#endif
