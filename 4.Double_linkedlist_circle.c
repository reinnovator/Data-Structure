/*************************************************************************
	> File Name: 4.Double_linkedlist_circle.c
	> Author: 
	> Mail: 
	> Created Time: 五  8/17 16:54:20 2018
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prior;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        head->next = head;
        //node->prior = NULL;
        return head;
    }
    if (index == 0) {
        node->next = head->next;//head:尾节点，head->next:头节点
		//head->next->prior = node;
        head->next = node;
        //node->prior = NULL;
        return head;
    }
    Node *current_node = head->next;
    int count = 0;
    while (current_node != head && count < index - 1) {//尾节点前一个节点
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
         //node->prior = NULL;
    }
   
    if(node == head->next){
        head = node;
    }
    //node->prior = NULL;
    return head;
}

LinkedList build(LinkedList head) {//构建双向链表
    if (head == NULL) {
        return head;
    }
    Node *prior_node = head;
    Node *current_node = head->next;
   do{
        current_node->prior = prior_node; 
       //  printf("%d\n", current_node->prior->data);
       current_node = current_node->next;
     
        prior_node = prior_node->next;
    }  while (current_node != head->next);//do while 很重要
    return head;
}
void output(LinkedList head, int m){
   	Node *current_node = head;
	while (current_node->data != m) {
        current_node = current_node->next;
    }
    Node *prior_node = current_node;
    printf("%d",prior_node->data);
    prior_node = prior_node->prior;

    while(prior_node != current_node){
        printf(" %d",prior_node->data);
        prior_node = prior_node->prior;
    }
    printf("\n");
    return;
}
int main(){
    LinkedList linkedlist = NULL;
    int num;
    int a;
    int index;
    scanf("%d\n", &num);
    for(int i = 1; i <= num; i++) {
        scanf("%d", &a);
        Node *node =(Node *)malloc(sizeof(Node));
        node->data = a;
        node->next = NULL;
       // node->prior = NULL;
        linkedlist = insert(linkedlist, node, i - 1 );
      
    }
    
    linkedlist = build(linkedlist);
    scanf("%d", &index);
    output(linkedlist, index);
    return 0;
}



