typedef struct Node {
    int data;
    struct Node *next;
} Node;

void deleteNode(Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    if (*head == (*head)->next && (*head)->data == value) {
        free(*head);
        *head = NULL;
        return;
    }

    prev = NULL;
    temp = *head;
    while (temp != NULL) {
        if (temp->data == value) {
            if (temp == *head) {
                Node *last = *head;
                while (last->next != *head) {
                    last = last->next;
                }
                *head = temp->next;
                last->next = *head; 
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
        
        if (temp == *head) break;
    }

    printf("Node with value %d not found in the list.\n", value);
}