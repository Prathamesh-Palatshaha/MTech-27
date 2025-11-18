int length(Node *head) {
    int len = 0;
    Node *temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

Node* middleNode(Node *head) {
    int len = length(head);
    Node *temp = head;
    for (int i = 0; i < len / 2; i++) {
        temp = temp->next;
    }
    return temp;
}
