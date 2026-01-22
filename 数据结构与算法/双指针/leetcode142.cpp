struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast) {
            slow = slow->next;
            if(fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;

            if(fast == slow) {
                fast = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }

        return nullptr;
    }
};
