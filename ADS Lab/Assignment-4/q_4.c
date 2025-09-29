#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;  // Pointer to itself
} Node;

int main() {
    Node n1, n2;

    n1.data = 10;
    n2.data = 20;

    n1.next = &n2;  // n1 points to n2
    n2.next = NULL;

    printf("First node data: %d\n", n1.data);
    printf("Second node data via next pointer: %d\n", n1.next->data);

    return 0;
}
