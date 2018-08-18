/*************************************************************************
	> File Name: 12.merge_twolinkedlist.c
	> Author: 
	> Mail: 
	> Created Time: 六  8/18 13:25:14 2018
 ************************************************************************/
//合并两个有序链表
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
ListNode* mergeTwoSortedLinkList(ListNode *head1, ListNode *head2) {
    ListNode *p[2], *q;
    ListNode *vir = (ListNode *)malloc(sizeof(ListNode));
	q = vir;//创建虚拟节点便于返回头节点
    p[0] = head1;
    p[1] = head2;
    int ind;
    while(p[0]|| p[1] != NULL){
        if(p[0] == NULL){ ind = 1;}
        else if(p[1] == NULL){ ind = 0;}
        else{
           ind = (p[0]->val < p[1]->val ? 0 : 1);   
        }
        q->next = p[ind];
        p[ind] = p[ind]->next;
        q = q->next;
       // q->next = NULL;
    }
 	q = vir->next;
    free(vir);
    return q;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
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
    temp = head;
    head = head->next;
    free(temp);
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->val = 0;
    head2->next = NULL;
    temp = head2;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp = head2;
    head2 = head2->next;
    free(temp);
    head = mergeTwoSortedLinkList(head, head2);
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
