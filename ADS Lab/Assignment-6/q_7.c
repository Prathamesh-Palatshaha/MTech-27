#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAfter(Node *head, int afterValue, int newValue) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    
    do {
        if (temp->data == afterValue) {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = newValue;

            newNode->next = temp->next;
            temp->next = newNode;   
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node with value %d not found in the list.\n", afterValue);
}

