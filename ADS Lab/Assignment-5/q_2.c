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

void searchElement(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}

int main() {
    Node* head = NULL;
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Searching for 20...\n");
    searchElement(head, 20);

    printf("Searching for 50...\n");
    searchElement(head, 50);

    return 0;
}
