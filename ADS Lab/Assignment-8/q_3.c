#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* swapNodes(Node* prevA, Node* A) {
    Node* B = A->next; 
    if (B == NULL) return A; 
    prevA->next = B;
    A->next = B->next;
    B->next = A;
    return B;
}

Node* selectionSortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node dummy;
    dummy.next = head;

    Node *sortedEnd = &dummy;

    while (sortedEnd->next != NULL) {
        Node *min_prev = sortedEnd;
        Node *min_curr = sortedEnd->next;

        Node *curr_prev = sortedEnd->next;
        Node *curr = curr_prev->next; 
        while (curr != NULL) {
            if (curr->data < min_curr->data) {
                min_prev = curr_prev; 
                min_curr = curr; 
            }
            curr_prev = curr;
            curr = curr->next;
        }

        if (min_curr != sortedEnd->next) {

            min_prev->next = min_curr->next;
            min_curr->next = sortedEnd->next;
            sortedEnd->next = min_curr;
        }

        sortedEnd = sortedEnd->next;

        printf("Progress: ");
        printList(dummy.next);
    }

    return dummy.next;
}

// --- Main Program ---
int main() {
    // Create the linked list: 64 -> 25 -> 12 -> 22 -> 11 -> NULL
    Node *head = createNode(64);
    head->next = createNode(25);
    head->next->next = createNode(12);
    head->next->next->next = createNode(22);
    head->next->next->next->next = createNode(11);

    printf("--- Linked List Selection Sort (Node Swaps) ---\n");
    printf("Original List: ");
    printList(head);
    printf("-----------------------------------------------\n");
    
    head = selectionSortList(head);

    printf("-----------------------------------------------\n");
    printf("Final Sorted List: ");
    printList(head);

    // Free allocated memory
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}