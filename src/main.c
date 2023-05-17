#include <stdio.h>
#include "llist.h"

int main(void) {
    node_t* begin = NULL;

    list_insert_ord(&begin, 10);
    list_insert_ord(&begin, 100);
    list_insert_ord(&begin, 10);
    list_insert_ord(&begin, 2);
    list_insert(&begin, 10);
    list_insert(&begin, 34);
    list_insert(&begin, 10);
    list_insert(&begin, 4);
    list_insert(&begin, 10);

    list_print(begin);
    printf("===\n");

    list_insert_at(&begin, 3, 66);
    list_insert_at(&begin, 0, 0);
    list_pop(&begin);
    printf("After insert at 3 and 0, and pop:\n");
    list_print(begin);
    list_remove(&begin, 10);
    list_remove(&begin, 0xFFF);
    printf("After remove <10> and remove inexistent element:\n");
    list_print(begin);
    list_remove_all(&begin, 10);
    printf("After removing all <10>:\n");
    list_print(begin);

    return 0;
}
