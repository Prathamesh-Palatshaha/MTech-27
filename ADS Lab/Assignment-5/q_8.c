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

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* deleteFromBeginning(Node* head) {
    if (!head) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteFromPosition(Node* head, int pos) {
    if (!head || pos < 1) return head;

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp || !temp->next) {
        printf("Position out of bounds.\n");
        return head;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

int main() {
    Node* head = NULL;

    // Creating list: 10 -> 20 -> 30 -> 40
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original list:\n");
    printList(head);

    head = deleteFromBeginning(head);
    printf("After deleting from beginning:\n");
    printList(head);

    head = deleteFromEnd(head);
    printf("After deleting from end:\n");
    printList(head);

    head = deleteFromPosition(head, 2);
    printf("After deleting from position 2:\n");
    printList(head);

    return 0;
}
