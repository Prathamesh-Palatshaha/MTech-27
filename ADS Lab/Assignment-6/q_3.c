void deleteFirstOccurrence(Node **head, int value) {
    Node *temp = *head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;
    
    if (temp == NULL) return;  // Value not found

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    
    if (*head == temp)
        *head = temp->next;

    free(temp);
}
