#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return head;
    }

    Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp) {
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 15, 2); // Insert at position 2

    printf("Linked List:\n");
    printList(head);

    return 0;
}
