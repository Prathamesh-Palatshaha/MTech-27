#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* removeDuplicates(Node* head) {
    Node* current = head;

    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
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

    // Creating sorted list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original list:\n");
    printList(head);

    head = removeDuplicates(head);
    printf("After removing duplicates:\n");
    printList(head);

    return 0;
}
