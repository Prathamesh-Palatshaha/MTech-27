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

void printMiddle(Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

int main() {
    Node* head = NULL;
    
    // List: 1 -> 2 -> 3 -> 4 -> 5
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printMiddle(head);

    return 0;
}
