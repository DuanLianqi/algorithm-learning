struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while(cur->next && cur->next->next) {
            ListNode *temp1 = cur->next;
            ListNode *temp2 = cur->next->next;
            cur->next = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            cur = temp1;
        }
        return dummyHead->next;
    }
};
