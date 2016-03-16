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

    int pre_num = 0;

    List *pre_node_1 = 0,*pre_node_2 = 0,*tmp_node;

    for(List *cur = head; cur; cur=cur->next) {
        if (cur->next == node_1) {
            pre_node_1 = cur;
            pre_num++;
        } else if (cur->next == node_2) {
            pre_node_2 = cur;
            pre_num++;
        }
    }

    if (pre_num != 2) {
        if (head == node_1) {
            pre_node_1 = NULL;
            pre_num++;
        } else if (head == node_2) {
            pre_node_2 = NULL;
            pre_num++;
        }
        if (pre_num!=2) return head;
    }

    if (pre_node_1 == NULL) {
        pre_node_2->next = node_1;
        NODE_SWAP(tmp_node, node_2->next, node_1->next);
        return node_2;
    } else if(pre_node_2 == NULL) {
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
