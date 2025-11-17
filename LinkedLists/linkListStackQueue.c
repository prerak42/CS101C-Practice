#include<stdio.h>
#include<stdlib.h>

//Defining node
struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;    //Global pointer to the top
struct Node* first = NULL;
struct Node* last = NULL;

//Functioon to check if the stack is empty or not
int isEmptyStack(){
    return top == NULL;
}

int isEmptyQueue(){
    return first == NULL;
}

//Function to 'push' the value to the stack
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

void enqueue(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation error.\n");
        return;
    }

    newNode->data = val;
    newNode->next = NULL;

    if(isEmptyQueue()){
        first = last = newNode;
    } else{
        last->next = newNode;
        last = newNode;
    }
}

int dequeue(){
    if(isEmptyQueue()){
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* temp = first;
    int deqVal = temp->data;

    first = first->next;

    if(first == NULL){
        last = NULL;
    }

    free(temp);

    return deqVal;
}

//Function to 'pop' the top element
int pop(){
    if(isEmptyStack()){
        printf("Stack is empty.\n");
        return -1;
    }

    struct Node* temp = top;
    int valPop = temp->data;

    top = top->next;

    free(temp);
    return valPop;
}

//Function to display the stack
void displayStack(){
    if(isEmptyStack()){
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

void displayQueue(){
    if(isEmptyQueue()){
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: \n");
    struct Node* current = first;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void main(){
    int n = 0, val, i;
    printf("Enter 0 for stack and 1 for queue.\n");
    scanf("%d", &i);
    switch(i){
        case 0:
            printf("Enter number of elements to push into the stack: \n");
            scanf("%d", &n);
            for(int j = 0; j<n; j++){
                printf("Enter element %d: \n", j+1);
                scanf("%d", &val);
                push(val);
            }
            displayStack();
            break;
        
            case 1:
            printf("Enter the number of elements to insert in the queue: \n");
            scanf("%d", &n);
            for(int j = 0; j<n; j++){
                printf("Enter element %d: \n", j+1);
                scanf("%d", &val);
                enqueue(val);
            }
            displayQueue();
            break;
    }
}
