/* FIXME : introduce elegant ways to reuse */
#include "swap.c"

typedef int (*cmp_t)(int a, int b);

int compare_gt(int a, int b)
{
    return a > b;
}

int compare_lt(int a, int b)
{
    return a < b;
}

void bubble_sort(List **head, cmp_t cmp)
{
    if (head == NULL || (*head == NULL))
        return;

    int num_list = 0;
    int sub_i;
    List **pre_sub_head = head;
    List *sub_head;

    sub_head = *head;
    for (; sub_head; sub_head=sub_head->next) {
        num_list++;
    }

    for (; num_list > 0; num_list--) {
        sub_head = *head;
        pre_sub_head = head;
        for (sub_i = 1; sub_i < num_list; sub_i++) {
            if(cmp(sub_head->value,sub_head->next->value)) {
                sub_head = swap(sub_head,sub_head,sub_head->next);
                *pre_sub_head = sub_head;
            }
            pre_sub_head = &((*pre_sub_head)->next);
            sub_head = sub_head->next;
        }
    }
    return;
}
