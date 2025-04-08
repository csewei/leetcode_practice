bool hasCycle(struct ListNode* head) {
    typedef struct ListNode ListNode;
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {    //運用快慢指針，若能相遇則有cycle
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}
