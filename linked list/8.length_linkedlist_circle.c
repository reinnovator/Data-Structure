/*************************************************************************
	> File Name: 8.length_linkedlist_circle.c
	> Author: 
	> Mail: 
	> Created Time: 五  8/17 22:08:20 2018
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
int linkedListCycleLength(ListNode *head) {
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
    return cnt;
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
    printf("%d\n", linkedListCycleLength(head));
    return 0;
}
