#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> uset;
        ListNode *cur = headA;
        while(cur) {
            uset.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while(cur) {
            if(uset.contains(cur)) {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }
};
