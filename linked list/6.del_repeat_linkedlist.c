/*************************************************************************
	> File Name: 6.del_repeat_linkedlist.c
	> Author: 
	> Mail: 
	> Created Time: 五  8/17 20:54:27 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* linkedListUnique(ListNode *head) {
    ListNode *p = head, *q = NULL;
    while (p->next != NULL) {
        if (p->val == p->next->val) { 
        	q = p->next->next;
            free(p->next);
            p->next = q;
        }else{
            p = p->next;
        }
    }
    return head;
}
int main() {
    int n;
    scanf("%d", &n);
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp = head;
    head = head->next;
    free(temp);
    head = linkedListUnique(head);
    temp = head;
    while (head) {
        printf("%d ", head->val);
        head = head->next;
        free(temp);
        temp = head;
    }
    printf("\n");
    return 0;
}
