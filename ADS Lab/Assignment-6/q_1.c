#include <stdio.h>
#include <stdlib.h>

typedef struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
} DLLNode;

void insertAtBeginning(DLLNode** head, int data) {
    DLLNode* newNode = (DLLNode*)malloc(sizeof(DLLNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(DLLNode** head, int data) {
    DLLNode* newNode = (DLLNode*)malloc(sizeof(DLLNode));
    DLLNode* temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(DLLNode** head, int data) {
    DLLNode* temp = *head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void displayDLL(DLLNode* head) {
    DLLNode* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    DLLNode* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Doubly Linked List: ");
    displayDLL(head);

    deleteNode(&head, 20);

    printf("After deleting node with data 20: ");
    displayDLL(head);

    return 0;
}
