/*************************************************************************
	> File Name: 9.crosspoint_linkedlist_circle.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 11:31:07 2018
 ************************************************************************/
 //求出单链表中环的链接点
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
ListNode* linkedListCycleLinkedNode(ListNode *head) {
    ListNode *p = head, *q = head;
    while (p && p->next) {
        p = p->next->next;
        q = q->next;
        if(p == q)break;
    }
    int cnt = 0;
    if(p != q) return 0;
    do{
        p = p->next;
        cnt++;
    }while(p != q);
    p = q = head;
    while (cnt--) {
        q = q->next;
    }
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}
int main() {
    int n;
    scanf("%d", &n);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
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
    int d;
    scanf("%d", &d);
    ListNode *Nth = head;
    while (d--) {
        Nth = Nth->next;
    }
    temp->next = Nth;
    temp = head;
    head = head->next;
    free(temp);
    ListNode *node = linkedListCycleLinkedNode(head);
    if (!node) {
        printf("No cycle\n");
    } else {
        printf("%d\n", node->val);
    }
    return 0;
}
