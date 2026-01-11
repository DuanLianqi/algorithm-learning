struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = head;
        int size = 0;
        while(cur) {
            size++;
            cur = cur->next;
        }
        int step = size - n;
        cur = dummyHead;
        while(step--) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummyHead->next;
    }
};
