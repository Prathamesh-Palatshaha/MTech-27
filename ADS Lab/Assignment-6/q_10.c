void splitCircularList(Node *head, Node **firstHalf, Node **secondHalf) {
    if (head == NULL) {
        *firstHalf = *secondHalf = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;       
        fast = fast->next->next;  
    }

    *firstHalf = head;
    *secondHalf = slow->next;
    
    slow->next = head;
    
    Node *temp = *secondHalf;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = *secondHalf;
}