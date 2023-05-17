#include "llist.h"
#include <stdlib.h>
#include <stdio.h>

int list_insert(node_t** begin, int data)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    printf("new node :: %p\n", (void*)new_node);
    if (new_node == NULL) return -1;

    new_node->data = data;
    new_node->next = *begin;
    *begin = new_node;
    return 0;
}

int list_push(node_t** begin, int data)
{
    if (*begin == NULL) {
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        if (new_node == NULL) return -1;

        new_node->data = data;
        new_node->next = NULL;
        *begin = new_node;

        return 0;
    } else {
        return list_push(&(*begin)->next, data);
    }
}

int list_insert_ord(node_t** begin, int data)
{
    if (*begin == NULL) return list_insert(begin, data);

    if ((*begin)->data > data) return list_insert(begin, data);

    return list_insert_ord(&(*begin)->next, data);
}

int list_insert_at(node_t **begin, uint32_t pos, int data)
{
    if (*begin == NULL || pos == 0) return list_insert(begin, data);

    return list_insert_at(&(*begin)->next, pos-1, data);
}

int list_shift(node_t** begin) /* remove 1st element */
{
    node_t* aux = *begin;

    if (*begin == NULL) return -1;

    *begin = (*begin)->next;
    free(aux);

    return 0;
}

int list_pop(node_t** begin) /* remove last element */
{
    if (*begin == NULL) return -1;
    if ((*begin)->next == NULL) {
        free(*begin);
        *begin = NULL;
        return 0;
    }
    return list_pop(&(*begin)->next);
}

int list_remove(node_t** begin, int data)
{
    node_t* curr = *begin;
    if (curr == NULL) return -1;
    if (curr->data != data) return list_remove(&curr->next, data);

    *begin = curr->next;
    free(curr);
    return 0;
}

void list_remove_all(node_t** begin, int data)
{
    node_t* curr = *begin;
    if (curr == NULL) return;
    if (curr->data != data) {
        list_remove_all(&curr->next, data);
    } else {
        *begin = curr->next;
        free(curr);
        list_remove_all(begin, data);
    }
}

void list_print(node_t* begin)
{
    if (begin == NULL) return;
    printf("data :: %d\n", begin->data);
    list_print(begin->next);
}

void list_print_rev(node_t* begin)
{
    if (begin == NULL) return;
    list_print_rev(begin->next);
    printf("data :: %d\n", begin->data);
}
