/*************************************************************************
	> File Name: 5.sort_linkedlist.c
	> Author: 
	> Mail: 
	> Created Time: 五  8/17 20:44:05 2018
 ************************************************************************/
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
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
ListNode* linkedListSort(ListNode *head) {
    ListNode *current_node ;
    ListNode *end = NULL;
    while(head != end) {
        current_node = head;
        while(current_node->next != end ) {
        if (current_node->val > current_node->next->val) { 
        	current_node->val ^= current_node->next->val;
            current_node->next->val ^= current_node->val;
            current_node->val ^= current_node->next->val;
        }
        	current_node = current_node->next;
    	}
    		end = current_node; 
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
        temp = temp->next;
    }
    temp = head;
    head = head->next;
    free(temp);
    head = linkedListSort(head);
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
