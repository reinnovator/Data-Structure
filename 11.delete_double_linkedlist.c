/*************************************************************************
	> File Name: 11.delete_double_linkedlist.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 12:42:35 2018
 ************************************************************************/
 //删除重复元素
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
ListNode *deleteValNode(ListNode *head, int val) {
    if (head == NULL) return NULL;
    ListNode *virtualHead = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p, *q;
    virtualHead->next = head;
    virtualHead->pre = NULL;
    head->pre = virtualHead;
    p = head;
    while (p) {
        if (p->val == val) {
            if (p->next != NULL) {
                p->next->pre = p->pre;
            }
            p->pre->next = p->next;
            q = p;
            p = p->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    head = virtualHead->next;
    if (head != NULL) {
        head->pre = NULL;
    }
    free(virtualHead);
    return head;
}
ListNode* twoWayLinkListUnique(ListNode *head) {
     if (head == NULL) return NULL;
    ListNode *p, *q;
    p = head;
    while (p) {
        q = deleteValNode(p->next, p->val);
        if (q != NULL) {
            q->pre = p;
        }
        p->next = q;
        p = p->next;
    }
    return head;
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
        temp->next->pre = temp;
        temp = temp->next;
    }
    temp = head;
    head = head->next;
    head->pre = NULL;
    free(temp);
    head = twoWayLinkListUnique(head);
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
