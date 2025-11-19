#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue {
    struct Node *items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};


bool isEmpty(struct Queue *q) {
    return q->front == -1;
}


bool isFull(struct Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(struct Queue *q, struct Node *node) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more nodes.\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = node;
}

struct Node *dequeue(struct Queue *q) {
    struct Node *item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return NULL;
    }

    item = q->items[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return item;
}

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *buildTreeLevelOrder() {
    int rootValue;
    printf("\nEnter the value for the Root node (or -1 to stop): ");
    if (scanf("%d", &rootValue) != 1 || rootValue == -1) {
        return NULL;
    }

    struct Node *root = createNode(rootValue);
    
    struct Queue q = {.front = -1, .rear = -1};
    enqueue(&q, root);

    struct Node *current = NULL;
    int childValue;

    while (!isEmpty(&q)) {
        current = dequeue(&q);

        // Get Left Child
        printf("Enter the Left child of %d (or -1 for NULL): ", current->data);
        if (scanf("%d", &childValue) == 1 && childValue != -1) {
            current->left = createNode(childValue);
            enqueue(&q, current->left);
        }

        // Get Right Child
        printf("Enter the Right child of %d (or -1 for NULL): ", current->data);
        if (scanf("%d", &childValue) == 1 && childValue != -1) {
            current->right = createNode(childValue);
            enqueue(&q, current->right);
        }
    }
    printf("\nTree construction complete.\n");
    return root;
}

void preorder(struct Node *node) {
    if (node != NULL) {
        printf("%d ", node->data); // Visit root
        preorder(node->left);      // Recurse left
        preorder(node->right);     // Recurse right
    }
}

void inorder(struct Node *node) {
    if (node != NULL) {
        inorder(node->left);       // Recurse left
        printf("%d ", node->data); // Visit root
        inorder(node->right);      // Recurse right
    }
}

void postorder(struct Node *node) {
    if (node != NULL) {
        postorder(node->left);     // Recurse left
        postorder(node->right);    // Recurse right
        printf("%d ", node->data); // Visit root
    }
}

void freeTree(struct Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    struct Node *root = NULL;

    printf("Welcome to Binary Tree Constructor!\n");
    printf("Instructions: Enter integer values for nodes.\n");
    printf("Use -1 when prompted for a child that should be NULL (no node).\n");

    root = buildTreeLevelOrder();

    if (root == NULL) {
        printf("No tree was constructed.\n");
        return 0;
    }

    printf("\n--- Binary Tree Traversal Results ---\n");

    printf("1. Preorder Traversal (Root, Left, Right):\n");
    preorder(root);
    printf("\n\n");

    printf("2. Inorder Traversal (Left, Root, Right):\n");
    inorder(root);
    printf("\n\n");

    printf("3. Postorder Traversal (Left, Right, Root):\n");
    postorder(root);
    printf("\n\n");

    freeTree(root);
    printf("Memory cleanup complete.\n");

    return 0;
}