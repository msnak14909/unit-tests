#include <stdio.h>
#include <stdlib.h>
#define NODE_SWAP(a,b,c) { (a)=(b);(b)=(c);(c)=(a); }

typedef struct List_node {
    int value;
    struct List_node *next;
} List;

List *swap(List *head, List *node_1, List *node_2)
{
    // limitation
    if (!head ||
            (node_1 == NULL) || (node_2 == NULL) ||
            (node_1 == node_2))
        return head;

    List *pre_node_1 = 0,*pre_node_2 = 0,*tmp_node;

    for(List *cur = head; cur; cur=cur->next) {
        if (cur->next == node_1) {
            pre_node_1 = cur;
        } else if (cur->next == node_2) {
            pre_node_2 = cur;
        }
    }

    if (pre_node_1 == NULL) {
        if(head != node_1 || !pre_node_2) return head;
        pre_node_2->next = node_1;
        NODE_SWAP(tmp_node, node_2->next, node_1->next);
        return node_2;
    } else if(pre_node_2 == NULL) {
        if(head != node_2 || !pre_node_1) return head;
        pre_node_1->next = node_2;
        NODE_SWAP(tmp_node, node_2->next, node_1->next);
        return node_1;
    } else {
        pre_node_1->next = node_2;
        pre_node_2->next = node_1;
        NODE_SWAP(tmp_node, node_2->next, node_1->next);
        return head;
    }
}
