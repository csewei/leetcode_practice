//雙指針法
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* temp;
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while (cur != NULL) {
        temp = cur->next;   //先保存下一個節點的位置
        cur->next = pre;    //指向前一個節點
        pre = cur;
        cur = temp;
    }
    return pre;
}
