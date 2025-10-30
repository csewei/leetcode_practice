struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode ListNode;
    ListNode* dummy = malloc(sizeof(ListNode));
    dummy->val = 0;
    dummy->next = head;
    ListNode* fast = head;
    ListNode* slow = dummy;

    for (int i = 0; i < n ; i++) {
        fast = fast->next;
    }
    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* temp;
    temp = slow->next;
    slow->next = temp->next;
    free(temp);
    return dummy->next;
}
