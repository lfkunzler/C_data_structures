#ifndef __INC_LLIST_H

#include <stdint.h>

typedef struct node_t {
    int data;
    struct node_t* next;
} node_t;

int list_insert(node_t** begin, int data); /* insert at given pos */
int list_push(node_t** begin, int data); /* insert at last pos */
int list_insert_ord(node_t** begin, int data); /* ordenated insert */
int list_insert_at(node_t** begin, uint32_t pos, int data); /* insert at given pos */
void list_print(node_t* begin); /* print list */
void list_print_rev(node_t* begin); /* print list backwards */
int list_shift(node_t** begin); /* remove 1st element */
int list_pop(node_t** begin); /* remove last element */
int list_remove(node_t** begin, int data); /* remove 1st occurrence of a given element */
void list_remove_all(node_t** begin, int data); /* remove all occurrences of a given element */
#endif /* !__INC_LLIST_H */
