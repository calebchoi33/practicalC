#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

node *node_make(int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = n->prev = NULL;
    
    return n;
}

node *list_insert(node *prev_node, int value){
    node *new_node = node_make(value);
    new_node-> prev_node = prev_node;
    new_node-> next = prev_node -> next; 
    prev_node-> next = new_node;
    if(new_node -> next != NULL) new_node->next->prev_node = n;
    return new_node;

}

void list_print(const node *head){
    node *current_node = head; 
    for(int i = 0; new_node != NULL;  i++){
        printf("[%d] %d", i, new_node->value);
        new_node = new_node->next;
    }
}

node *list_find(node *head, int value){
    node *current_node = head;
    do{
        if(current_node->value == value){
            return current_node;
        }
        current_node = current_node->next;
    }while(current_node != NULL);

    return NULL;

}

void list_remove(node *n){
    if(n->prev_node == NULL && n->next != NULL){
        n->next->prev = NULL;
    } else if(n->prev != NULL && n->next == NULL){
        n->prev->next = NULL;
    } else if(n-> prev != NULL && n->next != NULL){
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }

    free(n);
}

void list_free(node *head){
    if(head == NULL){
        return;
    }
    Node *n = head->next;
    list_remove(head);
}
