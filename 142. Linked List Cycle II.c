struct ListNode* detectCycle(struct ListNode* head) {
    typedef struct ListNode ListNode;
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {          // fast和slow在相遇代表有cycle
            ListNode* index1 = fast; // index1為fast和slow在cycle上相遇的node
            ListNode* index2 = head;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1; // index1與index2以同速度相遇的節點為cycle的起點
        }
    }
    return NULL;
}
