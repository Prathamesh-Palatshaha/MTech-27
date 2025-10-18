#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* reverseIterative(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* reverseRecursive(Node* head) {
    if (!head || !head->next)
        return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    Node* head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original list:\n");
    printList(head);

    head = reverseIterative(head);
    printf("Reversed list (Iterative):\n");
    printList(head);

    head = reverseRecursive(head);
    printf("Reversed back (Recursive):\n");
    printList(head);

    return 0;
}
