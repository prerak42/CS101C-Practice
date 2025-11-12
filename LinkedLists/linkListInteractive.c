#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* deleteNodeByValue(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Changed head
        free(temp);       // Free old head
        return head;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Element %d not found in the list\n", key);
        return head;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory

    return head;
}

struct Node* deleteNodeByPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete node at position %d\n", position);
        return head;
    }

    struct Node* temp = head;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d does not exist in the list\n", position);
        return head;
    }

    // If head needs to be removed
    if (position == 1) {
        head = temp->next; // Change head
        free(temp);       // Free old head
        return head;
    }

    // Find previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // Node temp->next is the node to be deleted
    struct Node* next = temp->next->next;
    free(temp->next); // Free memory

    temp->next = next; // Unlink the deleted node from list

    return head;
}

void traverse(struct Node* head){
    struct Node* temp = head;
    printf("Linked List elements: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    if(temp == NULL){
        printf("NULL\n");
    }
}

void appendNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertNodeAtPosition(struct Node* head, int position, int value) {
    struct Node* temp = head;
    int currentPos = 1;
    
    // Traverse to the specified position
    while(temp != NULL && currentPos < position) {
        temp = temp->next;
        currentPos++;
    }
    
    // Check if position is valid
    if(temp == NULL) {
        printf("Invalid position. Cannot insert node.\n");
        return;
    }
    
    // Insert the new node
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void traverseAdd(struct Node* head){
    struct Node* temp = head;
    int sum = 0;
    int position = 1;
    printf("Linked List elements: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        sum += temp->data;
        temp = temp->next;
        position++;
    }
    if(temp == NULL){
        printf("NULL");
    }
    printf("\nSum of elements: %d\n", sum);
    printf("Total number of elements: %d\n", position-1);
}

void traverseSearch(struct Node* head, int key){
    struct Node* temp = head;
    int position = 1;
    int found = 0;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }
    if(!found) {
        printf("Element %d not found in the list\n", key);
    }
}

void traverseFindMaxMin(struct Node* head){
    struct Node* temp = head;
    if(temp == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    int max = temp->data;
    while(temp != NULL) {
        if(temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("Maximum element in the list: %d\n", max);
}

void traverseFindMinima(struct Node* head){
    struct Node* temp = head;
    if(temp == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    int min = temp->data;
    while(temp != NULL) {
        if(temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("Minimum element in the list: %d\n", min);
}

void freeList(struct Node* head) {
    struct Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int operationMenu() {
    int choice;
    printf("\nChoose an operation:\n");
    printf("1. Insert Node\n");
    printf("2. Delete Node by Value\n");
    printf("3. Delete Node by Position\n");
    printf("4. Traverse List\n");
    printf("5. Search for Element\n");
    printf("6. Find Extreme Valued of Elements\n");
    printf("7. Sum of the Elements\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Node* head = NULL;
    int n=0, i=0, position, value;
    
    printf("Enter number of elements to add to the linked list: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int val;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        appendNode(&head, val);
    }
    
    printf("\nLinked list:\n");
    traverse(head);

    while(1){
        int choice = operationMenu();
        switch (choice)
        {
        case 1:
            int pos;
            printf("\n");
            printf("Enter position to insert the new node: ");
            scanf("%d", &pos);
            printf("Enter value to add: ");
            scanf("%d", &value);
            insertNodeAtPosition(head, pos, value);
            printf("After insertion:\n");
            traverse(head);
            break;

        case 2:
            printf("\n");
            printf("Enter value to delete: ");
            scanf("%d", &value);
            head = deleteNodeByValue(head, value);
            printf("After deletion:\n");
            traverse(head);
            break;

        case 3:
            printf("\n");
            printf("Enter position to delete: ");
            scanf("%d", &position);
            head = deleteNodeByPosition(head, position);
            printf("After deletion:\n");
            traverse(head);
            break;
        
        case 4:
            printf("\n");
            traverse(head);
            break;

        case 5:
            printf("\n");
            printf("Enter element to search for: ");
            scanf("%d", &value);
            traverseSearch(head, value);
            break;

        case 6:
            printf("\n");
            traverseFindMaxMin(head);
            break;

        case 7:
            printf("\n");
            traverseAdd(head);
            break;
    
        case 8:
            printf("\n");
            printf("Exiting program.\n");
            return 0;
    
        default:
            break;
        }
    }

    freeList(head);
    return 0;
}