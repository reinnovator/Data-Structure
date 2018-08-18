/*************************************************************************
	> File Name: 10.reverse_double_linkedlist.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 12:23:06 2018
 ************************************************************************/
//双向链表翻转
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *pre;
    struct Node *next;
} ListNode;
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *pre;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* reverseLinkedList(ListNode *head) {
    ListNode *p, *q = head;
    while(1) {
        p = q->next;
        q->next = q->pre;
        q->pre = p;
        if(q->pre == NULL)break;
        q = q->pre;
    }
    return q;
}
int main() {
    int n;
    scanf("%d", &n);
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    head->pre = NULL;
    ListNode *temp = head;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp->next->pre = temp;
        temp = temp->next;
    }
    temp = head;
    head = head->next;
    head->pre = NULL;
    free(temp);
    head = reverseLinkedList(head);
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
