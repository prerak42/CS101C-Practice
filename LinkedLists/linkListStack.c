#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty(){
    return top == NULL;
}

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation error.\n");
        return;
    }

    newNode->data = val;
    newNode->next = top;

    top = newNode;
}

int pop(){
    if(isEmpty()){
        printf("Stack is empty.\n");
        return -1;
    }

    struct Node* temp = top;
    int valPop = temp->data;

    top = top->next;

    free(temp);
    return valPop;
}

void display(){
    if(isEmpty()){
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: \n");
    struct Node* current = top;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void main(){
    int n = 0, val;
    printf("Enter number of elements to push into the stack: \n");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("Enter element %d: \n", i+1);
        scanf("%d", &val);
        push(val);
    }
    display();
}