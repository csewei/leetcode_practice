struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode ListNode;
    ListNode* dummyhead = (ListNode*)malloc(sizeof(ListNode));
    dummyhead->val = 0;
    dummyhead->next = head;

    ListNode* fast = dummyhead;
    ListNode* slow = dummyhead;

    n++; // 讓fast先走n+1步
    while (n && fast != NULL) {
        n--;
        fast = fast->next;
    }
    while (fast != NULL) { // fast走完n+1步後，fast和slow一起走
        fast = fast->next;
        slow = slow->next;
    } // 走完後slow指在要刪的節點的前一個節點
    
    ListNode *tmp = slow->next;  
    slow->next = tmp->next;
    free(tmp);      //釋放被刪掉節點占用的空間
    
    head = dummyhead->next;
    free(dummyhead);
    return head;
}
