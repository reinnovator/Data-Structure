/*************************************************************************
	> File Name: 21-合并两个有序链表.c
	> Author: 
	> Mail: 
	> Created Time: 六  9/ 8 14:06:03 2018
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode p ;   
    struct ListNode *temp = &p;
        
        while(l1&&l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{      
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
            temp->next = l1 ? l1 : l2;
        
        return p.next;
}

