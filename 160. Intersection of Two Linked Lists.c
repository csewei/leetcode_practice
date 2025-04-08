/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {
    typedef struct ListNode ListNode;
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lenA = 0, lenB = 0;
    while (curA != NULL) {  //用來求lenA
        curA = curA->next;
        lenA++;
    }
    while (curB != NULL) {  //用來求lenB
        curB = curB->next;
        lenB++;
    }
    curA = headA;   //指向第一個節點
    curB = headB;

    if (lenA > lenB) {      //讓兩個linked list尾部對齊
        while (lenA != lenB) {
            lenA--;
            curA = curA->next;
        }
    }
    else{
        while (lenB != lenA) {
            lenB--;
            curB = curB->next;
        }
    }
    while (curA != curB) {
        if (curA == NULL) {
            return NULL;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}
