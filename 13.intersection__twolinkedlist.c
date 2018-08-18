/*************************************************************************
	> File Name: 13.intersection__twolinkedlist.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 14:14:10 2018
 ************************************************************************/
//找出两个链表的交点
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
ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
	ListNode *p, *q;
    int cnt[2];
	 cnt[0] = getlength(head1);
     cnt[1] = getlength(head2);
    int d = abs(cnt[0] - cnt[1]);
    if(cnt[0] > cnt[1]){
        p = head1;
        q = head2;
    }else{
        p = head2;
        q = head1;
    }
    while(d--){
        p = p->next;
    }
    while(p && p->next) {
        p = p->next;
        q = q->next;
        if(p == q)return p;
    }
    return NULL;
}
int getlength(ListNode *head){
    ListNode *p = head;
    if(!p)return 0;
    int cnt = 1;
    while(p->next != NULL) {
        p = p->next;
        cnt++;
    }
    return cnt;
}
int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    ListNode *ans = NULL;
    for (int i = 0; i < n; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
        if (i == x) {
            ans = temp;
        }
    }
    temp = head;
    head = head->next;
    free(temp);
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->val = 0;
    head2->next = NULL;
    temp = head2;
    for (int i = 0; i < m; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp->next = ans;
    temp = head2;
    head2 = head2->next;
    free(temp);
    temp = findIntersectionListNode(head, head2);
    if(temp == ans) {
        printf("Accept\n");
    } else {
        printf("Wrong answer\n");
    }
    return 0;
}
