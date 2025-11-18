void insertAtPosition(Node **head, int value, int position) {
    if (position < 1) return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (position == 1) {
        newNode->prev = NULL;
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}
