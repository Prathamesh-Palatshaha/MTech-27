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

int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(10);
    head->next->next = createNode(15);

    printf("Number of nodes: %d\n", countNodes(head));
    return 0;
}
