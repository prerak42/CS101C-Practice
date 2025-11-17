#include<stdio.h>
#include<stdlib.h>

//Defining node
struct Node{
    int data;
    struct Node* next;
};

struct Node* first = NULL;
struct Node* last = NULL;

int isEmpty(){
    return first == NULL;
}

void enqueue(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;

    if(isEmpty()){
        first = last = newNode;
    } else{
        last->next = newNode;
        last = newNode;
    }
}

int dequeue(){
    struct Node* temp = first;
    int deqVal = temp->data;

    first = first->next;

    if(first == NULL){
        last = NULL;
    }

    free(temp);
    return deqVal;
}

void main(){
    int i=0, n, val;

    printf("Enter the number of elements to put into the queue: \n");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter element %d: \n", i+1);
        scanf("%d", &val);
        enqueue(val);
    }

    printf("Queue: \n");
    struct Node* current = first;
    while(current != NULL){ 
        printf("%d\n", current->data);
        current = current->next;
    }
}