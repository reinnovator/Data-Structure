/*************************************************************************
	> File Name: 1.vector.c
	> Author: 
	> Mail: 
	> Created Time: 五  8/17 11:14:03 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
      vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; ++i) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

 insert(Vector *vector, int loc, int value) {
      if (loc < 0 || loc > vector->length) {
            printf("failed\n");
          return ;
    }
    if (vector->length >= vector->size) {
        //return ERROR;
        expand(vector);
    }
    for (int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
     printf("success\n");
    return ;
 }

 search(Vector *vector, int value) {
     for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
            printf("success\n");
            return ;
        }
    }
     printf("failed\n");
    return ;
 }

 delete_node(Vector *vector, int index) {
        if (index < 0 || index >= vector->length) {
            printf("failed\n");
            return ;
    }
    for (int i = index + 1; i < vector->length; ++i) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length = vector->length - 1;
    printf("success\n");
     return ;


 }

void print(Vector *vector) {
     for(int i = 0; i < vector->length; i++){
        if(i > 0){
            printf(" ");
        }
        printf("%d",vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
     free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int b,num,index,choice,del,find;
    scanf("%d\n", &b);
    
    for(int i = 1; i <= b ;i++){
        scanf("%d ",&choice);
        if(choice == 1){
            scanf("%d %d",&index,&num);
          insert(a, index, num);
        }
        if(choice == 2){
            scanf("%d",&del);
          delete_node(a, del);
        }
        if(choice == 3){
            scanf("%d",&find);
            search(a, find);
        }
        if(choice == 4){
            print(a);
        }
        scanf("\n");
    }

    clear(a);
    return 0;
}

