struct ListNode* swapPairs(struct ListNode* head) { //1號2號交換
    typedef struct ListNode ListNode;
    ListNode* dummyhead = (ListNode*)malloc(sizeof(ListNode));
    dummyhead->next = head;
    ListNode* cur = dummyhead;
    while (cur->next != NULL && cur->next->next != NULL) { // 前後順序不可交換,不然cur->next==NULL時判斷cur->next->next!= NULL會出錯
                                                          
        ListNode* temp1 = cur->next;              //紀錄1號節點
        ListNode* temp2 = cur->next->next->next;  //紀錄2號的下一個(3號)
        cur->next = cur->next->next;    //cur連到2號節點
        cur->next->next = temp1;        //2號節點連到1號節點
        temp1->next = temp2;            //1號節點連到3號節點

        cur = cur->next->next;    //cur往後移兩位   
    }
    return dummyhead->next;
    free(dummyhead);
}
