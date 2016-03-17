#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"

List *recursive_sort(List *left, cmp_t cmp)
{
    if(!left->next) return left;

    List *right = left;
    List *pre_right = left;
    List *next_node = 0;
    List *head = 0;
    List *link = 0;

    for(List *sub_head = left;
            sub_head && sub_head->next;
            sub_head = sub_head->next->next) {

        pre_right = right;
        right = right->next;
    }

    pre_right->next = NULL; //sperate to two list

    left  = recursive_sort(left, cmp);
    right = recursive_sort(right, cmp);

    while(left && right) {
        if(cmp(left->value ,right->value)) {
            next_node = left;
            left = left->next;
        } else {
            next_node = right;
            right = right->next;
        }
        if(head) link->next = next_node;
        else head = next_node;
        link = next_node;
    }

    link->next = left ? left : right;

    return head;
}

void merge_sort(List **head, cmp_t cmp)
{
    if (head == NULL || (*head == NULL))
        return;

    *head = recursive_sort(*head, cmp);

    return;
}
