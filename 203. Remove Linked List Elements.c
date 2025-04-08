struct ListNode* removeElements(struct ListNode* head, int val) {
    typedef struct ListNode ListNode;
    ListNode* vhead;
    vhead = (ListNode*)malloc(sizeof(ListNode));
    vhead->next = head;
    ListNode* cur = vhead;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            ListNode* to_delete = cur->next;    //釋放被移出linked list的節點的空間
            cur->next = cur->next->next;
            free(to_delete);
        }
        else{
            cur = cur->next;
        }
    }
    head = vhead->next;
    free(vhead);
    return head;
}
